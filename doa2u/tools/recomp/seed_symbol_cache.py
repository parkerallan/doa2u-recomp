"""
Seed the functions named in a cxbx symbol cache .ini.
usage: py -3 -m tools.recomp.seed_symbol_cache <ini> <seed_list_out>
"""
import json
import re
import sys

from .config import is_code_address

starts = {int(f["start"], 16) for f in json.load(open("tools/disasm/output/functions.json"))}
found = []
for line in open(sys.argv[1], encoding="utf-8", errors="ignore"):
    m = re.match(r"\s*(\w+)\s*=\s*0x([0-9a-fA-F]+)", line)
    if not m or m.group(1).endswith("_OFFSET") or m.group(1).startswith(("D3DRS_", "D3D_g_", "g_")):
        continue
    a = int(m.group(2), 16)
    if is_code_address(a) and a not in starts:
        found.append(a)
with open(sys.argv[2], "w") as f:
    for a in sorted(set(found)):
        f.write(f"sub_{a:08X}\n")
print(f"symbol-cache entries not yet seeded: {len(set(found))}")
