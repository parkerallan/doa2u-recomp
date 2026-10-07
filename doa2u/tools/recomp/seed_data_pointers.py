"""
Seed function entries referenced only from data (vtables, callback tables) into functions.json.
usage: py -3 -m tools.recomp.seed_data_pointers <xbe> <seed_list_out>
"""
import json
import struct
import sys

from .config import SECTIONS, is_code_address, va_to_file_offset

xbe = open(sys.argv[1], "rb").read()
funcs = json.load(open("tools/disasm/output/functions.json"))
starts = {int(f["start"], 16) for f in funcs}
# a function packed directly behind another one starts where the detector
# ended its neighbour (no padding in between)
ends = {int(f["end"], 16) for f in funcs}


def byte_at(va):
    o = va_to_file_offset(va)
    return xbe[o] if o is not None else None


def at_boundary(va):
    if va in ends:
        return True
    b1 = byte_at(va - 1)
    if b1 in (0xCC, 0x90, 0xC3):
        return True
    # ret imm16: C2 xx xx
    return byte_at(va - 3) == 0xC2


found = set()
for name, va, size, raw in SECTIONS:
    # data sections, plus the writable XDK sections that keep their own
    # tables inline (XPP's device-type table -> MU_Init, D3D/DSOUND vtables)
    if name not in (".rdata", ".data", ".data1", "XON_RD",
                    "D3D", "D3DX", "XGRPH", "DSOUND", "XPP"):
        continue
    blob = xbe[raw:raw + size]
    for i in range(0, len(blob) - 3, 4):
        p = struct.unpack_from("<I", blob, i)[0]
        if p in starts or not is_code_address(p) or p in found:
            continue
        if at_boundary(p):
            found.add(p)

with open(sys.argv[2], "w") as f:
    for a in sorted(found):
        f.write(f"sub_{a:08X}\n")
print(f"data-referenced entry candidates not yet seeded: {len(found)}")
