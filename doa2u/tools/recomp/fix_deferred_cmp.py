#!/usr/bin/env python3
"""
Evaluate a deferred cmp/test at the compare when its operands are overwritten
before the branch that consumes its flags.

The lifter emits `cmp`/`test` as a comment and re-evaluates the operand
EXPRESSIONS at the conditional branch:

    /* test LO8(edx), LO8(edx) - flags set for next jcc */
    SET_LO8(edx, MEM8(esp + 0x10));                     <-- dl overwritten
    if (TEST_NZ(LO8(edx), LO8(edx))) goto loc_X;        <-- tests the NEW dl

x86 latched the flags at the `test`, so the branch must test the value the
operands had THERE. This tool rewrites such a site to

    /* test LO8(edx), LO8(edx) - flags set for next jcc */
    _rccf = (TEST_NZ(LO8(edx), LO8(edx)));  /* DOA3: ... */
    SET_LO8(edx, MEM8(esp + 0x10));
    if (_rccf) goto loc_X;

which is the `_rcc` form the pipeline already uses for the address-register
variant of the same bug.

Nothing is rewritten on the strength of the C text alone. A candidate is kept
only when the guest disassembly agrees, and the mapping from C to guest has to
be unambiguous:

  * the comment and the branch must be in the same straight-line run of one
    generated block -- the scan stops at a `loc_` label, a bare `goto`, a
    `return` and at the next compare comment, because past any of those the
    branch may be reached with different flags;
  * that block must hold exactly one candidate in the C and exactly one
    qualifying compare in the guest, so there is only one way to pair them;
  * the guest compare must be the same kind (cmp vs test), carry the same
    literal operand when there is one, reach its branch with no other
    flag-writing instruction, no `call` and no branch target in between, and
    really have one of its operand registers overwritten on the way.

usage (from doa3/):
    py -3 -m tools.recomp.fix_deferred_cmp                 # rewrite
    FIX_DRYRUN=1 py -3 -m tools.recomp.fix_deferred_cmp    # report only
"""
import glob
import os
import re

GEN_DIR = os.path.join("src", "game", "recomp", "gen")
ASM_DIR = os.path.join("tools", "disasm", "output", "asm")

CMT = re.compile(r'/\* (cmp|test) (.+?) - flags set for next jcc \*/')
CONS = re.compile(r'(CMP_[A-Z]+|TEST_[A-Z]+)\s*\(')
LABEL = re.compile(r'^loc_([0-9A-Fa-f]{8}):')
FUNC = re.compile(r'^void (sub_[0-9A-Fa-f]{8}\w*)\(void\)')
REGS = ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp")
LITERAL = re.compile(r'^(?:0[xX][0-9A-Fa-f]+u?|\d+)$')

# Instructions that write EFLAGS. One of these between the compare and the
# branch means the branch is not reading the compare's flags.
FLAG_WRITERS = {
    "add", "sub", "adc", "sbb", "and", "or", "xor", "cmp", "test", "inc", "dec",
    "neg", "shl", "shr", "sar", "sal", "rol", "ror", "rcl", "rcr", "shld", "shrd",
    "mul", "imul", "div", "idiv", "bt", "bts", "btr", "btc", "bsf", "bsr",
    "xadd", "cmpxchg", "sahf", "popf", "popfd", "cmps", "cmpsb", "cmpsw", "cmpsd",
    "scas", "scasb", "scasw", "scasd", "aaa", "aad", "aam", "aas", "daa", "das",
    "comiss", "ucomiss", "comisd", "ucomisd", "clc", "stc", "cmc", "std", "cld",
    "lock",
}

# Which bytes of the 32-bit register a name touches (bit 0 = low byte).
SUBREG = {
    "al": ("eax", 0b0001), "ah": ("eax", 0b0010), "ax": ("eax", 0b0011), "eax": ("eax", 0b1111),
    "bl": ("ebx", 0b0001), "bh": ("ebx", 0b0010), "bx": ("ebx", 0b0011), "ebx": ("ebx", 0b1111),
    "cl": ("ecx", 0b0001), "ch": ("ecx", 0b0010), "cx": ("ecx", 0b0011), "ecx": ("ecx", 0b1111),
    "dl": ("edx", 0b0001), "dh": ("edx", 0b0010), "dx": ("edx", 0b0011), "edx": ("edx", 0b1111),
    "si": ("esi", 0b0011), "esi": ("esi", 0b1111),
    "di": ("edi", 0b0011), "edi": ("edi", 0b1111),
    "bp": ("ebp", 0b0011), "ebp": ("ebp", 0b1111),
    "sp": ("esp", 0b0011), "esp": ("esp", 0b1111),
}
REG_RE = re.compile(r'\b(e?[abcd]x|[abcd][lh]|e?(?:si|di|bp|sp))\b')
INSN = re.compile(r'^\s{2}0x([0-9A-Fa-f]{8})\s{2}[0-9a-fA-F]+\s+(\S+)\s*(.*?)\s*$')


def parse_asm():
    """address -> (mnemonic, operands); plus the addresses that are branch targets."""
    insns, labelled = {}, set()
    for path in glob.glob(os.path.join(ASM_DIR, "*.asm")):
        pending = False
        for line in open(path, encoding="utf-8", errors="replace"):
            stripped = line.strip()
            # the disassembler prints "; XREF: ..." on its own line above the
            # target instruction; a "name:" line marks an entry point
            if stripped.startswith("; XREF:") or \
               re.match(r'^(sub|loc)_[0-9A-Fa-f]{8}:', stripped):
                pending = True
                continue
            m = INSN.match(line)
            if m:
                a = int(m.group(1), 16)
                insns[a] = (m.group(2).lower(), m.group(3))
                if pending:
                    labelled.add(a)
                pending = False
    return insns, labelled


def reg_mask(optext):
    out = {}
    for m in REG_RE.finditer(optext):
        full, mask = SUBREG[m.group(1)]
        out[full] = out.get(full, 0) | mask
    return out


def writes_of(mnem, optext):
    out = {}
    if mnem == "push":
        return {"esp": 0b1111}
    if mnem == "pop":
        out["esp"] = 0b1111
        m = REG_RE.fullmatch(optext.split(",")[0].strip())
        if m:
            full, mask = SUBREG[m.group(1)]
            out[full] = out.get(full, 0) | mask
        return out
    if mnem.startswith(("mov", "lea", "cmov", "set", "xchg")):
        parts = [p.strip() for p in optext.split(",")]
        m = REG_RE.fullmatch(parts[0]) if parts else None
        if m:
            full, mask = SUBREG[m.group(1)]
            out[full] = out.get(full, 0) | (0b1111 if mnem in ("movzx", "movsx") else mask)
        if mnem == "xchg" and len(parts) > 1:
            m2 = REG_RE.fullmatch(parts[1])
            if m2:
                full, mask = SUBREG[m2.group(1)]
                out[full] = out.get(full, 0) | mask
        return out
    return out


def guest_sites(insns, labelled, start_va, end_va):
    """Qualifying compares in [start_va, end_va): the ones whose consuming
    branch really sees an overwritten operand. Returns a list of
    (kind, operand text, clobber description)."""
    addrs = sorted(a for a in insns if start_va <= a < end_va)
    found = []
    for i, a in enumerate(addrs):
        mnem, ops = insns[a]
        if mnem not in ("cmp", "test"):
            continue
        need = reg_mask(ops)
        if not need:
            continue
        clobber = None
        for k in range(i + 1, len(addrs)):
            b = addrs[k]
            bm, bops = insns[b]
            if b in labelled:
                break                                  # another path joins
            if bm == "call":
                break                                  # flags volatile
            is_consumer = (bm.startswith("j") and bm != "jmp") or \
                          bm.startswith(("set", "cmov"))
            if is_consumer:
                if clobber:
                    found.append((mnem, ops, clobber))
                break
            if bm in FLAG_WRITERS:
                break                                  # flags replaced
            w = writes_of(bm, bops)
            for r, mask in w.items():
                if need.get(r, 0) & mask:
                    clobber = "%s at 0x%08X overwrites %s" % (bm, b, r)
                    break
    return found


def split_ops(s):
    depth, out, cur = 0, [], ""
    for ch in s:
        if ch == "(":
            depth += 1
        if ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    out.append(cur.strip())
    return out


def regs_in(expr):
    return {r for r in REGS if re.search(r'\b%s\b' % r, expr)}


def c_writes_of(line):
    w = set()
    m = re.match(r'\s*(eax|ebx|ecx|edx|esi|edi|ebp|esp)\s*(?:[-+*|&^]|>>|<<)?=[^=]', line)
    if m:
        w.add(m.group(1))
    for m in re.finditer(r'SET_LO(?:8|16)\((\w+),', line):
        if m.group(1) in REGS:
            w.add(m.group(1))
    for m in re.finditer(r'POP32\(\s*(\w+)\s*,\s*(\w+)\s*\)', line):
        for g in (m.group(1), m.group(2)):
            if g in REGS:
                w.add(g)
    if "PUSH32(" in line:
        w.add("esp")
    if re.search(r'\b(sub_[0-9A-Fa-f]{6}\w*|xbox_\w+)\s*\(', line):
        w |= {"eax", "ecx", "edx"}
    return w


def run_ends(line):
    """True when the generated line ends the straight-line run: past it the
    next statement may be reached from somewhere else."""
    s = line.strip()
    if LABEL.match(s) or s in ("}", "};"):
        return True
    if s.startswith("goto ") or s.startswith("return"):
        return True
    if re.match(r'^\}\s*$', s):
        return True
    return False


def scan_file(path):
    """Candidates in one generated file, grouped by block."""
    lines = open(path, encoding="utf-8", errors="surrogateescape").read().split("\n")
    labels = [(i, int(m.group(1), 16)) for i, l in enumerate(lines)
              for m in [LABEL.match(l)] if m]
    end_of = {}
    for k, (i, a) in enumerate(labels):
        end_of[i] = labels[k + 1][1] if k + 1 < len(labels) else a + 0x800

    cands = []
    func_start, block = None, None
    for i, line in enumerate(lines):
        if FUNC.match(line):
            func_start, block = i, None
        m = LABEL.match(line)
        if m:
            block = (i, int(m.group(1), 16), end_of[i])
        mc = CMT.search(line)
        if not mc or block is None:
            continue
        cops = [o.strip() for o in split_ops(mc.group(2))]
        need = set()
        for o in cops:
            need |= regs_in(o)
        if not need:
            continue
        clob = False
        for j in range(i + 1, len(lines)):
            l2 = lines[j]
            mcons = CONS.search(l2)
            if mcons:
                tail = l2[mcons.start():]
                depth, end = 0, None
                for k, ch in enumerate(tail):
                    if ch == "(":
                        depth += 1
                    elif ch == ")":
                        depth -= 1
                        if depth == 0:
                            end = k + 1
                            break
                if end is None:
                    break
                cond = tail[:end]
                bops = [o.strip() for o in split_ops(cond[cond.index("(") + 1:-1])]
                if bops == cops and clob:
                    cands.append(dict(cmt=i, br=j, cond=cond, kind=mc.group(1),
                                      cops=cops, block=block, func=func_start))
                break
            if CMT.search(l2) or run_ends(l2):
                break
            if c_writes_of(l2) & need:
                clob = True
    return lines, cands


def main():
    dry = bool(os.environ.get("FIX_DRYRUN"))
    insns, labelled = parse_asm()
    print("guest: %d instructions, %d branch targets" % (len(insns), len(labelled)))

    kept = skipped = 0
    reasons = {}
    for path in sorted(glob.glob(os.path.join(GEN_DIR, "*.c"))):
        lines, cands = scan_file(path)
        if not cands:
            continue
        by_block = {}
        for c in cands:
            by_block.setdefault(c["block"][0], []).append(c)

        edits, funcs = [], set()
        for bi, group in by_block.items():
            def drop(why):
                global_reasons = reasons
                global_reasons[why] = global_reasons.get(why, 0) + len(group)
                if dry:
                    print("  SKIP %s:%d (%s)" % (os.path.basename(path),
                                                 group[0]["cmt"] + 1, why))
            if len(group) != 1:
                skipped += len(group)
                drop("%d candidates in one block" % len(group))
                continue
            c = group[0]
            g = guest_sites(insns, labelled, c["block"][1], c["block"][2])
            if len(g) != 1:
                skipped += 1
                drop("%d qualifying compares in the guest block" % len(g))
                continue
            kind, gops, why = g[0]
            if kind != c["kind"]:
                skipped += 1
                drop("guest has %s, C has %s" % (kind, c["kind"]))
                continue
            # when both sides end in a bare literal, it must be the same one
            gtail = [o.strip() for o in gops.split(",")][-1]
            ctail = c["cops"][-1]
            if LITERAL.match(gtail) and LITERAL.match(ctail):
                if int(gtail, 0) != int(ctail.rstrip("uU"), 0):
                    skipped += 1
                    drop("literal %s vs %s" % (gtail, ctail))
                    continue
            kept += 1
            edits.append(c)
            if c["func"] is not None:
                funcs.add(c["func"])

        if not edits or dry:
            continue

        out = list(lines)
        note = ("  /* DOA3: x86 latched these flags at the compare above and the "
                "branch below reads them, but an operand is overwritten in "
                "between -- evaluate the condition where the guest does. */")
        for c in edits:
            indent = re.match(r'\s*', lines[c["cmt"]]).group(0)
            out[c["cmt"]] = lines[c["cmt"]] + "\n" + indent + "_rccf = (" + c["cond"] + ");" + note
            out[c["br"]] = out[c["br"]].replace(c["cond"], "_rccf", 1)
        for fs in funcs:
            k = fs
            while k < len(out) and out[k].strip() != "{":
                k += 1
            if k < len(out):
                out[k] = out[k] + "\n    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */"
        open(path, "w", encoding="utf-8", errors="surrogateescape").write("\n".join(out))
        print("patched %-22s %d site(s)" % (os.path.basename(path), len(edits)))

    print("\nrewritten: %d   skipped: %d" % (kept, skipped))
    for r, c in sorted(reasons.items(), key=lambda kv: -kv[1]):
        print("   skipped: %-42s x%d" % (r, c))
    if dry:
        print("(FIX_DRYRUN set: nothing written)")


if __name__ == "__main__":
    main()
