"""Dump object descriptors and their relationship to the index buffer."""
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
    expected_vb = 0x0C90 + obj_count * 0x90

    # Only analyze type-0 sections (formula match)
    if vb_start == expected_vb and sec_num < 4:
        print(f"\n=== Section {sec_num} at 0x{off:X} (type-0) ===")
        print(f"  size={sec_size} center=({cx:.0f},{cy:.0f},{cz:.0f})")
        print(f"  obj_count={obj_count} vb_start=0x{vb_start:X}")

        # Count vertices
        vb_count = 0
        voff = off + vb_start
        while voff + 28 <= off + sec_size:
            x, y, z = struct.unpack_from("<fff", data, voff)
            if x != x or y != y or z != z: break
            if abs(x) > 50000 or abs(y) > 50000 or abs(z) > 50000: break
            if abs(x) < 10 and abs(z) < 10: break
            vb_count += 1
            voff += 28
        vb_end_off = vb_start + vb_count * 28

        print(f"  vertices: {vb_count}, VB ends at section+0x{vb_end_off:X}")

        # Count indices
        ib_start = vb_end_off
        ib_count = 0
        ioff = off + ib_start
        while ioff + 2 <= off + sec_size:
            idx = struct.unpack_from("<H", data, ioff)[0]
            if idx < vb_count:
                ib_count += 1
                ioff += 2
            else:
                break
        print(f"  indices: {ib_count}, IB at section+0x{ib_start:X} to section+0x{ib_start + ib_count*2:X}")

        # Read all indices
        indices = []
        for i in range(ib_count):
            idx = struct.unpack_from("<H", data, off + ib_start + i*2)[0]
            indices.append(idx)

        # Find degenerate restart positions (where consecutive indices repeat)
        restarts = []
        for i in range(len(indices)-1):
            if indices[i] == indices[i+1]:
                restarts.append(i)
        print(f"  Degenerate restart positions: {len(restarts)}")
        if restarts:
            print(f"    First 20: {restarts[:20]}")

        # Dump object descriptors
        obj_area = off + 0x0C90
        print(f"\n  Object descriptors ({obj_count}):")
        for oi in range(min(obj_count, 20)):
            obj_off = obj_area + oi * 0x90
            if obj_off + 0x90 <= off + sec_size:
                desc_off = obj_off + 0x80
                vals = struct.unpack_from("<IIII", data, desc_off)
                print(f"    obj[{oi:2d}] type={vals[0]} idx_count={vals[1]:5d} data_off=0x{vals[2]:06X} term=0x{vals[3]:08X}")

                # Check if data_off is a byte offset into the index buffer
                ib_byte_start = ib_start
                rel_off = vals[2]  # data_off value
                # Try interpreting as byte offset from IB start
                if rel_off > 0 and rel_off < sec_size:
                    idx_at_off = rel_off // 2  # uint16 index number
                    print(f"           data_off as IB byte offset: index #{idx_at_off}, ", end="")
                    if idx_at_off < ib_count:
                        print(f"value={indices[idx_at_off]}")
                    else:
                        print("(out of range)")

                # Try interpreting as byte offset from section start
                sec_rel = vals[2]
                if ib_start <= sec_rel < ib_start + ib_count * 2:
                    idx_num = (sec_rel - ib_start) // 2
                    print(f"           data_off as section byte offset: IB index #{idx_num}, value={indices[idx_num]}")

        # Check if idx_count values sum to ib_count
        total_idx = 0
        for oi in range(obj_count):
            obj_off = obj_area + oi * 0x90
            if obj_off + 0x90 <= off + sec_size:
                idx_cnt = struct.unpack_from("<I", data, obj_off + 0x84)[0]
                total_idx += idx_cnt
        print(f"\n  Sum of obj idx_counts: {total_idx} vs actual IB count: {ib_count}")

        # Check if data_off values are cumulative byte offsets into IB
        print(f"\n  Checking data_off as cumulative IB byte offsets:")
        cum = 0
        for oi in range(min(obj_count, 10)):
            obj_off = obj_area + oi * 0x90
            if obj_off + 0x90 <= off + sec_size:
                vals = struct.unpack_from("<IIII", data, obj_off + 0x80)
                idx_cnt = vals[1]
                data_off_val = vals[2]
                print(f"    obj[{oi}] cum_bytes={cum} data_off=0x{data_off_val:X} idx_count={idx_cnt} next_cum={cum + idx_cnt*2}")
                cum += idx_cnt * 2

    sec_num += 1
    off += sec_size

print(f"\nTotal sections: {sec_num}")
