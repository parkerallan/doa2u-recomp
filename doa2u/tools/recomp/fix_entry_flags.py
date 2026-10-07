#!/usr/bin/env python3
"""
Re-evaluate a split function's entry branch on its predecessor's cmp/test (the lifter left `_flags`).
Rewrites only when every way in provably shares one register/immediate compare. FIX_DRYRUN=1 reports.
"""
import glob
import os
import re

GEN_DIR = os.path.join("src", "game", "recomp", "gen")
ASM_DIR = os.path.join("tools", "disasm", "output", "asm")

INSN = re.compile(r'^\s+0x([0-9A-Fa-f]{8})\s+([0-9a-fA-F]+)\s+(\S+)\s*(.*?)\s*$')
FUNC = re.compile(r'^void (sub_([0-9A-F]{8}))(?:_gen)?\(void\)$')
ENTRY_IF = re.compile(r'^(\s*)if \(_flags /\* (j[a-z]+)\b[^*]*\*/\)(.*)$')

FLAG_WRITERS = {
    "add", "sub", "adc", "sbb", "and", "or", "xor", "cmp", "test", "inc", "dec",
    "neg", "shl", "shr", "sar", "sal", "rol", "ror", "rcl", "rcr", "shld", "shrd",
    "mul", "imul", "div", "idiv", "bt", "bts", "btr", "btc", "bsf", "bsr",
    "xadd", "cmpxchg", "sahf", "popf", "popfd", "cmpsb", "cmpsw", "cmpsd",
    "scasb", "scasw", "scasd", "comiss", "ucomiss", "comisd", "ucomisd",
    "clc", "stc", "cmc",
}
UNCOND = {"jmp", "ret", "retn", "iret", "int3", "hlt", "ud2"}

REG32 = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"}
REG8 = {"al": "LO8(eax)", "ah": "HI8(eax)", "bl": "LO8(ebx)", "bh": "HI8(ebx)",
        "cl": "LO8(ecx)", "ch": "HI8(ecx)", "dl": "LO8(edx)", "dh": "HI8(edx)"}
REG16 = {"ax": "LO16(eax)", "bx": "LO16(ebx)", "cx": "LO16(ecx)", "dx": "LO16(edx)",
         "si": "LO16(esi)", "di": "LO16(edi)", "bp": "LO16(ebp)", "sp": "LO16(esp)"}
FULL = {r: r for r in REG32}
for k in REG8: FULL[k] = "e" + k[0] + "x"
for k in REG16: FULL[k] = ("e" + k) if k in ("si", "di", "bp", "sp") else ("e" + k[0] + "x")
IMM = re.compile(r'^(?:0x[0-9a-fA-F]+|\d+)$')


def c_operand(op):
    op = op.strip()
    if op in REG32:
        return op
    if op in REG8:
        return REG8[op]
    if op in REG16:
        return REG16[op]
    if IMM.match(op):
        v = int(op, 0) & 0xFFFFFFFF
        return "0x%Xu" % v
    return None


def cond_for(jcc, mnem, a, b):
    if mnem == "test":
        t = {"je": "TEST_Z(%s, %s)", "jz": "TEST_Z(%s, %s)",
             "jne": "TEST_NZ(%s, %s)", "jnz": "TEST_NZ(%s, %s)",
             "js": "TEST_S(%s, %s)", "jns": "!TEST_S(%s, %s)",
             "jl": "TEST_S(%s, %s)", "jge": "!TEST_S(%s, %s)",
             "jg": "(TEST_NZ(%s, %s) && !TEST_S(%s, %s))",
             "jle": "(TEST_Z(%s, %s) || TEST_S(%s, %s))",
             "ja": "TEST_NZ(%s, %s)", "jbe": "TEST_Z(%s, %s)"}
        f = t.get(jcc)
        return f % tuple([a, b] * (f.count("%s") // 2)) if f else None
    if mnem == "cmp":
        t = {"je": "CMP_EQ", "jz": "CMP_EQ", "jne": "CMP_NE", "jnz": "CMP_NE",
             "jb": "CMP_B", "jc": "CMP_B", "jnae": "CMP_B", "jae": "CMP_AE", "jnc": "CMP_AE",
             "jnb": "CMP_AE", "jbe": "CMP_BE", "jna": "CMP_BE", "ja": "CMP_A", "jnbe": "CMP_A",
             "jl": "CMP_L", "jnge": "CMP_L", "jge": "CMP_GE", "jnl": "CMP_GE",
             "jle": "CMP_LE", "jng": "CMP_LE", "jg": "CMP_G", "jnle": "CMP_G"}
        m = t.get(jcc)
        return "%s(%s, %s)" % (m, a, b) if m else None
    return None


def load_asm():
    insns = []
    for path in glob.glob(os.path.join(ASM_DIR, "*.asm")):
        for line in open(path, encoding="utf-8", errors="ignore"):
            m = INSN.match(line)
            if m:
                addr = int(m.group(1), 16)
                size = len(m.group(2)) // 2
                mnem = m.group(3).lower()
                ops = m.group(4).split(";")[0].strip().lower()
                insns.append((addr, size, mnem, ops))
    insns.sort()
    return insns


def written_regs(mnem, ops):
    """Full registers an instruction may write (conservative)."""
    if mnem in ("cmp", "test", "push") or mnem.startswith("j"):
        return set()
    if mnem in ("call",):
        return set(REG32)
    parts = [p.strip() for p in ops.split(",")] if ops else []
    out = set()
    if parts and parts[0] in FULL:
        out.add(FULL[parts[0]])
    if mnem in ("pop",) and parts and parts[0] in FULL:
        out.add(FULL[parts[0]])
    if mnem in ("xchg", "xadd", "cmpxchg") and len(parts) > 1 and parts[1] in FULL:
        out.add(FULL[parts[1]])
    if mnem in ("mul", "imul", "div", "idiv", "cdq", "cwd", "cbw", "cwde", "lodsb", "lodsd",
                "stosb", "stosd", "movsb", "movsd", "rep", "cpuid", "rdtsc"):
        out |= {"eax", "edx", "ecx", "esi", "edi"}
    return out


def main():
    dry = os.environ.get("FIX_DRYRUN") == "1"
    insns = load_asm()
    idx = {a: i for i, (a, _, _, _) in enumerate(insns)}
    targets = {}
    for i, (a, sz, mn, ops) in enumerate(insns):
        if mn.startswith("j"):
            m = re.match(r'^(0x[0-9a-f]+)$', ops)
            if m:
                targets.setdefault(int(m.group(1), 16), []).append(i)

    def setter_before(i):
        """Walk back from instruction index i (exclusive) to the flag setter."""
        written = set()
        j = i - 1
        while j >= 0 and i - j < 64:
            a, sz, mn, ops = insns[j]
            if mn in FLAG_WRITERS:
                if mn not in ("cmp", "test"):
                    return None
                parts = [p.strip() for p in ops.split(",")]
                if len(parts) != 2:
                    return None
                ca, cb = c_operand(parts[0]), c_operand(parts[1])
                if ca is None or cb is None:
                    return None
                for p in parts:
                    if p in FULL and FULL[p] in written:
                        return None
                return (mn, parts[0], parts[1], a, ca, cb)
            if mn == "call" or mn in UNCOND:
                return None
            # a branch target between setter and use means another path
            if a in targets and j < i - 1:
                return None
            written |= written_regs(mn, ops)
            j -= 1
        return None

    fixed = skipped = 0
    for path in sorted(glob.glob(os.path.join(GEN_DIR, "recomp_*.c"))):
        if path.endswith("recomp_dispatch.c"):
            continue
        lines = open(path, encoding="utf-8", errors="surrogateescape").read().split("\n")
        changed = False
        for k, line in enumerate(lines):
            fm = FUNC.match(line)
            if not fm:
                continue
            A = int(fm.group(2), 16)
            # first statement after the entry label
            e = None
            for q in range(k + 1, min(k + 12, len(lines))):
                if lines[q].startswith("loc_%08X: ;" % A):
                    e = q + 1
                    break
            if e is None or e >= len(lines):
                continue
            mi = ENTRY_IF.match(lines[e])
            if not mi:
                continue
            jcc = mi.group(2)
            if A not in idx:
                print("[entry-flags] %s: not in disassembly, left" % fm.group(1)); skipped += 1
                continue
            ia = idx[A]
            preds = list(targets.get(A, []))
            pa, psz, pmn, _ = insns[ia - 1] if ia > 0 else (0, 0, "", "")
            if ia > 0 and pa + psz == A and pmn not in UNCOND:
                preds.append(ia)   # fall-through: setter search starts before A
            setters = set()
            ok = bool(preds)
            for p in preds:
                # p indexes the branch into A, or A itself for the fall-through;
                # either way the setter is searched in the instructions before p
                s = setter_before(p)
                if s is None:
                    ok = False
                    break
                setters.add(s[:3] + s[4:])
            if not ok or len(setters) != 1:
                print("[entry-flags] %s %s: predecessors not provable, left" % (fm.group(1), jcc))
                skipped += 1
                continue
            mn, oa, ob, ca, cb = next(iter(setters))
            cond = cond_for(jcc, mn, ca, cb)
            if not cond:
                print("[entry-flags] %s: no mapping for %s after %s, left" % (fm.group(1), jcc, mn))
                skipped += 1
                continue
            lines[e] = "%sif (%s /* %s: flags of `%s %s, %s` before the split (entry-flags) */)%s" % (
                mi.group(1), cond, jcc, mn, oa, ob, mi.group(3))
            changed = True
            fixed += 1
            print("[entry-flags] %s: %s <- %s %s, %s" % (fm.group(1), jcc, mn, oa, ob))
        if changed and not dry:
            open(path, "w", encoding="utf-8", errors="surrogateescape", newline="\n").write("\n".join(lines))
    print("entry-flags: %d rewritten, %d left%s" % (fixed, skipped, " (dry run)" if dry else ""))


if __name__ == "__main__":
    main()
