"""
List call targets the generated code references but no function defines; write the seedable ones.
usage: py -3 -m tools.recomp.find_missing <seed_list_out>
"""
import glob
import re
import sys

from .config import is_code_address

called, defined = set(), set()
for path in glob.glob("src/game/recomp/gen/*.c") + ["src/game/recomp/recomp_manual.c"]:
    try:
        text = open(path, encoding="utf-8", errors="ignore").read()
    except FileNotFoundError:
        continue
    called.update(int(m, 16) for m in re.findall(r"\bsub_([0-9A-F]{8})\(\)", text))
    defined.update(int(m, 16) for m in re.findall(r"^void sub_([0-9A-F]{8})\(void\)", text, re.M))

missing = sorted(called - defined)
seedable = [a for a in missing if is_code_address(a)]
garbage = [a for a in missing if not is_code_address(a)]
with open(sys.argv[1], "w") as f:
    for a in seedable:
        f.write(f"sub_{a:08X}\n")
print(f"called={len(called)} defined={len(defined)} missing={len(missing)} "
      f"seedable={len(seedable)} garbage={len(garbage)}")
for a in garbage:
    print(f"  garbage target sub_{a:08X}")
