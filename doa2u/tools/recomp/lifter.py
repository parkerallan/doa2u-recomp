"""
x86 → C instruction lifter.

Translates individual x86 instructions (and common multi-instruction
patterns like cmp+jcc) into C statements using the recomp_types.h macros.

Register model:
  - eax, ebx, ecx, edx, esi, edi, ebp: uint32_t locals
  - esp: uint32_t local (stack pointer)
  - FPU: double fp_stack[8] with fp_top index

Memory model:
  - MEM8/MEM16/MEM32 macros for memory access at flat addresses
  - Xbox data sections mapped at original VAs
"""

import re
import struct

from .disasm import Instruction, Operand
from .config import is_code_address, is_data_address, va_to_file_offset, KERNEL_THUNK_ADDR
from . import config as _cfg


# ── Operand formatting ──────────────────────────────────────

def _fmt_reg(name, size=4):
    """Format a register name as a C expression."""
    if not name:
        return "0"

    # Segment registers → constants
    if name in ("fs", "gs", "cs", "ds", "es", "ss"):
        return f"0 /* seg:{name} */"

    # Map sub-registers to expressions on 32-bit locals
    SUB_REGS = {
        "al": "LO8(eax)", "ah": "HI8(eax)", "ax": "LO16(eax)",
        "bl": "LO8(ebx)", "bh": "HI8(ebx)", "bx": "LO16(ebx)",
        "cl": "LO8(ecx)", "ch": "HI8(ecx)", "cx": "LO16(ecx)",
        "dl": "LO8(edx)", "dh": "HI8(edx)", "dx": "LO16(edx)",
        "si": "LO16(esi)", "di": "LO16(edi)",
        "bp": "LO16(ebp)", "sp": "LO16(esp)",
    }
    if name in SUB_REGS:
        return SUB_REGS[name]
    return name


def _fmt_set_reg(name, value_expr):
    """Format assignment to a register, handling sub-register writes."""
    # Segment registers → no-op
    if name in ("fs", "gs", "cs", "ds", "es", "ss"):
        return f"/* mov {name}, {value_expr} - segment register */;"

    SET_MAP = {
        "al": f"SET_LO8(eax, {value_expr})",
        "ah": f"SET_HI8(eax, {value_expr})",
        "ax": f"SET_LO16(eax, {value_expr})",
        "bl": f"SET_LO8(ebx, {value_expr})",
        "bh": f"SET_HI8(ebx, {value_expr})",
        "bx": f"SET_LO16(ebx, {value_expr})",
        "cl": f"SET_LO8(ecx, {value_expr})",
        "ch": f"SET_HI8(ecx, {value_expr})",
        "cx": f"SET_LO16(ecx, {value_expr})",
        "dl": f"SET_LO8(edx, {value_expr})",
        "dh": f"SET_HI8(edx, {value_expr})",
        "dx": f"SET_LO16(edx, {value_expr})",
        "si": f"SET_LO16(esi, {value_expr})",
        "di": f"SET_LO16(edi, {value_expr})",
        "bp": f"SET_LO16(ebp, {value_expr})",
        "sp": f"SET_LO16(esp, {value_expr})",
    }
    if name in SET_MAP:
        return SET_MAP[name] + ";"
    return f"{name} = {value_expr};"


def _fmt_imm(val):
    """Format an immediate value as a C hex literal."""
    if val == 0:
        return "0"
    if val <= 9:
        return str(val)
    if val > 0x7FFFFFFF:
        return f"0x{val:08X}u"
    return f"0x{val:X}"


def _mem_accessor(size):
    """Return the MEM macro name for a given operand size."""
    return {1: "MEM8", 2: "MEM16", 4: "MEM32"}.get(size, "MEM32")


_ARITH_RE = re.compile(r"^f(i?)(add|sub|mul|div)(r?)(p?)$")


def _smem_accessor(size):
    """Return the signed MEM macro for a given operand size."""
    return {1: "SMEM8", 2: "SMEM16", 4: "SMEM32"}.get(size, "SMEM32")


def _fmt_mem(op):
    """Format a memory operand as a C expression (the address computation).
    fs:-relative operands address the fake KPCR/TIB at XBOX_FS_BASE
    (recomp_types.h); dropping the segment used to put the KPCR at guest VA 0,
    which is physical page 0 -- the page the USB host-controller driver (XPP)
    uses for its own memory through the 0x80000000 cached window."""
    if getattr(op, "mem_seg", None) == "fs":
        inner = _fmt_mem_flat(op)
        return f"(XBOX_FS_BASE + {inner})"
    return _fmt_mem_flat(op)


def _fmt_mem_flat(op):
    parts = []
    if op.mem_base:
        parts.append(_fmt_reg(op.mem_base))
    if op.mem_index:
        idx = _fmt_reg(op.mem_index)
        if op.mem_scale and op.mem_scale > 1:
            parts.append(f"{idx} * {op.mem_scale}")
        else:
            parts.append(idx)
    if op.mem_disp:
        if op.mem_disp < 0:
            # Negative displacement - but we stored unsigned, check sign
            if op.mem_disp > 0x80000000:
                # Actually negative (two's complement)
                signed_disp = op.mem_disp - 0x100000000
                if parts:
                    parts.append(f"- {_fmt_imm(-signed_disp)}")
                else:
                    parts.append(_fmt_imm(op.mem_disp))
            else:
                parts.append(_fmt_imm(op.mem_disp))
        else:
            parts.append(_fmt_imm(op.mem_disp))
    if not parts:
        return "0"
    return " + ".join(parts)


def _fmt_mem_read(op):
    """Format reading from a memory operand."""
    accessor = _mem_accessor(op.mem_size)
    addr = _fmt_mem(op)
    return f"{accessor}({addr})"


def _fmt_mem_write(op, value_expr):
    """Format writing to a memory operand."""
    accessor = _mem_accessor(op.mem_size)
    addr = _fmt_mem(op)
    return f"{accessor}({addr}) = {value_expr};"


def _fmt_operand_read(op):
    """Format reading any operand type."""
    if op.type == "reg":
        return _fmt_reg(op.reg)
    elif op.type == "imm":
        return _fmt_imm(op.imm)
    elif op.type == "mem":
        return _fmt_mem_read(op)
    return "/* unknown operand */"


def _fmt_operand_write(op, value_expr):
    """Format writing to any operand type. Returns a C statement."""
    if op.type == "reg":
        return _fmt_set_reg(op.reg, value_expr)
    elif op.type == "mem":
        return _fmt_mem_write(op, value_expr)
    return f"/* cannot write to {op.type} */;"



# ── MMX lifting: MM registers are per-function uint64_t locals; helpers
# (mmx_*, MMQ_LOAD/MMQ_STORE) live in recomp_types.h.

_MMX_BINOPS = {
    "paddw": "mmx_paddw", "psubw": "mmx_psubw",
    "pavgb": "mmx_pavgb",
    "pmullw": "mmx_pmullw", "pmulhw": "mmx_pmulhw",
    "punpcklwd": "mmx_punpcklwd", "punpckhwd": "mmx_punpckhwd",
    "punpcklbw": "mmx_punpcklbw", "punpckhbw": "mmx_punpckhbw",
    "packssdw": "mmx_packssdw", "packuswb": "mmx_packuswb",
    "packsswb": "mmx_packsswb",
    "paddd": "mmx_paddd", "psubd": "mmx_psubd",
    "paddusw": "mmx_paddusw", "paddusb": "mmx_paddusb",
    "pminsw": "mmx_pminsw", "pmaxsw": "mmx_pmaxsw",
    "pmaddwd": "mmx_pmaddwd", "pavgw": "mmx_pavgw",
    "punpckldq": "mmx_punpckldq", "punpckhdq": "mmx_punpckhdq",
    "pcmpeqd": "mmx_pcmpeqd", "pcmpeqw": "mmx_pcmpeqw",
}
_MMX_SHIFTS = {"psraw": "mmx_psraw", "psrad": "mmx_psrad", "psllw": "mmx_psllw",
               "psrlw": "mmx_psrlw", "psrld": "mmx_psrld", "psrlq": "mmx_psrlq",
               "pslld": "mmx_pslld", "psllq": "mmx_psllq"}
_MMX_MNEMONICS = (set(_MMX_BINOPS) | set(_MMX_SHIFTS) |
                  {"movq", "movntq", "pextrw", "pinsrw", "pshufw", "pmovmskb",
                   "movd", "emms", "pand", "pandn", "por", "pxor"})


def _is_mm_reg(op):
    return (op.type == "reg" and op.reg.startswith("mm")
            and not op.reg.startswith("xmm"))


def _is_mmx_insn(m, ops):
    if m not in _MMX_MNEMONICS:
        return False
    if m == "emms":
        return True
    return any(_is_mm_reg(op) for op in ops)


def _mmx_read(op):
    """Read a 64-bit MMX operand (mm reg or qword memory)."""
    if _is_mm_reg(op):
        return op.reg
    if op.type == "mem":
        return f"MMQ_LOAD({_fmt_mem(op)})"
    if op.type == "reg":       # 32-bit GPR (movd)
        return f"(uint64_t){_fmt_reg(op.reg)}"
    if op.type == "imm":
        return _fmt_imm(op.imm)
    return "0 /* mmx: bad operand */"


def _mmx_write(op, expr):
    if _is_mm_reg(op):
        return f"{op.reg} = {expr};"
    if op.type == "mem":
        return f"MMQ_STORE({_fmt_mem(op)}, {expr});"
    if op.type == "reg":       # 32-bit GPR (movd r32, mm)
        return _fmt_set_reg(op.reg, f"(uint32_t)({expr})")
    return f"/* mmx: cannot write operand */;"


def _lift_mmx(insn, m, ops):
    nops = len(ops)
    if m == "emms":
        return ["/* emms */"]
    if m in ("movq", "movntq"):
        if nops >= 2:
            return [_mmx_write(ops[0], _mmx_read(ops[1])) + f" /* {m} */"]
    if m == "movd":
        if nops >= 2:
            if _is_mm_reg(ops[0]):
                # movd mm, r/m32: zero-extend into low 32
                src = _fmt_operand_read(ops[1])
                return [f"{ops[0].reg} = (uint64_t)(uint32_t)({src}); /* movd */"]
            else:
                # movd r/m32, mm: low 32 bits
                return [_fmt_operand_write(ops[0],
                        f"(uint32_t){_mmx_read(ops[1])}") + " /* movd */"]
    if m in _MMX_BINOPS and nops >= 2:
        fn = _MMX_BINOPS[m]
        return [_mmx_write(ops[0],
                f"{fn}({_mmx_read(ops[0])}, {_mmx_read(ops[1])})") + f" /* {m} */"]
    if m in _MMX_SHIFTS and nops >= 2:
        fn = _MMX_SHIFTS[m]
        if ops[1].type == "imm":
            cnt = _fmt_imm(ops[1].imm)
        else:
            cnt = f"(uint32_t){_mmx_read(ops[1])}"
        return [_mmx_write(ops[0],
                f"{fn}({_mmx_read(ops[0])}, {cnt})") + f" /* {m} */"]
    if m == "pextrw" and nops >= 3:
        lane = f"({_fmt_imm(ops[2].imm)} & 3)" if ops[2].type == "imm" else "0"
        return [_fmt_operand_write(ops[0],
                f"(uint32_t)(({_mmx_read(ops[1])} >> ({lane} * 16)) & 0xFFFF)")
                + " /* pextrw */"]
    if m == "pinsrw" and nops >= 3:
        lane = f"({_fmt_imm(ops[2].imm)} & 3)" if ops[2].type == "imm" else "0"
        src = _fmt_operand_read(ops[1])
        return [_mmx_write(ops[0],
                f"mmx_pinsrw({_mmx_read(ops[0])}, (uint32_t)({src}), {lane})") + " /* pinsrw */"]
    if m == "pshufw" and nops >= 3:
        return [_mmx_write(ops[0],
                f"mmx_pshufw({_mmx_read(ops[1])}, {_fmt_imm(ops[2].imm)})") + " /* pshufw */"]
    if m == "pmovmskb" and nops >= 2:
        return [_fmt_operand_write(ops[0], f"mmx_pmovmskb({_mmx_read(ops[1])})") + " /* pmovmskb */"]
    if m in ("pand", "pandn", "por", "pxor") and nops >= 2:
        a = _mmx_read(ops[0]); b = _mmx_read(ops[1])
        expr = {"pand": f"{a} & {b}", "pandn": f"~{a} & {b}",
                "por": f"{a} | {b}", "pxor": f"{a} ^ {b}"}[m]
        return [_mmx_write(ops[0], f"({expr})") + f" /* {m} */"]
    return [f"/* MMX-unlifted: {m} {insn.op_str} */"]


# ── Condition code mapping ───────────────────────────────────

# Maps jcc mnemonic → (cmp_macro, test_macro, description)
# cmp_macro takes (lhs, rhs), test_macro takes (lhs, rhs)
COND_MAP = {
    "je":   ("CMP_EQ",  "TEST_Z",  "equal / zero"),
    "jz":   ("CMP_EQ",  "TEST_Z",  "zero"),
    "jne":  ("CMP_NE",  "TEST_NZ", "not equal / not zero"),
    "jnz":  ("CMP_NE",  "TEST_NZ", "not zero"),
    "jb":   ("CMP_B",   None,      "below (unsigned <)"),
    "jnae": ("CMP_B",   None,      "below"),
    "jae":  ("CMP_AE",  None,      "above or equal (unsigned >=)"),
    "jnb":  ("CMP_AE",  None,      "above or equal"),
    "jbe":  ("CMP_BE",  None,      "below or equal (unsigned <=)"),
    "jna":  ("CMP_BE",  None,      "below or equal"),
    "ja":   ("CMP_A",   None,      "above (unsigned >)"),
    "jl":   ("CMP_L",   "TEST_S",  "less (signed <)"),
    "jge":  ("CMP_GE",  None,      "greater or equal (signed >=)"),
    "jle":  ("CMP_LE",  None,      "less or equal (signed <=)"),
    "jg":   ("CMP_G",   None,      "greater (signed >)"),
    "js":   (None,       "TEST_S",  "sign (negative)"),
    "jns":  (None,       None,      "not sign (positive)"),
    "jo":   (None,       None,      "overflow"),
    "jno":  (None,       None,      "not overflow"),
    "jp":   (None,       None,      "parity"),
    "jnp":  (None,       None,      "not parity"),
    "jecxz": (None,      None,      "ecx is zero"),
    "jcxz":  (None,      None,      "cx is zero"),
}

# Instructions that set arithmetic flags (primary set, fully handled)
FLAG_SETTERS = frozenset({
    "cmp", "test", "sub", "add", "and", "or", "xor",
    "inc", "dec", "neg", "shl", "shr", "sar", "imul", "adc", "sbb",
    "comiss", "comisd", "ucomiss", "ucomisd",  # SSE float compare
})

# Additional instructions that modify EFLAGS (tracked but handled as generic)
_EFLAGS_SETTERS = frozenset({
    "shld", "shrd", "rol", "ror", "rcl", "rcr",  # Shifts/rotates set CF
    "bsf", "bsr",       # Bit scan sets ZF
    "bt", "bts", "btr", "btc",  # Bit test sets CF
    "cmpxchg",           # Compare-and-exchange sets ZF
    "xadd",              # Exchange-and-add sets flags
})

# Instructions with undefined/unpredictable flags (clear tracking)
_FLAGS_UNDEFINED = frozenset({
    "mul", "div", "idiv",  # Flags partially undefined
    "rdtsc", "cpuid",      # Special instructions
    "lock xadd",           # Lock prefix - complex flag behavior
})

# Instructions that do NOT modify EFLAGS (preserve flag tracking)
_EFLAGS_PRESERVE = frozenset({
    # General-purpose data movement / stack
    "mov", "lea", "push", "pop", "nop", "leave", "ret",
    "movzx", "movsx", "xchg", "bswap",
    "cdq", "cwde", "cbw", "cwd",
    "lahf",
    "not",  # NOT does not modify flags
    "call",
    "int3", "int", "wait",
    "cld", "std", "cli", "sti",
    "pushfd", "popfd", "pushal",
    "sgdt", "ljmp", "sfence",
    # SSE scalar float
    "movss", "movsd",
    "addss", "subss", "mulss", "divss",
    "minss", "maxss", "sqrtss", "rsqrtss", "rcpss",
    "addsd", "subsd", "mulsd", "divsd",
    "minsd", "maxsd", "sqrtsd",
    "cvtsi2ss", "cvtss2si", "cvttss2si",
    "cvtsi2sd", "cvtsd2si", "cvttsd2si",
    "cvtss2sd", "cvtsd2ss",
    "cmpss", "cmpsd",
    "cmpltss", "cmpeqss", "cmpleps", "cmpneqss",
    # SSE packed float
    "movaps", "movups", "movlps", "movhps", "movlhps", "movhlps",
    "addps", "subps", "mulps", "divps",
    "minps", "maxps", "sqrtps", "rsqrtps", "rcpps",
    "shufps", "unpcklps", "unpckhps",
    "andps", "orps", "xorps", "andnps",
    "cmpps", "cmpneqps",
    "movmskps",
    # SSE2 packed double
    "movapd", "movupd",
    "addpd", "subpd", "mulpd", "divpd",
    # SSE/MMX integer
    "movd", "movq", "movntq",
    "emms",
    "paddb", "paddw", "paddd", "paddq",
    "psubb", "psubw", "psubd",
    "pmullw", "pmulhw", "pmulhuw", "pmaddwd",
    "pand", "pandn", "por", "pxor",
    "pcmpeqb", "pcmpeqw", "pcmpeqd",
    "pcmpgtb", "pcmpgtw", "pcmpgtd",
    "psllw", "pslld", "psllq",
    "psrlw", "psrld", "psrlq",
    "psraw", "psrad",
    "pshufw", "pshufd", "pshufhw", "pshuflw",
    "punpcklbw", "punpcklwd", "punpckldq", "punpcklqdq",
    "punpckhbw", "punpckhwd", "punpckhdq", "punpckhqdq",
    "packsswb", "packssdw", "packuswb",
    "pmovmskb",
    # String operations (without rep prefix)
    "stosb", "stosw", "stosd",
    "movsb", "movsw", "movsd",
    "lodsb", "lodsw", "lodsd",
    # Prefetch hints
    "prefetchnta", "prefetcht0", "prefetcht1", "prefetcht2",
})



def _sign_cast(expr):
    """C cast that reproduces the x86 sign flag for the operand width of a lifted
    expression (DOA3 2026-09-20: `test al,al / jns` was emitted as a 32-bit
    comparison, so bit 7 of an 8-bit result was never seen as the sign)."""
    e = expr.lstrip("(")
    if e.startswith("LO8(") or e.startswith("HI8(") or e.startswith("MEM8("):
        return "int8_t"
    if e.startswith("LO16(") or e.startswith("MEM16("):
        return "int16_t"
    return "int32_t"

def _make_condition(jcc, flag_setter, flag_ops):
    """
    Generate a C condition expression for a jcc based on what set the flags.
    Returns (cond_expr, description) or None.
    """
    cond_info = COND_MAP.get(jcc)
    if not cond_info:
        return None
    cmp_macro, test_macro, desc = cond_info

    if len(flag_ops) >= 2:
        lhs = _fmt_operand_read(flag_ops[0])
        rhs = _fmt_operand_read(flag_ops[1])
    elif len(flag_ops) == 1:
        lhs = _fmt_operand_read(flag_ops[0])
        rhs = None
    else:
        lhs = None
        rhs = None

    # ── FPU compare-to-EFLAGS and sahf: no standard operands ──
    if flag_setter in ("fcompi", "fcomip", "fucomi", "fucompi",
                        "fucomip", "fcomi", "sahf", "comiss", "ucomiss"):
        fpu_cmp_map = {
            "ja": ">", "jnbe": ">",
            "jae": ">=", "jnb": ">=", "jnc": ">=",
            "jb": "<", "jnae": "<", "jc": "<",
            "jbe": "<=", "jna": "<=",
            "je": "==", "jz": "==",
            "jne": "!=", "jnz": "!=",
        }
        op = fpu_cmp_map.get(jcc)
        if op:
            return f"(_fpu_cmp {op} 0) /* {flag_setter} */", desc
        if jcc == "jp":
            return "0 /* fpu: unordered/NaN */", desc
        if jcc == "jnp":
            return "1 /* fpu: ordered */", desc
        return None

    # If no operands available for other flag-setters, can't generate condition
    if lhs is None:
        return None

    # ── comiss/ucomiss: float comparison, sets CF/ZF/PF ──
    if flag_setter in ("comiss", "comisd", "ucomiss", "ucomisd"):
        def _sse_op(op):
            if op.type == "reg":
                return op.reg
            elif op.type == "mem":
                if op.mem_size == 8:
                    return f"MEMD({_fmt_mem(op)})"
                return f"MEMF({_fmt_mem(op)})"
            return _fmt_operand_read(op)
        a = _sse_op(flag_ops[0]) if len(flag_ops) >= 1 else "0.0f"
        b = _sse_op(flag_ops[1]) if len(flag_ops) >= 2 else "0.0f"
        # comiss uses unsigned condition codes (CF, ZF)
        if jcc in ("ja", "jnbe"):
            return f"({a} > {b})", desc
        if jcc in ("jae", "jnb", "jnc"):
            return f"({a} >= {b})", desc
        if jcc in ("jb", "jnae", "jc"):
            return f"({a} < {b})", desc
        if jcc in ("jbe", "jna"):
            return f"({a} <= {b})", desc
        if jcc in ("je", "jz"):
            return f"({a} == {b})", desc
        if jcc in ("jne", "jnz"):
            return f"({a} != {b})", desc
        if jcc == "jp":
            return f"0 /* {jcc}: unordered/NaN */", desc
        if jcc == "jnp":
            return f"1 /* {jcc}: ordered */", desc
        return None

    # ── cmp: flags from (a - b), operands unchanged ──
    if flag_setter == "cmp":
        if cmp_macro:
            return f"{cmp_macro}({lhs}, {rhs})", desc
        if jcc == "js":
            return f"(({_sign_cast(lhs)})({lhs} - {rhs}) < 0)", desc
        if jcc == "jns":
            return f"(({_sign_cast(lhs)})({lhs} - {rhs}) >= 0)", desc
        if jcc in ("jp", "jnp"):
            return f"1 /* {jcc} after cmp - parity */", desc
        return None

    # ── test: flags from (a & b), operands unchanged ──
    if flag_setter == "test":
        if test_macro:
            return f"{test_macro}({lhs}, {rhs})", desc
        if cmp_macro:
            return f"{cmp_macro}({lhs} & {rhs}, 0)", desc
        if jcc == "js":
            return f"(({_sign_cast(lhs)})({lhs} & {rhs}) < 0)", desc
        if jcc == "jns":
            return f"(({_sign_cast(lhs)})({lhs} & {rhs}) >= 0)", desc
        if jcc == "jo":
            return "0", desc  # OF=0 after test
        if jcc == "jno":
            return "1", desc
        if jcc in ("jp", "jnp"):
            # Real parity (bug #9: was hardcoded 1). x86 PF is set when the
            # low byte of the result has an EVEN number of set bits. Used by
            # the CRT/D3DX float-compare pattern `fnstsw ax; test ah,X; jp`.
            pf = f"X86_PF8(({lhs}) & ({rhs}))"
            return (f"({pf})" if jcc == "jp" else f"(!{pf})"), desc
        return None

    # ── sub: a = a - b, flags from (a_orig - b) ──
    if flag_setter == "sub":
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        # Ordered: reconstruct original a = result + b
        if cmp_macro and rhs:
            return f"{cmp_macro}((uint32_t){lhs} + (uint32_t){rhs}, (uint32_t){rhs})", desc
        if jcc in ("jb", "jnae"):
            return f"((uint32_t){lhs} + (uint32_t){rhs} < (uint32_t){rhs})", desc
        if jcc in ("jae", "jnb"):
            return f"((uint32_t){lhs} + (uint32_t){rhs} >= (uint32_t){rhs})", desc
        if jcc in ("jl", "jnge"):
            return f"((int32_t){lhs} < 0)", desc
        if jcc in ("jge", "jnl"):
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jle", "jng"):
            return f"((int32_t){lhs} <= 0)", desc
        if jcc in ("jg", "jnle"):
            return f"((int32_t){lhs} > 0)", desc
        return None

    # ── add: a = a + b, flags from result ──
    if flag_setter == "add":
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jb", "jnae", "jc"):
            return f"({lhs} < (uint32_t){rhs})", desc
        if jcc in ("jae", "jnb", "jnc"):
            return f"({lhs} >= (uint32_t){rhs})", desc
        if jcc in ("jl", "jnge"):
            return f"((int32_t){lhs} < 0)", desc
        if jcc in ("jge", "jnl"):
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jle", "jng"):
            return f"((int32_t){lhs} <= 0)", desc
        if jcc in ("jg", "jnle"):
            return f"((int32_t){lhs} > 0)", desc
        return None

    # ── adc/sbb: result-based (like add/sub but with carry) ──
    if flag_setter in ("adc", "sbb"):
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        return None

    # ── and/or/xor: result-based, CF=0, OF=0 ──
    if flag_setter in ("and", "or", "xor"):
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc in ("js", "jl"):
            return f"((int32_t){lhs} < 0)", desc
        if jcc in ("jns", "jge"):
            return f"((int32_t){lhs} >= 0)", desc
        if jcc == "jle":
            return f"((int32_t){lhs} <= 0)", desc
        if jcc == "jg":
            return f"((int32_t){lhs} > 0)", desc
        if jcc in ("jb", "jnae", "jbe", "jna"):
            return "0", desc  # CF=0 after and/or/xor
        if jcc in ("jae", "jnb", "ja", "jnbe"):
            return "1", desc
        return None

    # ── dec/inc: result-based, CF unchanged ──
    if flag_setter in ("dec", "inc"):
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jl", "jle", "jg", "jge"):
            cast = "(int32_t)" + lhs
            op = {"jl": "<", "jle": "<=", "jg": ">", "jge": ">="}[jcc]
            return f"({cast} {op} 0)", desc
        return None

    # ── neg: flags from (0 - a_orig), result is -a ──
    if flag_setter == "neg":
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc in ("jb", "jnae", "jc"):
            # CF=1 unless original was 0
            return f"({lhs} != 0)", desc
        if jcc in ("jae", "jnb", "jnc"):
            return f"({lhs} == 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jg", "jnle"):
            return f"((int32_t){lhs} > 0)", desc
        if jcc in ("jge", "jnl"):
            return f"((int32_t){lhs} >= 0)", desc
        if jcc in ("jl", "jnge"):
            return f"((int32_t){lhs} < 0)", desc
        if jcc in ("jle", "jng"):
            return f"((int32_t){lhs} <= 0)", desc
        return None

    # ── shift: result-based ──
    if flag_setter in ("shl", "shr", "sar"):
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        return None

    # ── shld/shrd: double-precision shift, result-based ──
    if flag_setter in ("shld", "shrd"):
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        if jcc == "js":
            return f"((int32_t){lhs} < 0)", desc
        if jcc == "jns":
            return f"((int32_t){lhs} >= 0)", desc
        return None

    # ── rol/ror/rcl/rcr: rotation, only CF/OF affected ──
    if flag_setter in ("rol", "ror", "rcl", "rcr"):
        # ZF/SF not modified by rotations - can't resolve most conditions
        return None

    # ── bsf/bsr: bit scan, ZF set if source is zero ──
    if flag_setter in ("bsf", "bsr"):
        if rhs is None:
            return None
        if jcc in ("je", "jz"):
            return f"({rhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({rhs} != 0)", desc
        return None

    # ── bt/bts/btr/btc: bit test, sets CF ──
    if flag_setter in ("bt", "bts", "btr", "btc"):
        if rhs is None:
            return None
        if jcc in ("jb", "jnae", "jc"):
            return f"(({lhs} >> ({rhs} & 31)) & 1)", desc
        if jcc in ("jae", "jnb", "jnc"):
            return f"!(({lhs} >> ({rhs} & 31)) & 1)", desc
        return None

    # ── cmpxchg: compares accumulator with dest, sets ZF on match ──
    if flag_setter == "cmpxchg":
        # ZF = (accumulator == old destination), latched by the lifted
        # cmpxchg in g_str_a/g_str_b before either side is overwritten.
        if jcc in ("je", "jz"):
            return "(g_str_a == g_str_b)", desc
        if jcc in ("jne", "jnz"):
            return "(g_str_a != g_str_b)", desc
        return None

    # ── xadd: exchange and add, flags from addition ──
    if flag_setter == "xadd":
        if jcc in ("je", "jz"):
            return f"({lhs} == 0)", desc
        if jcc in ("jne", "jnz"):
            return f"({lhs} != 0)", desc
        return None

    # ── repe cmps / repne scas: flags come from the final compared operand pair,
    # left in g_str_a/g_str_b by the lifted loop (see _lift_rep_string). ──
    if "cmps" in flag_setter or "scas" in flag_setter:
        if jcc in ("je", "jz"):
            return "(g_str_a == g_str_b)", desc
        if jcc in ("jne", "jnz"):
            return "(g_str_a != g_str_b)", desc
        if jcc in ("ja", "jnbe"):
            return "(g_str_a > g_str_b)", desc
        if jcc in ("jb", "jnae", "jc"):
            return "(g_str_a < g_str_b)", desc
        if jcc in ("jae", "jnb", "jnc"):
            return "(g_str_a >= g_str_b)", desc
        if jcc in ("jbe", "jna"):
            return "(g_str_a <= g_str_b)", desc
        return None

    return None


def _make_setcc_value(setcc_mnemonic, flag_setter, flag_ops):
    """Generate the condition expression for a SETcc instruction."""
    cc = setcc_mnemonic[3:]
    jcc = "j" + cc
    result = _make_condition(jcc, flag_setter, flag_ops)
    if result:
        return result[0]
    return None


def _make_cmovcc_cond(cmov_mnemonic, flag_setter, flag_ops):
    """Generate the condition expression for a CMOVcc instruction."""
    cc = cmov_mnemonic[4:]
    jcc = "j" + cc
    result = _make_condition(jcc, flag_setter, flag_ops)
    if result:
        return result[0]
    return None


# ── Pattern matching for flag-setter + jcc ────────────────────

def _emit_cond_goto(cond_expr, jcc, desc, target, lifter):
    """Emit a conditional goto or call for a jump target."""
    if target is None:
        return f"if ({cond_expr}) {{ /* {jcc}: {desc} - indirect */ }}"
    if lifter and lifter._is_external_target(target):
        name = lifter._call_target_name(target)
        # Conditional tail-jmp: sync g_seh_ebp like the unconditional tail-jmp does,
        # so fpo_leaf callees inherit the CURRENT frame pointer (not a stale one).
        return (f"if ({cond_expr}) {{ g_seh_ebp = ebp; {name}(); return; }}"
                f" /* {jcc}: {desc} */")
    return f"if ({cond_expr}) goto loc_{target:08X}; /* {jcc}: {desc} */"


def try_match_cmp_jcc(insns, idx, lifter=None):
    """
    Try to match a cmp/test + jcc pattern starting at insns[idx].
    Returns (c_statement, num_consumed) or None.
    """
    if idx + 1 >= len(insns):
        return None

    first = insns[idx]
    second = insns[idx + 1]

    if first.mnemonic not in ("cmp", "test") or not second.is_cond_jump:
        return None

    if len(first.operands) < 2:
        return None

    result = _make_condition(second.mnemonic, first.mnemonic, first.operands)
    if not result:
        return None

    cond_expr, desc = result
    target = second.jump_target
    stmt = _emit_cond_goto(cond_expr, second.mnemonic, desc, target, lifter)
    return (stmt, 2)


# ── Single instruction lifting ───────────────────────────────



def _make_cf_expr(setter, ops):
    """C expression for the carry flag after `setter ops` (recomp bug #10).
    Reads operands at their POST-instruction values, so only setters whose
    CF is recoverable from post-state are handled; return None otherwise."""
    if setter in ("and", "or", "xor", "test"):
        return "0"
    if not ops:
        return None
    a = _fmt_operand_read(ops[0])
    if setter == "neg":
        return f"(({a}) != 0)"
    if len(ops) < 2:
        return None
    b = _fmt_operand_read(ops[1])
    if setter == "cmp":
        return f"((uint32_t)({a}) < (uint32_t)({b}))"
    same = (ops[0].type == "reg" and ops[1].type == "reg"
            and ops[0].reg == ops[1].reg)
    if setter == "sub":
        if same:
            return "0"
        # post = orig - b  =>  CF = (orig < b) = ((post + b) mod 2^32 < b)
        return f"((uint32_t)(({a}) + ({b})) < (uint32_t)({b}))"
    if setter == "add":
        if same:
            return None  # CF = high bit of orig; not recoverable cheaply
        return f"((uint32_t)({a}) < (uint32_t)({b}))"
    return None

def _st_index(regname):
    """'st' -> 0, 'st(3)'/'st3' -> 3."""
    import re as _re
    m = _re.search(r"(\d+)", regname)
    return int(m.group(1)) if m else 0


class Lifter:
    """Translates x86 instructions to C statements."""

    def __init__(self, func_db=None, label_db=None, abi_db=None, xbe_data=None):
        """
        func_db: dict of func_addr → func_info (for naming call targets)
        label_db: dict of addr → name (for kernel imports, etc.)
        abi_db: dict of addr → ABI info (for calling conventions)
        xbe_data: raw XBE file bytes (for reading jump tables)
        """
        self.func_db = func_db or {}
        self.label_db = label_db or {}
        self.abi_db = abi_db or {}
        self.xbe_data = xbe_data
        self._fp_top = 0  # FPU stack top index
        self.func_start = 0  # Set per-function by translator
        self.func_end = 0

    def _call_target_name(self, addr):
        """Get the name for a call target address."""
        if addr in self.label_db:
            return self.label_db[addr]
        if addr in self.func_db:
            info = self.func_db[addr]
            name = info.get("name", f"sub_{addr:08X}")
            return name
        return f"sub_{addr:08X}"

    def lift_instruction(self, insn):
        """
        Translate a single x86 instruction to one or more C statements.
        Returns a list of C statement strings.
        """
        m = insn.mnemonic
        ops = insn.operands
        nops = len(ops)

        # ── NOP ──
        if m == "nop" or (m == "lea" and nops == 2 and
                          ops[0].type == "reg" and ops[1].type == "mem" and
                          ops[1].mem_base == ops[0].reg and
                          not ops[1].mem_index and ops[1].mem_disp == 0):
            return [f"/* nop */"]

        # ── MMX (64-bit integer SIMD, mm0-mm7) — recomp bug #11 ──
        if _is_mmx_insn(m, ops):
            return _lift_mmx(insn, m, ops)

        # ── Data movement ──
        if m == "mov":
            return self._lift_mov(insn, ops)
        if m == "movzx":
            return self._lift_movzx(insn, ops)
        if m == "movsx":
            return self._lift_movsx(insn, ops)
        if m == "lea":
            return self._lift_lea(insn, ops)
        if m == "xchg":
            return self._lift_xchg(insn, ops)

        # ── Stack ──
        if m == "push":
            return self._lift_push(insn, ops)
        if m == "pop":
            return self._lift_pop(insn, ops)

        # ── Arithmetic ──
        if m in ("add", "sub", "and", "or", "xor"):
            return self._lift_alu_binop(insn, ops, m)
        if m in ("inc", "dec"):
            return self._lift_inc_dec(insn, ops, m)
        if m == "neg":
            return self._lift_neg(insn, ops)
        if m == "not":
            return self._lift_not(insn, ops)
        if m == "imul":
            return self._lift_imul(insn, ops)
        if m in ("mul", "div", "idiv"):
            return self._lift_muldiv(insn, ops, m)
        if m == "sbb":
            return self._lift_sbb(insn, ops)
        if m == "adc":
            return self._lift_adc(insn, ops)
        if m in ("shl", "sal"):
            return self._lift_shift(insn, ops, "<<")
        if m == "shr":
            return self._lift_shift(insn, ops, ">>")
        if m == "sar":
            return self._lift_sar(insn, ops)
        if m in ("rol", "ror"):
            return self._lift_rotate(insn, ops, m)

        # ── Comparison / test (standalone, not part of cmp+jcc pattern) ──
        if m == "cmp":
            return self._lift_cmp(insn, ops)
        if m == "test":
            return self._lift_test(insn, ops)

        # ── Control flow ──
        if m == "call":
            return self._lift_call(insn, ops)
        if m in ("ret", "retn", "retf"):
            return self._lift_ret(insn, ops)
        if m == "jmp":
            return self._lift_jmp(insn, ops)
        if insn.is_cond_jump:
            return self._lift_jcc(insn)

        # ── String operations ──
        if m.startswith("rep ") or m.startswith("repe ") or m.startswith("repne "):
            return self._lift_rep_string(insn, m)
        if m in ("movsb", "movsd", "movsw", "stosb", "stosd", "stosw",
                 "lodsb", "lodsd", "lodsw"):
            return self._lift_string_op(insn, m)
        if m == "wait":
            return ["/* wait - FPU sync */"]

        # ── Misc ──
        if m == "cdq":
            return ["edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */"]
        if m == "cwde":
            return ["eax = SX16(eax); /* cwde */"]
        if m == "cbw":
            return ["SET_LO16(eax, SX8(eax)); /* cbw */"]
        if m == "bswap" and nops >= 1 and ops[0].type == "reg":
            r = _fmt_reg(ops[0].reg)
            return [f"{r} = BSWAP32({r}); /* bswap */"]
        if m in ("bsf", "bsr") and nops == 2 and ops[0].type == "reg" \
                and ops[0].reg in ("eax", "ebx", "ecx", "edx",
                                   "esi", "edi", "ebp"):
            # Bit scan: dest = index of the lowest (bsf) / highest (bsr)
            # set bit. A zero source sets ZF and leaves dest unchanged.
            # The XDK's log2 helpers (XGSetTextureHeader's size fields) are
            # a bare `bsf eax, src; ret` -- an unlifted scan left eax as
            # whatever the caller had, and texture headers were built with
            # garbage log2 width/height/level fields.
            dst = _fmt_reg(ops[0].reg)
            src = _fmt_operand_read(ops[1])
            fn = "BSF32" if m == "bsf" else "BSR32"
            return [f"{{ uint32_t _bs = (uint32_t)({src}); "
                    f"if (_bs) {dst} = {fn}(_bs); }} /* {m} */"]
        if m == "int3":
            return ["__debugbreak(); /* int3 */"]
        if m in ("leave",):
            return ["esp = ebp;", "POP32(esp, ebp); /* leave */"]
        if m in ("cld", "std"):
            return [f"/* {m} - direction flag */"]
        if m == "lahf":
            return ["/* lahf - load AH from flags (used in FPU compare idiom) */"]
        if m == "sahf":
            return ["/* sahf - store AH to flags */"]
        if m == "shld":
            return self._lift_shld(insn, ops)
        if m == "shrd":
            return self._lift_shrd(insn, ops)
        if m == "bt":
            if len(ops) >= 2:
                return [f"/* bt {_fmt_operand_read(ops[0])}, {_fmt_operand_read(ops[1])} - bit test */"]
            return [f"/* bt {insn.op_str} */"]
        if m == "emms":
            return ["/* emms - empty MMX state */"]
        if m in ("sete", "setne", "setb", "setae", "setbe", "seta",
                 "setl", "setge", "setle", "setg", "sets", "setns"):
            return self._lift_setcc(insn, ops, m)
        if m in ("cmove", "cmovne", "cmovb", "cmovae", "cmovbe", "cmova",
                 "cmovl", "cmovge", "cmovle", "cmovg", "cmovs", "cmovns"):
            return self._lift_cmovcc(insn, ops, m)

        # Cache hints and store fences have no effect on the host model.
        if m.startswith("prefetch") or m in ("sfence", "lfence", "mfence"):
            return [f"/* {m} {insn.op_str} */"]
        if m == "cmpxchg" and len(ops) >= 2:
            # Latch accumulator and old destination for the following jcc
            # (ZF = equal), then exchange.
            d = _fmt_operand_read(ops[0])
            return [f"{{ uint32_t _cx_old = {d}; g_str_a = eax; g_str_b = _cx_old;",
                    f"if (eax == _cx_old) {{ {_fmt_operand_write(ops[0], _fmt_operand_read(ops[1]))} }}",
                    f"else {{ eax = _cx_old; }} }} /* cmpxchg */"]
        if m == "xadd" and len(ops) >= 2:
            d = _fmt_operand_read(ops[0]); r = _fmt_operand_read(ops[1])
            return [f"{{ uint32_t _xa_old = {d}; uint32_t _xa_sum = _xa_old + {r};",
                    _fmt_operand_write(ops[1], "_xa_old"),
                    _fmt_operand_write(ops[0], "_xa_sum") + " } /* xadd */"]

        # ── SSE (scalar float) ──
        if m in ("movss", "movsd", "movaps", "movups", "movlps", "movhps",
                 "movntps", "movlhps", "movhlps", "sqrtps", "rsqrtps", "rcpps",
                 "addss", "subss", "mulss", "divss", "sqrtss",
                 "addsd", "subsd", "mulsd", "divsd", "sqrtsd",
                 "minss", "maxss", "minsd", "maxsd",
                 "comiss", "comisd", "ucomiss", "ucomisd",
                 "cvtsi2ss", "cvtss2si", "cvttss2si",
                 "cvtsi2sd", "cvtsd2si", "cvttsd2si",
                 "cvtss2sd", "cvtsd2ss",
                 "xorps", "xorpd", "andps", "orps",
                 "movd", "movq",
                 "shufps", "unpcklps", "unpckhps",
                 "addps", "subps", "mulps", "divps",
                 "minps", "maxps", "rsqrtss", "rcpss",
                 "cmpneqps", "cmpeqps", "cmpltps", "cmpleps",
                 "movmskps",
                 "pand", "pandn", "por", "pxor", "pcmpgtd"):
            return self._lift_sse(insn, m, ops)

        # ── FPU ──
        if m.startswith("f"):
            return self._lift_fpu(insn, m, ops)

        # ── Unhandled ──
        return [f"/* TODO: {m} {insn.op_str} */"]

    # ── MOV family ──

    def _lift_mov(self, insn, ops):
        if nops := len(ops) < 2:
            return [f"/* mov: bad operands */"]
        src = _fmt_operand_read(ops[1])
        return [_fmt_operand_write(ops[0], src)]

    def _lift_movzx(self, insn, ops):
        if len(ops) < 2:
            return [f"/* movzx: bad operands */"]
        src = _fmt_operand_read(ops[1])
        if ops[1].type == "mem":
            if ops[1].mem_size == 1:
                src = f"ZX8({src})"
            elif ops[1].mem_size == 2:
                src = f"ZX16({src})"
        elif ops[1].type == "reg":
            r = ops[1].reg
            if r in ("al", "bl", "cl", "dl", "ah", "bh", "ch", "dh"):
                src = f"ZX8({src})"
            elif r in ("ax", "bx", "cx", "dx", "si", "di", "bp", "sp"):
                src = f"ZX16({src})"
        return [_fmt_operand_write(ops[0], src)]

    def _lift_movsx(self, insn, ops):
        if len(ops) < 2:
            return [f"/* movsx: bad operands */"]
        src = _fmt_operand_read(ops[1])
        if ops[1].type == "mem":
            accessor = _smem_accessor(ops[1].mem_size)
            addr = _fmt_mem(ops[1])
            src = f"(uint32_t)(int32_t){accessor}({addr})"
        elif ops[1].type == "reg":
            r = ops[1].reg
            if r in ("al", "bl", "cl", "dl", "ah", "bh", "ch", "dh"):
                src = f"SX8({src})"
            elif r in ("ax", "bx", "cx", "dx", "si", "di"):
                src = f"SX16({src})"
        return [_fmt_operand_write(ops[0], src)]

    def _lift_lea(self, insn, ops):
        if len(ops) < 2 or ops[1].type != "mem":
            return [f"/* lea: unexpected operands */"]
        addr_expr = _fmt_mem(ops[1])
        return [_fmt_operand_write(ops[0], addr_expr)]

    def _lift_xchg(self, insn, ops):
        if len(ops) < 2:
            return [f"/* xchg: bad operands */"]
        a = _fmt_operand_read(ops[0])
        b = _fmt_operand_read(ops[1])
        return [
            f"{{ uint32_t _tmp = {a};",
            _fmt_operand_write(ops[0], b),
            _fmt_operand_write(ops[1], "_tmp") + " }",
        ]

    # ── Stack ──

    def _lift_push(self, insn, ops):
        if len(ops) < 1:
            return ["/* push: no operand */"]
        val = _fmt_operand_read(ops[0])
        return [f"PUSH32(esp, {val});"]

    def _lift_pop(self, insn, ops):
        if len(ops) < 1:
            return ["/* pop: no operand */"]
        if ops[0].type == "reg":
            r = ops[0].reg
            # Segment register pop → discard from stack
            if r in ("fs", "gs", "cs", "ds", "es", "ss"):
                return [f"{{ uint32_t _tmp; POP32(esp, _tmp); }} /* pop {r} - segment register */"]
            return [f"POP32(esp, {r});"]
        else:
            return [f"{{ uint32_t _tmp; POP32(esp, _tmp); {_fmt_operand_write(ops[0], '_tmp')} }}"]

    # ── ALU binary operations ──

    def _lift_alu_binop(self, insn, ops, m):
        if len(ops) < 2:
            return [f"/* {m}: bad operands */"]
        c_op = {"add": "+", "sub": "-", "and": "&", "or": "|", "xor": "^"}[m]
        dst = _fmt_operand_read(ops[0])
        src = _fmt_operand_read(ops[1])
        # XOR reg, reg → zero
        if m == "xor" and ops[0].type == "reg" and ops[1].type == "reg" and ops[0].reg == ops[1].reg:
            return [_fmt_operand_write(ops[0], "0") + " /* xor self */"]
        expr = f"{dst} {c_op} {src}"
        return [_fmt_operand_write(ops[0], expr)]

    def _lift_inc_dec(self, insn, ops, m):
        if len(ops) < 1:
            return [f"/* {m}: no operand */"]
        val = _fmt_operand_read(ops[0])
        delta = "1"
        op_char = "+" if m == "inc" else "-"
        # For sub-registers (al, cl, etc.), use the SET macro instead of ++
        if ops[0].type == "reg" and ops[0].reg in (
                "eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"):
            return [f"{val}{'++' if m == 'inc' else '--'};"]
        else:
            return [_fmt_operand_write(ops[0], f"{val} {op_char} {delta}")]

    def _lift_neg(self, insn, ops):
        if len(ops) < 1:
            return ["/* neg: no operand */"]
        val = _fmt_operand_read(ops[0])
        return [_fmt_operand_write(ops[0], f"(uint32_t)(-(int32_t){val})")]

    def _lift_not(self, insn, ops):
        if len(ops) < 1:
            return ["/* not: no operand */"]
        val = _fmt_operand_read(ops[0])
        return [_fmt_operand_write(ops[0], f"~{val}")]

    def _lift_sbb(self, insn, ops):
        """SBB: subtract with borrow. Common idiom: sbb reg, reg → -CF (0 or -1)."""
        if len(ops) < 2:
            return ["/* sbb: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        src = _fmt_operand_read(ops[1])
        # sbb reg, reg is a common idiom: result is 0 or 0xFFFFFFFF depending on CF
        if ops[0].type == "reg" and ops[1].type == "reg" and ops[0].reg == ops[1].reg:
            return [_fmt_operand_write(ops[0], "_cf ? 0xFFFFFFFF : 0") + " /* sbb self (CF extend) */"]
        return [_fmt_operand_write(ops[0], f"{dst} - {src} - _cf") + " /* sbb */"]

    def _lift_adc(self, insn, ops):
        """ADC: add with carry."""
        if len(ops) < 2:
            return ["/* adc: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        src = _fmt_operand_read(ops[1])
        return [_fmt_operand_write(ops[0], f"{dst} + {src} + _cf") + " /* adc */"]

    def _lift_shld(self, insn, ops):
        """SHLD: double-precision shift left."""
        if len(ops) < 3:
            return [f"/* shld: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        src = _fmt_operand_read(ops[1])
        cnt = _fmt_operand_read(ops[2])
        return [_fmt_operand_write(ops[0],
            f"({dst} << {cnt}) | ({src} >> (32 - {cnt}))") + " /* shld */"]

    def _lift_shrd(self, insn, ops):
        """SHRD: double-precision shift right."""
        if len(ops) < 3:
            return [f"/* shrd: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        src = _fmt_operand_read(ops[1])
        cnt = _fmt_operand_read(ops[2])
        return [_fmt_operand_write(ops[0],
            f"({dst} >> {cnt}) | ({src} << (32 - {cnt}))") + " /* shrd */"]

    def _lift_imul(self, insn, ops):
        nops = len(ops)
        if nops == 1:
            # One operand: edx:eax = eax * ops[0]
            src = _fmt_operand_read(ops[0])
            return [
                f"{{ int64_t _r = (int64_t)(int32_t)eax * (int64_t)(int32_t){src};",
                f"  eax = (uint32_t)_r; edx = (uint32_t)(_r >> 32); }}"
            ]
        elif nops == 2:
            # Two operand: dst = dst * src
            dst = _fmt_operand_read(ops[0])
            src = _fmt_operand_read(ops[1])
            return [_fmt_operand_write(ops[0], f"(uint32_t)((int32_t){dst} * (int32_t){src})")]
        elif nops == 3:
            # Three operand: dst = src1 * imm
            src = _fmt_operand_read(ops[1])
            imm = _fmt_operand_read(ops[2])
            return [_fmt_operand_write(ops[0], f"(uint32_t)((int32_t){src} * (int32_t){imm})")]
        return ["/* imul: unexpected form */"]

    def _lift_muldiv(self, insn, ops, m):
        if len(ops) < 1:
            return [f"/* {m}: no operand */"]
        src = _fmt_operand_read(ops[0])
        if m == "mul":
            return [
                f"{{ uint64_t _r = (uint64_t)eax * (uint64_t){src};",
                f"  eax = (uint32_t)_r; edx = (uint32_t)(_r >> 32); }}"
            ]
        elif m == "div":
            return [
                f"{{ uint64_t _dividend = ((uint64_t)edx << 32) | eax;",
                f"  eax = (uint32_t)(_dividend / (uint32_t){src});",
                f"  edx = (uint32_t)(_dividend % (uint32_t){src}); }}"
            ]
        elif m == "idiv":
            return [
                f"{{ int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;",
                f"  eax = (uint32_t)((int32_t)(_dividend / (int32_t){src}));",
                f"  edx = (uint32_t)((int32_t)(_dividend % (int32_t){src})); }}"
            ]
        return [f"/* {m}: unhandled */"]

    def _lift_shift(self, insn, ops, c_op):
        if len(ops) < 2:
            return [f"/* shift: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        cnt = _fmt_operand_read(ops[1])
        return [_fmt_operand_write(ops[0], f"{dst} {c_op} {cnt}")]

    def _lift_sar(self, insn, ops):
        if len(ops) < 2:
            return ["/* sar: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        cnt = _fmt_operand_read(ops[1])
        return [_fmt_operand_write(ops[0], f"(uint32_t)((int32_t){dst} >> {cnt})")]

    def _lift_rotate(self, insn, ops, m):
        if len(ops) < 2:
            return [f"/* {m}: bad operands */"]
        dst = _fmt_operand_read(ops[0])
        cnt = _fmt_operand_read(ops[1])
        func = "ROL32" if m == "rol" else "ROR32"
        return [_fmt_operand_write(ops[0], f"{func}({dst}, {cnt})")]

    # ── Compare / Test (standalone) ──

    def _lift_cmp(self, insn, ops):
        if len(ops) < 2:
            return ["/* cmp: bad operands */"]
        lhs = _fmt_operand_read(ops[0])
        rhs = _fmt_operand_read(ops[1])
        return [f"/* cmp {lhs}, {rhs} - flags set for next jcc */"]

    def _lift_test(self, insn, ops):
        if len(ops) < 2:
            return ["/* test: bad operands */"]
        lhs = _fmt_operand_read(ops[0])
        rhs = _fmt_operand_read(ops[1])
        return [f"/* test {lhs}, {rhs} - flags set for next jcc */"]

    # ── Control flow ──

    def _build_call_args(self, target_addr):
        """Build argument list for a function call based on ABI data."""
        abi_info = self.abi_db.get(target_addr, {})
        cc = abi_info.get("calling_convention", "cdecl")
        num_params = abi_info.get("estimated_params", 0)

        args = []
        if cc in ("thiscall", "thiscall_cdecl"):
            args.append("(void*)(uintptr_t)ecx")
        for i in range(num_params):
            args.append(f"0 /* a{i+1} */")
        return ", ".join(args)

    # SEH prolog/epilog addresses - these functions modify ebp for their
    # caller.  After calling __SEH_prolog, the caller must read back ebp
    # from g_seh_ebp.  Before returning, __SEH_prolog writes g_seh_ebp.
    SEH_PROLOG = _cfg.SEH_PROLOG
    SEH_EPILOG = _cfg.SEH_EPILOG

    def _lift_call(self, insn, ops):
        # x86 'call' pushes return address then jumps.
        # With global esp, we push a dummy return address (0) then call.
        # The callee's 'ret' will pop it back off.
        if insn.call_target:
            name = self._call_target_name(insn.call_target)
            # publish ebp: frame-inheriting callees (fpo_leaf, SEH epilog) read it from g_seh_ebp
            lines = [f"g_seh_ebp = ebp; PUSH32(esp, 0); {name}(); /* call 0x{insn.call_target:08X} */"]
            # After __SEH_prolog/__SEH_epilog, read back the frame pointer.
            if insn.call_target in (self.SEH_PROLOG, self.SEH_EPILOG):
                lines.append("ebp = g_seh_ebp; /* read back frame from SEH helper */")
            return lines
        elif len(ops) >= 1:
            target = _fmt_operand_read(ops[0])
            # Read the call target into a temp BEFORE pushing the dummy return.
            # For esp-relative targets (e.g. `call [esp+0xC]`), pushing first shifts esp
            # so MEM32(esp+X) would read the wrong slot (the just-pushed dummy). The
            # original x86 reads the target at the pre-push esp.
            return [f"{{ uint32_t _icall_t = {target}; g_seh_ebp = ebp; PUSH32(esp, 0); "
                    f"RECOMP_ICALL_SAFE(_icall_t, _icall_esp); }} /* indirect call */"]
        return ["/* call: no target */"]

    def _lift_ret(self, insn, ops):
        # x86 'ret' pops return address from stack.
        # 'ret N' also pops N extra bytes (stdcall cleanup).
        # If this function IS __SEH_prolog or __SEH_epilog, bridge ebp
        # so the caller can read back the frame pointer.
        prefix = ""
        if self.func_start in (self.SEH_PROLOG, self.SEH_EPILOG):
            prefix = "g_seh_ebp = ebp; "
        if len(ops) >= 1 and ops[0].type == "imm":
            n = ops[0].imm
            return [f"{prefix}esp += {4 + n}; return; /* ret {n} */"]
        return [f"{prefix}esp += 4; return; /* ret */"]

    def _is_external_target(self, addr):
        """Check if a jump target is outside the current function."""
        return not (self.func_start <= addr < self.func_end)

    def _read_jump_table(self, table_va, max_entries=256):
        """Read 32-bit jump table entries from the XBE at a given VA.
        Returns list of target addresses. Stops when an entry is not a
        valid code address or max_entries is reached."""
        if not self.xbe_data:
            return []
        offset = va_to_file_offset(table_va)
        if offset is None:
            return []
        targets = []
        for i in range(max_entries):
            o = offset + i * 4
            if o + 4 > len(self.xbe_data):
                break
            val = struct.unpack_from('<I', self.xbe_data, o)[0]
            if not is_code_address(val):
                break
            targets.append(val)
        return targets

    def _analyze_switch_table(self, ops):
        """Detect if an indirect jmp operand is an intra-function switch table.
        Pattern: jmp [reg*scale + table_base] or jmp [reg + table_base]
        Returns (targets: list[int]) if ALL table entries are within the current
        function, else empty list."""
        if not ops or ops[0].type != "mem":
            return []
        op = ops[0]
        # Need a table base (displacement) and an index register
        if not op.mem_disp or not (op.mem_index or op.mem_base):
            return []
        table_va = op.mem_disp
        targets = self._read_jump_table(table_va)
        if not targets:
            return []
        # Trim at the first out-of-function entry: _read_jump_table has no size
        # bound, so it can run past the real table into adjacent data that
        # happens to look like code addresses. The switch's index is guarded by
        # a cmp/ja before the jmp, so dropping trailing entries is safe (an
        # index past the trim falls to the RECOMP_ITAIL default, which is the
        # old behavior). A genuinely out-of-function case target also ends the
        # trim - it degrades to ITAIL for that index only.
        trimmed = []
        for t in targets:
            if not (self.func_start <= t < self.func_end):
                break
            trimmed.append(t)
        return trimmed

    def _lift_jmp(self, insn, ops):
        if insn.jump_target:
            if self._is_external_target(insn.jump_target):
                # Tail call - no return address push (reuses current frame's)
                # Bridge ebp so the target function can inherit our frame pointer.
                name = self._call_target_name(insn.jump_target)
                return [f"g_seh_ebp = ebp; {name}(); return; /* tail jmp 0x{insn.jump_target:08X} */"]
            return [f"goto loc_{insn.jump_target:08X};"]
        elif len(ops) >= 1:
            # Detect intra-function switch tables (computed gotos)
            switch_targets = self._analyze_switch_table(ops)
            if switch_targets:
                target_expr = _fmt_operand_read(ops[0])
                unique_targets = sorted(set(switch_targets))
                lines = [f"{{ uint32_t _jt = {target_expr}; /* switch: {len(switch_targets)} entries, {len(unique_targets)} targets */"]
                for t in unique_targets:
                    lines.append(f"if (_jt == 0x{t:08X}u) goto loc_{t:08X};")
                lines.append(f"g_seh_ebp = ebp; RECOMP_ITAIL(_jt); return; }}")
                return lines
            target = _fmt_operand_read(ops[0])
            return [f"g_seh_ebp = ebp; RECOMP_ITAIL({target}); return; /* indirect tail jmp */"]
        return ["/* jmp: no target */"]

    def _lift_jcc(self, insn):
        """Standalone conditional jump (no flag-setter tracked)."""
        target = insn.jump_target
        jcc = insn.mnemonic

        # jecxz/jcxz: jump if ecx/cx is zero (not flag-based)
        if jcc in ("jecxz", "jcxz"):
            cond = "ecx == 0" if jcc == "jecxz" else "LO16(ecx) == 0"
            if target:
                if self._is_external_target(target):
                    name = self._call_target_name(target)
                    return [f"if ({cond}) {{ {name}(); return; }} /* {jcc} */"]
                return [f"if ({cond}) goto loc_{target:08X}; /* {jcc} */"]
            return [f"/* {jcc} - no target */"]

        cond_info = COND_MAP.get(jcc)
        desc = cond_info[2] if cond_info else jcc
        if target:
            if self._is_external_target(target):
                name = self._call_target_name(target)
                return [f"if (_flags /* {jcc}: {desc} */) {{ {name}(); return; }}"]
            return [f"if (_flags /* {jcc}: {desc} */) goto loc_{target:08X};"]
        return [f"/* {jcc}: {desc} - no target */"]

    # ── SETcc / CMOVcc ──

    def _lift_setcc(self, insn, ops, m):
        if len(ops) < 1:
            return [f"/* {m}: no operand */"]
        return [_fmt_operand_write(ops[0], f"_flags /* {m} */")]

    def _lift_cmovcc(self, insn, ops, m):
        if len(ops) < 2:
            return [f"/* {m}: bad operands */"]
        src = _fmt_operand_read(ops[1])
        return [f"if (_flags /* {m} */) {_fmt_operand_write(ops[0], src)}"]

    # ── String operations ──

    def _lift_rep_string(self, insn, m):
        if "movsb" in m:
            return ["memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);",
                    "esi += ecx; edi += ecx; ecx = 0; /* rep movsb */"]
        if "movsd" in m:
            return ["memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);",
                    "esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */"]
        if "movsw" in m:
            return ["memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 2);",
                    "esi += ecx * 2; edi += ecx * 2; ecx = 0; /* rep movsw */"]
        if "stosb" in m:
            return ["memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);",
                    "edi += ecx; ecx = 0; /* rep stosb */"]
        if "stosd" in m:
            return [
                "{ uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }",
                "edi += ecx * 4; ecx = 0; /* rep stosd */"
            ]
        if "stosw" in m:
            return [
                "{ uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM16(edi + _i*2) = LO16(eax); }",
                "edi += ecx * 2; ecx = 0; /* rep stosw */"
            ]
        # rep[e]/repne cmps / scas: actually run the compare loop, leaving esi/edi/ecx
        # updated and the final compared operand pair in g_str_a/g_str_b for the jcc.
        # repe (cmps) continues while equal; repne (scas) continues while not equal.
        if "cmps" in m:
            if "cmpsd" in m:
                rd, step = "MEM32(esi)", "MEM32(edi)"; sz = 4
            elif "cmpsw" in m:
                rd, step = "(uint16_t)MEM16(esi)", "(uint16_t)MEM16(edi)"; sz = 2
            else:
                rd, step = "(uint8_t)MEM8(esi)", "(uint8_t)MEM8(edi)"; sz = 1
            cont = "==" if m.startswith("repe") or m.startswith("rep ") else "!="
            return [("{ uint32_t _ca=0,_cb=0; while (ecx != 0) { "
                     f"_ca={rd}; _cb={step}; esi+={sz}; edi+={sz}; ecx--; "
                     f"if (!(_ca {cont} _cb)) break; }} g_str_a=_ca; g_str_b=_cb; }}"
                     f" /* {m} */")]
        if "scas" in m:
            if "scasd" in m:
                al, rd, step = "eax", "MEM32(edi)", 4
            elif "scasw" in m:
                al, rd, step = "(uint16_t)LO16(eax)", "(uint16_t)MEM16(edi)", 2
            else:
                al, rd, step = "(uint8_t)LO8(eax)", "(uint8_t)MEM8(edi)", 1
            cont = "!=" if m.startswith("repne") else "=="
            return [("{ uint32_t _sa=" + f"{al}" + ", _sb=0; while (ecx != 0) { "
                     f"_sb={rd}; edi+={step}; ecx--; "
                     f"if (!(_sa {cont} _sb)) break; }} g_str_a=_sa; g_str_b=_sb; }}"
                     f" /* {m} */")]
        return [f"/* {m} */"]

    def _lift_string_op(self, insn, m):
        if m == "movsb":
            return ["MEM8(edi) = MEM8(esi); esi++; edi++; /* movsb */"]
        if m == "movsd":
            return ["MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */"]
        if m == "stosb":
            return ["MEM8(edi) = LO8(eax); edi++; /* stosb */"]
        if m == "stosd":
            return ["MEM32(edi) = eax; edi += 4; /* stosd */"]
        if m == "lodsb":
            return ["SET_LO8(eax, MEM8(esi)); esi++; /* lodsb */"]
        if m == "lodsd":
            return ["eax = MEM32(esi); esi += 4; /* lodsd */"]
        if m == "movsw":
            return ["MEM16(edi) = MEM16(esi); esi += 2; edi += 2; /* movsw */"]
        if m == "stosw":
            return ["MEM16(edi) = LO16(eax); edi += 2; /* stosw */"]
        if m == "lodsw":
            return ["SET_LO16(eax, MEM16(esi)); esi += 2; /* lodsw */"]
        return [f"/* {m} */"]

    # ── FPU (x87) ──

    # ── SSE (scalar/packed float) ──

    def _lift_sse(self, insn, m, ops):
        """SSE translation over xmm128_t lanes (see recomp_types.h xmm_*).

        Every xmm register is a 4-lane union. Scalar ops (movss/addss/...)
        touch lane 0 and keep the others; a movss load from memory zeroes
        lanes 1-3 like the hardware. Packed ops go through the helpers, so
        the XDK matrix routines (movaps/shufps/mulps/addps/subps/cmpneqps/
        orps/xorps/movlps/movhps/rcpss) compute what the Xbox computed.
        """
        nops = len(ops)
        if nops < 1:
            return [f"/* {m}: no operands */"]

        def is_xmm(op):
            return op.type == "reg" and op.reg.startswith("xmm")

        def rd(op):
            """Read a 128-bit value (register, or 16-byte memory)."""
            if is_xmm(op):
                return op.reg
            if op.type == "mem":
                return f"xmm_load({_fmt_mem(op)})"
            return "xmm_zero()"

        def rd_ss(op):
            """Read a scalar float (lane 0 of a register, or a float in memory)."""
            if is_xmm(op):
                return f"{op.reg}.f[0]"
            if op.type == "mem":
                return f"MEMF({_fmt_mem(op)})"
            if op.type == "imm":
                return _fmt_imm(op.imm)
            return "0.0f"

        # -- 128-bit moves --
        if m in ("movaps", "movups", "movntps", "movapd", "movupd", "movdqa", "movdqu"):
            if nops >= 2:
                if is_xmm(ops[0]):
                    return [f"{ops[0].reg} = {rd(ops[1])}; /* {m} */"]
                if ops[0].type == "mem" and is_xmm(ops[1]):
                    return [f"xmm_store({_fmt_mem(ops[0])}, {ops[1].reg}); /* {m} */"]
            return [f"/* {m} {insn.op_str} */"]

        # -- 64-bit half moves --
        if m in ("movlps", "movlpd"):
            if nops >= 2:
                if is_xmm(ops[0]) and ops[1].type == "mem":
                    return [f"{ops[0].reg} = xmm_load_lo({ops[0].reg}, {_fmt_mem(ops[1])}); /* {m} */"]
                if ops[0].type == "mem" and is_xmm(ops[1]):
                    return [f"xmm_store_lo({_fmt_mem(ops[0])}, {ops[1].reg}); /* {m} */"]
        if m in ("movhps", "movhpd"):
            if nops >= 2:
                if is_xmm(ops[0]) and ops[1].type == "mem":
                    return [f"{ops[0].reg} = xmm_load_hi({ops[0].reg}, {_fmt_mem(ops[1])}); /* {m} */"]
                if ops[0].type == "mem" and is_xmm(ops[1]):
                    return [f"xmm_store_hi({_fmt_mem(ops[0])}, {ops[1].reg}); /* {m} */"]
        if m == "movlhps" and nops >= 2 and is_xmm(ops[0]) and is_xmm(ops[1]):
            return [f"{ops[0].reg} = xmm_movlhps({ops[0].reg}, {ops[1].reg}); /* movlhps */"]
        if m == "movhlps" and nops >= 2 and is_xmm(ops[0]) and is_xmm(ops[1]):
            return [f"{ops[0].reg} = xmm_movhlps({ops[0].reg}, {ops[1].reg}); /* movhlps */"]
        if m == "movq" and nops >= 2:
            if is_xmm(ops[0]) and ops[1].type == "mem":
                return [f"{ops[0].reg} = xmm_load_lo(xmm_zero(), {_fmt_mem(ops[1])}); /* movq */"]
            if ops[0].type == "mem" and is_xmm(ops[1]):
                return [f"xmm_store_lo({_fmt_mem(ops[0])}, {ops[1].reg}); /* movq */"]
            if is_xmm(ops[0]) and is_xmm(ops[1]):
                d, sname = ops[0].reg, ops[1].reg
                return [f"{{ xmm128_t _t = xmm_zero(); _t.u[0] = {sname}.u[0]; _t.u[1] = {sname}.u[1]; {d} = _t; }} /* movq */"]

        # -- scalar moves --
        if m == "movss":
            if nops >= 2:
                if is_xmm(ops[0]) and ops[1].type == "mem":
                    return [f"{ops[0].reg} = xmm_load_ss({_fmt_mem(ops[1])}); /* movss */"]
                if ops[0].type == "mem" and is_xmm(ops[1]):
                    return [f"xmm_store_ss({_fmt_mem(ops[0])}, {ops[1].reg}); /* movss */"]
                if is_xmm(ops[0]) and is_xmm(ops[1]):
                    return [f"{ops[0].reg}.u[0] = {ops[1].reg}.u[0]; /* movss reg,reg (upper lanes kept) */"]
        if m == "movsd":
            if nops >= 2:
                if is_xmm(ops[0]) and ops[1].type == "mem":
                    return [f"{ops[0].reg} = xmm_load_lo(xmm_zero(), {_fmt_mem(ops[1])}); /* movsd */"]
                if ops[0].type == "mem" and is_xmm(ops[1]):
                    return [f"xmm_store_lo({_fmt_mem(ops[0])}, {ops[1].reg}); /* movsd */"]
                if is_xmm(ops[0]) and is_xmm(ops[1]):
                    return [f"{ops[0].reg}.u[0] = {ops[1].reg}.u[0]; {ops[0].reg}.u[1] = {ops[1].reg}.u[1]; /* movsd reg,reg */"]
        if m == "movd" and nops >= 2:
            if is_xmm(ops[0]):
                return [f"{ops[0].reg} = xmm_zero(); {ops[0].reg}.u[0] = {_fmt_operand_read(ops[1])}; /* movd to xmm */"]
            if is_xmm(ops[1]):
                return [_fmt_operand_write(ops[0], f"{ops[1].reg}.u[0]") + " /* movd from xmm */"]

        # -- scalar arithmetic (lane 0) --
        sc_ops = {"addss": "+", "subss": "-", "mulss": "*", "divss": "/"}
        if m in sc_ops and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg}.f[0] = {ops[0].reg}.f[0] {sc_ops[m]} {rd_ss(ops[1])}; /* {m} */"]
        if m == "sqrtss" and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg}.f[0] = sqrtf({rd_ss(ops[1])}); /* sqrtss */"]
        if m == "rsqrtss" and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg}.f[0] = 1.0f / sqrtf({rd_ss(ops[1])}); /* rsqrtss */"]
        if m == "rcpss" and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg}.f[0] = 1.0f / {rd_ss(ops[1])}; /* rcpss */"]
        if m in ("minss", "maxss") and nops >= 2 and is_xmm(ops[0]):
            a, b = f"{ops[0].reg}.f[0]", rd_ss(ops[1])
            cmp = "<" if m == "minss" else ">"
            return [f"{{ float _b = {b}; {a} = ({a} {cmp} _b) ? {a} : _b; }} /* {m} */"]

        # -- packed arithmetic / bitwise / compares / shuffles --
        pk = {"addps": "xmm_addps", "subps": "xmm_subps", "mulps": "xmm_mulps",
              "divps": "xmm_divps", "minps": "xmm_minps", "maxps": "xmm_maxps",
              "andps": "xmm_andps", "andnps": "xmm_andnps", "orps": "xmm_orps",
              "xorps": "xmm_xorps",
              "cmpeqps": "xmm_cmpeqps", "cmpneqps": "xmm_cmpneqps",
              "cmpltps": "xmm_cmpltps", "cmpleps": "xmm_cmpleps",
              "unpcklps": "xmm_unpcklps", "unpckhps": "xmm_unpckhps"}
        if m in pk and nops >= 2 and is_xmm(ops[0]):
            if m == "xorps" and is_xmm(ops[1]) and ops[0].reg == ops[1].reg:
                return [f"{ops[0].reg} = xmm_zero(); /* xorps self */"]
            return [f"{ops[0].reg} = {pk[m]}({ops[0].reg}, {rd(ops[1])}); /* {m} */"]
        if m in ("sqrtps", "rsqrtps", "rcpps") and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg} = xmm_{m}({rd(ops[1])}); /* {m} */"]
        if m == "shufps" and nops >= 3 and is_xmm(ops[0]):
            return [f"{ops[0].reg} = xmm_shufps({ops[0].reg}, {rd(ops[1])}, {_fmt_imm(ops[2].imm)}); /* shufps */"]
        if m == "movmskps" and nops >= 2 and is_xmm(ops[1]):
            return [_fmt_operand_write(ops[0], f"xmm_movmskps({ops[1].reg})") + " /* movmskps */"]

        # -- conversions --
        if m == "cvtsi2ss" and nops >= 2 and is_xmm(ops[0]):
            return [f"{ops[0].reg}.f[0] = (float)(int32_t){_fmt_operand_read(ops[1])}; /* cvtsi2ss */"]
        if m in ("cvtss2si", "cvttss2si") and nops >= 2:
            fn = "(int32_t)rintf" if m == "cvtss2si" else "(int32_t)"
            return [_fmt_operand_write(ops[0], f"{fn}({rd_ss(ops[1])})") + f" /* {m} */"]
        if m in ("cvtsi2sd", "cvtsd2si", "cvttsd2si", "cvtss2sd", "cvtsd2ss",
                 "addsd", "subsd", "mulsd", "divsd", "sqrtsd", "minsd", "maxsd",
                 "comisd", "ucomisd"):
            return [f"/* TODO SSE2 double: {m} {insn.op_str} */"]

        # -- scalar compare -> _fpu_cmp, consumed by the following jcc --
        if m in ("comiss", "ucomiss") and nops >= 2:
            a, b = rd_ss(ops[0]), rd_ss(ops[1])
            return [f"_fpu_cmp = ({a} < {b}) ? -1 : ({a} > {b}) ? 1 : 0; /* {m} */"]

        # -- integer SIMD on xmm (unused by this image) --
        if m in ("pand", "pandn", "por", "pxor", "pcmpgtd"):
            return [f"/* TODO: {m} {insn.op_str} (integer SIMD on xmm) */"]

        return [f"/* TODO SSE: {m} {insn.op_str} */"]

    # ── FPU (x87) ──

    def _lift_fpu(self, insn, m, ops):
        """Basic FPU instruction translation using double locals."""
        # FPU is complex. We translate common patterns to double operations.
        # Full accuracy would require an x87 stack emulator.

        if m == "fld":
            if len(ops) >= 1:
                if ops[0].type == "mem":
                    if ops[0].mem_size == 4:
                        return [f"fp_push(MEMF({_fmt_mem(ops[0])})); /* fld float */"]
                    elif ops[0].mem_size == 8:
                        return [f"fp_push(MEMD({_fmt_mem(ops[0])})); /* fld double */"]
                    return [f"fp_push(MEMF({_fmt_mem(ops[0])})); /* fld */"]
                if ops[0].type == "reg" and ops[0].reg.startswith("st"):
                    # fld st(i): push a copy of stack[i]. Pre-read to avoid
                    # unsequenced g_fp_top access inside the push macro.
                    i = _st_index(ops[0].reg)
                    return [f"{{ double _t = g_fp_stack[(g_fp_top + {i}) & 7]; fp_push(_t); }} /* fld st({i}) */"]
            return [f"/* fld {insn.op_str} */"]

        if m in ("fst", "fstp"):
            # fst stores WITHOUT popping; only fstp pops (the old lift popped
            # for both — recomp bug #12).
            popstmt = " fp_popp();" if m == "fstp" else ""
            if len(ops) >= 1 and ops[0].type == "mem":
                if ops[0].mem_size == 4:
                    return [f"MEMF({_fmt_mem(ops[0])}) = (float)fp_top();{popstmt} /* {m} */"]
                elif ops[0].mem_size == 8:
                    return [f"MEMD({_fmt_mem(ops[0])}) = fp_top();{popstmt} /* {m} */"]
            if len(ops) >= 1 and ops[0].type == "reg" and ops[0].reg.startswith("st"):
                i = _st_index(ops[0].reg)
                if m == "fstp" and i == 0:
                    return ["fp_popp(); /* fstp st(0) = pop */"]
                return [f"g_fp_stack[(g_fp_top + {i}) & 7] = fp_top();{popstmt} /* {m} st({i}) */"]
            return [f"/* {m} {insn.op_str} */"]

        if m == "fild":
            if len(ops) >= 1 and ops[0].type == "mem":
                smem = _smem_accessor(ops[0].mem_size)
                return [f"fp_push((double){smem}({_fmt_mem(ops[0])})); /* fild */"]
            return [f"/* fild {insn.op_str} */"]

        if m in ("fist", "fistp"):
            popstmt = " fp_popp();" if m == "fistp" else ""
            if len(ops) >= 1 and ops[0].type == "mem":
                mem_acc = _mem_accessor(ops[0].mem_size)
                return [f"{mem_acc}({_fmt_mem(ops[0])}) = (int32_t)fp_top();{popstmt} /* {m} */"]
            return [f"/* {m} {insn.op_str} */"]

        # ── x87 arithmetic (recomp bug #13) ──
        # The old lift emitted the bare pop-pair form ("st1 OP= st0; pop")
        # for EVERY fadd/fsub/fmul/fdiv, dropping memory operands (st0 was
        # multiplied into stale stack garbage and popped) and register
        # destinations; the fi* integer and *r reversed variants fell
        # through to comments and were dropped entirely.
        _am = _ARITH_RE.match(m)
        if _am:
            is_int = _am.group(1) == "i"
            sym = {"add": "+", "sub": "-", "mul": "*", "div": "/"}[_am.group(2)]
            is_rev = _am.group(3) == "r"
            is_pop = _am.group(4) == "p"

            def _st_lv(i):
                return "fp_top()" if i == 0 else f"g_fp_stack[(g_fp_top + {i}) & 7]"

            if len(ops) >= 1 and ops[0].type == "mem":
                # OP m32/m64 (or fiOP m16/m32): st0 = st0 OP mem, never pops
                if is_int:
                    src = f"(double){_smem_accessor(ops[0].mem_size)}({_fmt_mem(ops[0])})"
                else:
                    acc = "MEMD" if ops[0].mem_size == 8 else "MEMF"
                    src = f"(double){acc}({_fmt_mem(ops[0])})"
                if is_rev:
                    return [f"fp_top() = {src} {sym} fp_top(); /* {m} mem */"]
                return [f"fp_top() = fp_top() {sym} {src}; /* {m} mem */"]

            if len(ops) >= 2 and ops[0].type == "reg" and ops[1].type == "reg":
                di, si = _st_index(ops[0].reg), _st_index(ops[1].reg)
            elif len(ops) == 1 and ops[0].type == "reg":
                # one visible operand: "OP st(i)" is st0 = st0 OP st(i)
                # (D8 form); "OPp st(i)" is st(i) = st(i) OP st0 then pop
                i = _st_index(ops[0].reg)
                di, si = (i, 0) if is_pop else (0, i)
            else:
                di, si = (1, 0)  # bare OPp == OPp st(1), st0
            dst, src = _st_lv(di), _st_lv(si)
            if is_rev:
                stmt = f"{dst} = {src} {sym} {dst};"
            else:
                stmt = f"{dst} = {dst} {sym} {src};"
            if is_pop:
                stmt += " fp_pop();"
            return [stmt + f" /* {m} {insn.op_str} */"]
        if m == "fchs":
            return [f"fp_top() = -fp_top(); /* fchs */"]
        if m == "fabs":
            return [f"fp_top() = fabs(fp_top()); /* fabs */"]
        if m == "fsqrt":
            return [f"fp_top() = sqrt(fp_top()); /* fsqrt */"]

        # RECOMP BUG #18: the x87 transcendentals were never lifted -- they
        # fell through to the bare-comment fallback and were dropped, so every
        # tan/atan/sin/cos/pow/exp/log the game computes returned whatever was
        # already on the FPU stack. D3D_UpdateProjectionViewportTransform's
        # projection reached the composite multiply with inf in m00/m11
        # (1 / tan(fov/2) where the tan never happened), which turned the
        # whole composite matrix into 0xFFC00000 and put every post-movie
        # vertex at NaN.
        if m == "fsin":
            return ["fp_top() = sin(fp_top()); /* fsin */"]
        if m == "fcos":
            return ["fp_top() = cos(fp_top()); /* fcos */"]
        if m == "fsincos":
            # ST(0) = sin(x), then push cos(x): ST(1)=sin, ST(0)=cos.
            return ["{ double _x = fp_top(); fp_top() = sin(_x); fp_push(cos(_x)); }"
                    " /* fsincos */"]
        if m == "fptan":
            # ST(0) = tan(x), then push 1.0: ST(1)=tan, ST(0)=1.0.
            return ["{ fp_top() = tan(fp_top()); fp_push(1.0); } /* fptan */"]
        if m == "fpatan":
            # ST(1) = atan2(ST(1), ST(0)), then pop.
            return ["fp_st1() = atan2(fp_st1(), fp_top()); fp_pop(); /* fpatan */"]
        if m == "f2xm1":
            return ["fp_top() = pow(2.0, fp_top()) - 1.0; /* f2xm1 */"]
        if m == "fyl2x":
            return ["fp_st1() = fp_st1() * (log(fp_top()) / 0.69314718055994531);"
                    " fp_pop(); /* fyl2x */"]
        if m == "fyl2xp1":
            return ["fp_st1() = fp_st1() * (log(fp_top() + 1.0) / 0.69314718055994531);"
                    " fp_pop(); /* fyl2xp1 */"]
        if m == "fscale":
            # ST(0) *= 2^trunc(ST(1)); ST(1) is left in place.
            return ["fp_top() = fp_top() * pow(2.0, (double)(int)fp_st1()); /* fscale */"]
        if m == "frndint":
            # Round to integer in the CURRENT x87 rounding mode (RC bits of
            # the control word). The CRT's floor/ceil set RC=down/up with
            # fldcw around frndint; rint() (nearest) made floor(12.7)==13,
            # which flagged "inexact" and sent floor down its exception path.
            return ["fp_top() = x87_frndint(fp_top()); /* frndint */"]
        if m == "fprem":
            # Truncating partial remainder (C2 is reported complete).
            return ["fp_top() = fmod(fp_top(), fp_st1()); /* fprem */"]
        if m == "fprem1":
            return ["fp_top() = remainder(fp_top(), fp_st1()); /* fprem1 */"]
        if m == "fldpi":
            return ["fp_push(3.14159265358979323846); /* fldpi */"]
        if m == "fldl2e":
            return ["fp_push(1.44269504088896340736); /* fldl2e */"]
        if m == "fldl2t":
            return ["fp_push(3.32192809488736234787); /* fldl2t */"]
        if m == "fldlg2":
            return ["fp_push(0.30102999566398119521); /* fldlg2 */"]
        if m == "fldln2":
            return ["fp_push(0.69314718055994530942); /* fldln2 */"]
        if m == "ftst":
            return ["_fpu_cmp = (fp_top() < 0.0) ? -1 : (fp_top() > 0.0) ? 1 : 0;"
                    " /* ftst */"]
        if m == "fisttp":
            if len(ops) >= 1 and ops[0].type == "mem":
                mem_acc = _mem_accessor(ops[0].mem_size)
                return [f"{mem_acc}({_fmt_mem(ops[0])}) = (int32_t)fp_top(); fp_popp();"
                        f" /* fisttp */"]
            return ["fp_popp(); /* fisttp */"]
        if m == "fincstp":
            return ["fp_pop(); /* fincstp */"]
        if m == "fdecstp":
            return ["g_fp_top--; /* fdecstp */"]
        if m == "fxch":
            # RECOMP BUG #17: capstone reports fxch -- alone among the x87
            # ops -- in its two-operand form "fxch st(0), st(i)", so reading
            # ops[0] always yielded st(0) and every fxch became a no-op.
            # `fxch st(2)` in D3D_UpdateProjectionViewportTransform's tail
            # (0x001B60B1) is what rotated the viewport matrix's diagonal:
            # the device got m00=1, m11=halfwidth, m33=-halfheight instead of
            # halfwidth/-halfheight/1, so the composite matrix was wrong and
            # every post-movie vertex landed off screen. The index lives in
            # the last st operand; a bare fxch means st(1).
            i = 1
            for _o in ops:
                if _o.type == "reg" and _o.reg.startswith("st"):
                    i = _st_index(_o.reg)
            return [f"{{ double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + {i}) & 7]; g_fp_stack[(g_fp_top + {i}) & 7] = _t; }} /* fxch st({i}) */"]
        if m in ("fcom", "fcomp", "fcompp", "fucom", "fucomp", "fucompp"):
            # Set _fpu_cmp for the fcomp/fnstsw/sahf pattern.
            # Compare st(0) against the REAL operand: a memory float/double or
            # st(i) (recomp bug #9: this used to always compare st0 vs st1 and
            # never popped, so every float comparison against memory was wrong).
            rhs = "fp_st1()"
            ops_str = insn.op_str or ""
            # RECOMP BUG #19: a register operand other than st(1) (fcomp st(2)
            # in the walker's visibility test 0x00155F8D) was compared against
            # st(1); use the real stack slot.
            for _o in ops:
                if _o.type == "reg" and _o.reg.startswith("st"):
                    _i = _st_index(_o.reg)
                    if _i != 1:
                        rhs = f"g_fp_stack[(g_fp_top + {_i}) & 7]"
            if "dword ptr" in ops_str or "qword ptr" in ops_str:
                mem = _fmt_operand_read(ops[0]) if ops else None
                if mem:
                    # MEM32 -> float load, adjust macro by width
                    if "dword ptr" in ops_str:
                        rhs = mem.replace("MEM32", "MEMF").replace("SMEM32", "MEMF")
                        rhs = f"(double){rhs}"
                    else:
                        rhs = mem.replace("MEM32", "MEMD").replace("SMEM32", "MEMD")
            pops = ""
            if m in ("fcomp", "fucomp"):
                pops = " fp_popp();"
            elif m in ("fcompp", "fucompp"):
                pops = " fp_popp(); fp_popp();"
            return [f"_fpu_cmp = (fp_top() < {rhs}) ? -1 : (fp_top() > {rhs}) ? 1 : 0;"
                    f"{pops} /* {m} {insn.op_str} */"]
        if m in ("fcompi", "fcomip", "fucomi", "fucompi", "fucomip", "fcomi"):
            # These set EFLAGS directly (CF, ZF, PF) from FPU comparison
            # fcompi/fucompi pop st(0) after comparing; fcomi/fucomi do not
            pops = m.endswith("pi") or m.endswith("ip")
            pop_code = " fp_pop();" if pops else ""
            return [f"_fpu_cmp = (fp_top() < fp_st1()) ? -1 : (fp_top() > fp_st1()) ? 1 : 0;"
                    f"{pop_code} /* {m} */"]
        if m == "fnstsw":
            # Store the FPU status word: AH gets C0(0x01)/C2(0x04)/C3(0x40).
            # From _fpu_cmp: less -> C0, equal -> C3, greater -> none.
            # (bug #9: this was a comment only — the following `test ah, X;
            # jcc` read whatever happened to be in eax.)
            if (insn.op_str or "").strip() == "ax":
                return [f"SET_HI8(eax, (_fpu_cmp < 0 ? 0x01 : 0) | (_fpu_cmp == 0 ? 0x40 : 0)); /* fnstsw ax */"]
            return [f"/* fnstsw {insn.op_str} - store FPU status word */"]
        if m == "fnstcw":
            # The control word is real state: the CRT's _ctrlfp reads it back
            # to decide which FP exceptions are masked. Left untranslated it
            # read stack garbage and floor() raised STATUS_FLOAT_INEXACT.
            if ops and ops[0].type == "mem":
                return [f"MEM16({_fmt_mem(ops[0])}) = g_x87_cw; /* fnstcw */"]
            return [f"/* fnstcw {insn.op_str} - store FPU control word */"]
        if m == "fldcw":
            if ops and ops[0].type == "mem":
                return [f"g_x87_cw = MEM16({_fmt_mem(ops[0])}); /* fldcw */"]
            return [f"/* fldcw {insn.op_str} - load FPU control word */"]
        if m == "fldz":
            return [f"fp_push(0.0); /* fldz */"]
        if m == "fld1":
            return [f"fp_push(1.0); /* fld1 */"]

        return [f"/* FPU: {m} {insn.op_str} */"]


def lift_basic_block(lifter, bb, flag_state=None):
    """
    Lift a basic block to C statements.
    Tracks flags to generate proper conditions for jcc/setcc/cmovcc.

    Args:
        lifter: Lifter instance
        bb: BasicBlock with instructions
        flag_state: tuple of (flag_setter_mnemonic, flag_operands) from
                    a preceding block, or None

    Returns:
        (stmts, flag_state) where stmts is a list of C statement strings
        and flag_state is a tuple for passing to the next block.
    """
    stmts = []
    insns = bb.instructions
    i = 0

    # Track the last instruction that set flags
    if flag_state:
        last_flag_setter, last_flag_ops = flag_state
    else:
        last_flag_setter = None
        last_flag_ops = []

    while i < len(insns):
        curr = insns[i]

        # Try cmp/test + jcc pattern first (2-instruction match)
        match = try_match_cmp_jcc(insns, i, lifter=lifter)
        if match:
            stmt, consumed = match
            stmts.append(stmt)
            # Preserve the flag-setter from the cmp/test since jcc
            # doesn't modify flags - subsequent jcc can reuse them
            flag_insn = insns[i]
            last_flag_setter = flag_insn.mnemonic
            last_flag_ops = list(flag_insn.operands)
            i += consumed
            continue

        # Handle jecxz/jcxz specially (not flag-based)
        if curr.mnemonic in ("jecxz", "jcxz"):
            results = lifter._lift_jcc(curr)
            stmts.extend(results)
            i += 1
            continue

        # Check if this instruction uses flags (jcc, setcc, cmovcc)
        if curr.is_cond_jump and last_flag_setter:
            result = _make_condition(
                curr.mnemonic, last_flag_setter, last_flag_ops)
            if result:
                cond_expr, desc = result
                target = curr.jump_target
                stmt = _emit_cond_goto(
                    cond_expr, curr.mnemonic, desc, target, lifter)
                stmts.append(stmt)
                i += 1
                continue

        if (curr.mnemonic in ("sete", "setne", "setb", "setae", "setbe",
                              "seta", "setl", "setge", "setle", "setg",
                              "sets", "setns")
                and last_flag_setter and len(curr.operands) >= 1):
            cond = _make_setcc_value(
                curr.mnemonic, last_flag_setter, last_flag_ops)
            if cond:
                stmts.append(
                    _fmt_operand_write(curr.operands[0],
                                       f"({cond}) ? 1 : 0")
                    + f" /* {curr.mnemonic} */")
                i += 1
                continue

        if (curr.mnemonic in ("cmove", "cmovne", "cmovb", "cmovae",
                              "cmovbe", "cmova", "cmovl", "cmovge",
                              "cmovle", "cmovg", "cmovs", "cmovns")
                and last_flag_setter and len(curr.operands) >= 2):
            cond = _make_cmovcc_cond(
                curr.mnemonic, last_flag_setter, last_flag_ops)
            if cond:
                src = _fmt_operand_read(curr.operands[1])
                stmts.append(
                    f"if ({cond}) "
                    + _fmt_operand_write(curr.operands[0], src)
                    + f" /* {curr.mnemonic} */")
                i += 1
                continue

        # Materialize the carry flag for sbb/adc (recomp bug #10: _cf was
        # declared but never produced, so every borrow/carry and every
        # neg/sbb/cmp+sbb boolean idiom computed with CF=0).
        if curr.mnemonic in ("sbb", "adc") and last_flag_setter:
            cf_expr = _make_cf_expr(last_flag_setter, last_flag_ops)
            if cf_expr is not None:
                stmts.append(f"_cf = {cf_expr}; /* CF from {last_flag_setter} */")

        # Lift the instruction normally
        results = lifter.lift_instruction(insns[i])
        stmts.extend(results)

        # Track flag-setting instructions
        if curr.mnemonic in FLAG_SETTERS:
            last_flag_setter = curr.mnemonic
            last_flag_ops = list(curr.operands)
        elif curr.mnemonic in _FLAGS_UNDEFINED:
            # Flags are undefined after these - clear tracking
            last_flag_setter = None
            last_flag_ops = []
        elif curr.mnemonic in _EFLAGS_SETTERS:
            # Additional flag-setting instructions
            last_flag_setter = curr.mnemonic
            last_flag_ops = list(curr.operands)
        elif curr.mnemonic in _EFLAGS_PRESERVE:
            pass  # These don't affect EFLAGS
        elif curr.mnemonic in ("fcompi", "fcomip", "fucomi", "fucompi",
                                "fucomip", "fcomi"):
            # FPU compare-to-EFLAGS: sets CF, ZF, PF directly
            last_flag_setter = curr.mnemonic
            last_flag_ops = list(curr.operands)
        elif curr.mnemonic == "sahf":
            # sahf loads AH into flags - typically after fnstsw ax
            # in the fcomp/fnstsw/sahf pattern for FPU comparisons
            last_flag_setter = "sahf"
            last_flag_ops = list(curr.operands)
        elif curr.mnemonic.startswith("f") or curr.mnemonic.startswith("cmov"):
            pass  # FPU and already-handled CMOVcc
        elif curr.mnemonic.startswith("j"):
            pass  # Jumps don't set flags
        elif curr.mnemonic.startswith("set"):
            pass  # SETcc doesn't set flags
        elif curr.mnemonic.startswith("rep"):
            # rep movsb/movsd = data copy, preserves flags
            # repe cmpsb/repne scasb = comparison, sets flags
            rest = curr.op_str.strip() if hasattr(curr, 'op_str') else ""
            raw_m = curr.mnemonic
            if "cmps" in raw_m or "scas" in raw_m:
                last_flag_setter = raw_m
                last_flag_ops = list(curr.operands)
            elif "cmps" in rest or "scas" in rest:
                last_flag_setter = raw_m
                last_flag_ops = list(curr.operands)
            else:
                pass  # rep movs/stos = data movement, flags preserved
        else:
            # Unknown instruction - conservatively clear flag state
            last_flag_setter = None
            last_flag_ops = []

        i += 1

    out_flag_state = (last_flag_setter, last_flag_ops) if last_flag_setter else None
    return stmts, out_flag_state
