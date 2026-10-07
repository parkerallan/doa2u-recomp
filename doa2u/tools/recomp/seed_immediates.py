"""
Seed function entries referenced only as code immediates (push/mov of a code address).
usage: py -3 -m tools.recomp.seed_immediates <xbe> <seed_list_out>
"""
import glob
import json
import re
import sys

from .config import is_code_address, va_to_file_offset

xbe = open(sys.argv[1], "rb").read()
starts = {int(f["start"], 16) for f in json.load(open("tools/disasm/output/functions.json"))}
INSN = re.compile(r"^\s{2}0x[0-9A-Fa-f]{8}\s{2}[0-9a-fA-F]+\s+(\S+)\s*(.*?)\s*$")
IMM = re.compile(r"(?<![\w\[+*-])0x([0-9a-fA-F]{5,8})\b(?!\])")


def byte_at(va):
    o = va_to_file_offset(va)
    return xbe[o] if o is not None else None


found = set()
for path in glob.glob("tools/disasm/output/asm/*.asm"):
    for line in open(path, encoding="utf-8", errors="replace"):
        m = INSN.match(line)
        if not m or m.group(1) not in ("push", "mov"):
            continue
        ops = m.group(2)
        if "[" in ops and m.group(1) == "push":
            continue
        for v in IMM.findall(ops.split(",")[-1]):
            a = int(v, 16)
            if a in starts or not is_code_address(a):
                continue
            if byte_at(a - 1) in (0xCC, 0x90, 0xC3) or byte_at(a - 3) == 0xC2:
                found.add(a)

with open(sys.argv[2], "w") as f:
    for a in sorted(found):
        f.write(f"sub_{a:08X}\n")
print(f"immediate entry candidates not yet seeded: {len(found)}")
