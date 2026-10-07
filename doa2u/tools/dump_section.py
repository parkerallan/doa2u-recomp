"""Dump the structure of streamed.dat sections to understand index buffer format."""
import struct, sys

path = sys.argv[1] if len(sys.argv) > 1 else r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"
with open(path, "rb") as f:
    data = f.read()

off = 0
sec_num = 0
while off + 0x80 <= len(data):
    version = struct.unpack_from("<I", data, off + 0x00)[0]
    sec_size = struct.unpack_from("<I", data, off + 0x08)[0]
    if version != 1 or sec_size == 0 or off + sec_size > len(data):
        break

    cx, cy, cz = struct.unpack_from("<fff", data, off + 0x10)
    wp_off = struct.unpack_from("<I", data, off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, off + 0x60)[0]

    vb_start = wp_off + 0x50

    if sec_num < 6:  # Only dump first 6 sections
        print(f"\n=== Section {sec_num} at 0x{off:X} ===")
        print(f"  size={sec_size} center=({cx:.0f},{cy:.0f},{cz:.0f})")
        print(f"  wp_off=0x{wp_off:X} obj_count={obj_count}")
        print(f"  vb_start=0x{vb_start:X} (= 0x0C90 + {obj_count}*0x90 = 0x{0x0C90 + obj_count * 0x90:X})")

        # Check if vb_start matches the formula
        expected_vb = 0x0C90 + obj_count * 0x90
        print(f"  formula match: {vb_start == expected_vb}")

        # Look at object descriptors (at offset 0x0C90 - obj_count*0 ... before vb_start)
        # Object descriptors start after connectivity tables
        obj_area = off + 0x0C90  # approximate
        print(f"  Object area at section+0x0C90:")
        for oi in range(min(obj_count, 4)):
            obj_off = obj_area + oi * 0x90
            if obj_off + 0x90 <= off + sec_size:
                # Dump key fields of the 0x90-byte object descriptor
                # First 128 bytes = 8 bounding positions (16 bytes each = float4)
                # Last 16 bytes = descriptor: type, index_count, data_offset, terminator
                desc_off = obj_off + 0x80  # descriptor at end of object
                vals = struct.unpack_from("<IIII", data, desc_off)
                print(f"    obj[{oi}] desc: type={vals[0]} idx_count={vals[1]} data_off=0x{vals[2]:X} term=0x{vals[3]:X}")

                # Also dump the bounding box min/max
                bmin = struct.unpack_from("<fff", data, obj_off)
                bmax = struct.unpack_from("<fff", data, obj_off + 0x40)
                print(f"           bbox: ({bmin[0]:.0f},{bmin[1]:.0f},{bmin[2]:.0f}) to ({bmax[0]:.0f},{bmax[1]:.0f},{bmax[2]:.0f})")

        # Count vertices (28-byte stride, valid coords)
        vb_count = 0
        voff = off + vb_start
        while voff + 28 <= off + sec_size:
            x, y, z = struct.unpack_from("<fff", data, voff)
            if x != x or y != y or z != z:
                break
            if abs(x) > 50000 or abs(y) > 50000 or abs(z) > 50000:
                break
            if abs(x) < 10 and abs(z) < 10:
                break
            vb_count += 1
            voff += 28

        vb_end = off + vb_start + vb_count * 28

        # Look at raw data after vertex buffer
        print(f"  Vertices: {vb_count} (ends at section+0x{vb_start + vb_count*28:X})")
        print(f"  Remaining bytes after VB: {off + sec_size - vb_end}")

        # Try to understand index format
        # Dump first 40 uint16 values after VB
        print(f"  Raw uint16 after VB:")
        for i in range(min(40, (off + sec_size - vb_end) // 2)):
            idx = struct.unpack_from("<H", data, vb_end + i * 2)[0]
            marker = ""
            if idx >= vb_count:
                marker = f" (>= vb_count={vb_count})"
            if idx == 0xFFFF:
                marker = " (FFFF = strip restart)"
            print(f"    [{i:3d}] {idx}{marker}")

    sec_num += 1
    off += sec_size

print(f"\nTotal sections: {sec_num}")
