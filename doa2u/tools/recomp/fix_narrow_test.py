#!/usr/bin/env python3
"""
Cast `test r8/r16; jcc` conditions back to the operand width.

The lifter emitted `test cl,cl; jge` as `CMP_GE(LO8(ecx) & LO8(ecx), 0)`.
uint8_t & uint8_t promotes to int, and CMP_* sign-extends by sizeof(a), so a
byte with bit 7 set never read as negative: the attract fight's table walk in
sub_000372A0 never saw its terminator and ran off into unmapped memory. Each
site becomes

    CMP_GE((uint8_t)(LO8(ecx) & LO8(ecx)), 0)

-- the lifter's form since this fix. Only `X & Y, 0` where both sides are the
same-width 8- or 16-bit accessor is rewritten. Idempotent.

usage (from doa2u/):
    py -3 -m tools.recomp.fix_narrow_test                 # rewrite
    FIX_DRYRUN=1 py -3 -m tools.recomp.fix_narrow_test    # report only
"""
import glob
import os
import re

GEN_DIR = os.path.join("src", "game", "recomp", "gen")
ARG = r'\((?:[^()]|\([^()]*\))*\)'          # one call's argument list, one nesting level
ACC8 = r'(?:LO8|HI8|MEM8|SMEM8)'
ACC16 = r'(?:LO16|MEM16|SMEM16)'
SITE = re.compile(r'\b(CMP_(?:L|GE|LE|G|A|B|AE|BE|EQ|NE))\(((%s%s) & (%s%s)|(%s%s) & (%s%s)), 0\)'
                  % (ACC8, ARG, ACC8, ARG, ACC16, ARG, ACC16, ARG))


def fix(m):
    macro, expr = m.group(1), m.group(2)
    cast = 'uint8_t' if m.group(3) else 'uint16_t'
    return '%s((%s)(%s), 0)' % (macro, cast, expr)


def main():
    dry = bool(os.environ.get("FIX_DRYRUN"))
    total = 0
    for path in sorted(glob.glob(os.path.join(GEN_DIR, "*.c"))):
        data = open(path, "rb").read().decode("utf-8", "surrogateescape")
        new, n = SITE.subn(fix, data)
        if not n:
            continue
        total += n
        print("%s %-22s %d site(s)" % ("would patch" if dry else "patched", os.path.basename(path), n))
        if not dry:
            open(path, "wb").write(new.encode("utf-8", "surrogateescape"))
    print("\nrewritten: %d" % total)
    if dry:
        print("(FIX_DRYRUN set: nothing written)")


if __name__ == "__main__":
    main()
