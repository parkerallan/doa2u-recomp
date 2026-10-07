"""Check if object idx_counts partition the index buffer into separate strips."""
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

    wp_off = struct.unpack_from("<I", data, off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, off + 0x60)[0]
    vb_start = wp_off + 0x50
    expected_vb = 0x0C90 + obj_count * 0x90

    if vb_start == expected_vb and sec_num < 2:
        print(f"\n=== Section {sec_num} ===")

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
        vb_end = vb_start + vb_count * 28

        # Read all indices
        indices = []
        ioff = off + vb_end
        while ioff + 2 <= off + sec_size:
            idx = struct.unpack_from("<H", data, ioff)[0]
            if idx < vb_count:
                indices.append(idx)
                ioff += 2
            else:
                break

        # Read object idx_counts
        obj_area = off + 0x0C90
        obj_idx_counts = []
        for oi in range(obj_count):
            obj_off = obj_area + oi * 0x90
            if obj_off + 0x90 <= off + sec_size:
                idx_cnt = struct.unpack_from("<I", data, obj_off + 0x84)[0]
                obj_idx_counts.append(idx_cnt)

        print(f"  vertices={vb_count} indices={len(indices)} obj_count={obj_count}")
        print(f"  obj idx_counts: {obj_idx_counts}")
        print(f"  sum={sum(obj_idx_counts)}")

        # Check transitions at object boundaries
        cum = 0
        for oi, cnt in enumerate(obj_idx_counts):
            start = cum
            end = cum + cnt
            if end > len(indices):
                print(f"  obj[{oi}] range [{start},{end}) EXCEEDS IB!")
                break

            # Get vertex positions at the boundary
            if start > 0 and start < len(indices):
                prev_idx = indices[start - 1]
                curr_idx = indices[start]
                # Read vertex positions
                prev_vo = off + vb_start + prev_idx * 28
                curr_vo = off + vb_start + curr_idx * 28
                px, py, pz = struct.unpack_from("<fff", data, prev_vo)
                cx, cy, cz = struct.unpack_from("<fff", data, curr_vo)
                dist = ((px-cx)**2 + (py-cy)**2 + (pz-cz)**2) ** 0.5
                print(f"  obj[{oi}] boundary at idx {start}: prev_vtx={prev_idx}({px:.0f},{py:.0f},{pz:.0f}) -> curr_vtx={curr_idx}({cx:.0f},{cy:.0f},{cz:.0f}) dist={dist:.0f}")

            # Also show first few and last few indices of this object's range
            first3 = indices[start:min(start+5, end)]
            last3 = indices[max(start, end-5):end]
            print(f"    first indices: {first3}  last indices: {last3}")

            cum += cnt

        # Check what's after the last object's indices
        remaining = len(indices) - cum
        if remaining > 0:
            print(f"\n  {remaining} indices AFTER last object (idx {cum} to {len(indices)-1})")
            print(f"    first: {indices[cum:cum+10]}")
            # Check if these are also valid strips
            # Look for vertex distance jumps in the remaining data
            max_dist = 0
            for i in range(cum, min(cum + remaining - 1, len(indices)-1)):
                v0 = off + vb_start + indices[i] * 28
                v1 = off + vb_start + indices[i+1] * 28
                x0,y0,z0 = struct.unpack_from("<fff", data, v0)
                x1,y1,z1 = struct.unpack_from("<fff", data, v1)
                d = ((x0-x1)**2 + (y0-y1)**2 + (z0-z1)**2) ** 0.5
                if d > max_dist:
                    max_dist = d
            print(f"    max consecutive vertex distance: {max_dist:.0f}")

    sec_num += 1
    off += sec_size
