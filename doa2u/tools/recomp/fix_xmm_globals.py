#!/usr/bin/env python3
"""
Drop the per-function `xmm128_t xmm0, ...;` declarations from the generated
units so xmm0-7 resolve to the global register file g_xmm[8] (see
recomp_types.h). Floats cross calls and split fragments in xmm registers;
as locals those values were lost. Only exact declaration lines are removed.
Idempotent.

usage (from doa2u/):
    py -3 -m tools.recomp.fix_xmm_globals                 # rewrite
    FIX_DRYRUN=1 py -3 -m tools.recomp.fix_xmm_globals    # report only
"""
import glob
import os
import re

GEN_DIR = os.path.join("src", "game", "recomp", "gen")
DECL = re.compile(r'^[ \t]*xmm128_t[ \t]+xmm[0-7](?:[ \t]*,[ \t]*xmm[0-7])*[ \t]*;[ \t]*\r?\n',
                  re.MULTILINE)


def main():
    dry = bool(os.environ.get("FIX_DRYRUN"))
    total = 0
    for path in sorted(glob.glob(os.path.join(GEN_DIR, "*.c"))):
        data = open(path, "rb").read().decode("utf-8", "surrogateescape")
        new, n = DECL.subn("", data)
        if not n:
            continue
        total += n
        print("%s %-22s %d declaration(s)" % ("would patch" if dry else "patched",
                                               os.path.basename(path), n))
        if not dry:
            open(path, "wb").write(new.encode("utf-8", "surrogateescape"))
    left = 0
    for path in glob.glob(os.path.join(GEN_DIR, "*.c")):
        left += len(re.findall(r'\bxmm128_t\s+xmm[0-7]\b',
                               open(path, encoding="utf-8", errors="replace").read()))
    print("\nremoved: %d   remaining local xmm declarations: %d" % (total, 0 if not dry else left))
    if dry:
        print("(FIX_DRYRUN set: nothing written)")


if __name__ == "__main__":
    main()
