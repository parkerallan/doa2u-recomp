#!/usr/bin/env python3
"""
Materialize AH at `lahf` sites that follow a float compare
(`ucomiss/fcomip; lahf; test ah, X; jp`). The lifter used to emit `lahf` as a
comment, so the branch tested stale eax. Each site becomes the lifter's form:

    SET_HI8(eax, 0x02 | (_fpu_cmp < 0 ? 0x01 : 0) | (_fpu_cmp == 0 ? 0x40 : 0)); /* lahf */

A site is rewritten only when the C block holds one `lahf` after a float
compare in the same straight-line run, and the guest block holds one `lahf`
whose flags come from a float compare of the same family with no call, flag
writer or branch target in between.

usage (from doa2u/):
    py -3 -m tools.recomp.fix_lahf                 # rewrite
    FIX_DRYRUN=1 py -3 -m tools.recomp.fix_lahf    # report only
"""
import glob
import os
import re

from tools.recomp.fix_deferred_cmp import (GEN_DIR, LABEL, FLAG_WRITERS,
                                           parse_asm, run_ends)

CMT = "/* lahf - load AH from flags"
NEW = ("SET_HI8(eax, 0x02 | (_fpu_cmp < 0 ? 0x01 : 0) | "
       "(_fpu_cmp == 0 ? 0x40 : 0)); /* lahf */")
SSE_CMP = {"comiss", "ucomiss"}
X87_CMP = {"fcomi", "fcomip", "fucomi", "fucomip", "fcompi", "fucompi"}
FPU_SET = re.compile(r'_fpu_cmp = .*/\* (\w+)')


def family(m):
    return "sse" if m in SSE_CMP else "x87" if m in X87_CMP else None


def guest_lahfs(insns, labelled, start_va, end_va):
    """[(lahf address, compare mnemonic or None, why)] in [start_va, end_va)."""
    addrs = sorted(a for a in insns if start_va <= a < end_va)
    out = []
    for i, a in enumerate(addrs):
        if insns[a][0] != "lahf":
            continue
        cmp_m, why = None, "no float compare before it in the block"
        for k in range(i - 1, -1, -1):
            b = addrs[k]
            bm = insns[b][0]
            if bm == "call":
                why = "call between compare and lahf"
                break
            if bm in SSE_CMP or bm in X87_CMP:
                cmp_m, why = bm, None
                break
            if bm in FLAG_WRITERS or bm.startswith("j"):
                why = "flags last written by %s at 0x%08X" % (bm, b)
                break
            if b in labelled:
                why = "branch target at 0x%08X between compare and lahf" % b
                break
        out.append((a, cmp_m, why))
    return out


def scan_file(path):
    lines = open(path, encoding="utf-8", errors="surrogateescape").read().split("\n")
    labels = [(i, int(m.group(1), 16)) for i, l in enumerate(lines)
              for m in [LABEL.match(l.strip())] if m]
    end_of = {}
    for k, (i, a) in enumerate(labels):
        end_of[i] = labels[k + 1][1] if k + 1 < len(labels) else a + 0x800
    cands, block = [], None
    for i, line in enumerate(lines):
        m = LABEL.match(line.strip())
        if m:
            block = (i, int(m.group(1), 16), end_of[i])
        if CMT not in line or block is None:
            continue
        cmp_m = None
        for j in range(i - 1, block[0], -1):
            mf = FPU_SET.search(lines[j])
            if mf:
                cmp_m = mf.group(1)
                break
            if run_ends(lines[j]):
                break
        cands.append(dict(line=i, block=block, cmp=cmp_m))
    return lines, cands


def main():
    dry = bool(os.environ.get("FIX_DRYRUN"))
    insns, labelled = parse_asm()
    print("guest: %d instructions, %d branch targets" % (len(insns), len(labelled)))
    kept = skipped = 0
    reasons = {}

    def skip(path, c, why):
        nonlocal skipped
        skipped += 1
        reasons[why.split(" at 0x")[0]] = reasons.get(why.split(" at 0x")[0], 0) + 1
        if dry:
            print("  SKIP %s:%d (%s)" % (os.path.basename(path), c["line"] + 1, why))

    for path in sorted(glob.glob(os.path.join(GEN_DIR, "*.c"))):
        lines, cands = scan_file(path)
        if not cands:
            continue
        by_block = {}
        for c in cands:
            by_block.setdefault(c["block"][0], []).append(c)
        edits = []
        for group in by_block.values():
            if len(group) != 1:
                for c in group:
                    skip(path, c, "%d lahf in one C block" % len(group))
                continue
            c = group[0]
            if c["cmp"] is None or family(c["cmp"]) is None:
                skip(path, c, "no float compare before it in the C run")
                continue
            g = guest_lahfs(insns, labelled, c["block"][1], c["block"][2])
            if len(g) != 1:
                skip(path, c, "%d lahf in the guest block" % len(g))
                continue
            ga, gcmp, why = g[0]
            if why:
                skip(path, c, why)
                continue
            if family(gcmp) != family(c["cmp"]):
                skip(path, c, "guest %s vs C %s" % (gcmp, c["cmp"]))
                continue
            kept += 1
            edits.append(c)
        if not edits or dry:
            if edits:
                print("would patch %-22s %d site(s)" % (os.path.basename(path), len(edits)))
            continue
        out = list(lines)
        for c in edits:
            indent = re.match(r'\s*', lines[c["line"]]).group(0)
            out[c["line"]] = indent + NEW
        open(path, "w", encoding="utf-8", errors="surrogateescape").write("\n".join(out))
        print("patched %-22s %d site(s)" % (os.path.basename(path), len(edits)))

    print("\nrewritten: %d   skipped: %d" % (kept, skipped))
    for r, n in sorted(reasons.items(), key=lambda kv: -kv[1]):
        print("   skipped: %-48s x%d" % (r, n))
    if dry:
        print("(FIX_DRYRUN set: nothing written)")


if __name__ == "__main__":
    main()
