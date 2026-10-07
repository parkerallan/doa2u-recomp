"""Find the actual giant triangles in the strip conversion."""
import struct, sys, math

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

    if vb_start == expected_vb and sec_num == 0:
        # Read all vertices
        verts = []
        voff = off + vb_start
        while voff + 28 <= off + sec_size:
            x, y, z = struct.unpack_from("<fff", data, voff)
            if x != x or y != y or z != z: break
            if abs(x) > 50000 or abs(y) > 50000 or abs(z) > 50000: break
            if abs(x) < 10 and abs(z) < 10: break
            verts.append((x, y, z))
            voff += 28
        vb_count = len(verts)

        # Read all indices
        vb_end = vb_start + vb_count * 28
        indices = []
        ioff = off + vb_end
        while ioff + 2 <= off + sec_size:
            idx = struct.unpack_from("<H", data, ioff)[0]
            if idx < vb_count:
                indices.append(idx)
                ioff += 2
            else:
                break

        print(f"Section 0: {vb_count} verts, {len(indices)} indices")

        # Convert strip to triangles, tracking giant ones
        giant_count = 0
        normal_count = 0
        winding = 0
        THRESHOLD = 100.0  # units - anything bigger is "giant"

        for t in range(len(indices) - 2):
            i0, i1, i2 = indices[t], indices[t+1], indices[t+2]

            # Skip degenerate
            if i0 == i1 or i0 == i2 or i1 == i2:
                winding = 0
                continue

            v0, v1, v2 = verts[i0], verts[i1], verts[i2]

            # Compute max edge length
            def dist(a, b):
                return math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2 + (a[2]-b[2])**2)

            d01 = dist(v0, v1)
            d02 = dist(v0, v2)
            d12 = dist(v1, v2)
            max_edge = max(d01, d02, d12)

            if max_edge > THRESHOLD:
                giant_count += 1
                if giant_count <= 10:
                    print(f"  GIANT tri t={t} winding={winding}: "
                          f"idx=({i0},{i1},{i2}) "
                          f"edges=({d01:.0f},{d02:.0f},{d12:.0f}) "
                          f"v0=({v0[0]:.0f},{v0[1]:.0f},{v0[2]:.0f}) "
                          f"v1=({v1[0]:.0f},{v1[1]:.0f},{v1[2]:.0f}) "
                          f"v2=({v2[0]:.0f},{v2[1]:.0f},{v2[2]:.0f})")
            else:
                normal_count += 1

            winding += 1

        print(f"\nGiant triangles (edge > {THRESHOLD}): {giant_count}")
        print(f"Normal triangles: {normal_count}")
        print(f"Giant ratio: {giant_count}/{giant_count+normal_count} = {giant_count*100/(giant_count+normal_count):.1f}%")

        # Now check: does index 0 appear frequently and is it special?
        idx0_count = indices.count(0)
        print(f"\nIndex 0 appears {idx0_count} times")
        print(f"Vertex 0: ({verts[0][0]:.1f}, {verts[0][1]:.1f}, {verts[0][2]:.1f})")

        # Check if index 0 is used as a strip restart marker
        zero_positions = [i for i, x in enumerate(indices) if x == 0]
        print(f"Index 0 positions (first 30): {zero_positions[:30]}")

        # Check patterns around index 0
        print("\nContext around index 0 appearances:")
        for pos in zero_positions[:10]:
            start = max(0, pos-2)
            end = min(len(indices), pos+3)
            context = indices[start:end]
            # Get vertex positions
            ctx_pos = [(verts[i][0], verts[i][1], verts[i][2]) for i in context]
            print(f"  pos {pos}: indices={context}")
            for ci, (cx, cy, cz) in zip(context, ctx_pos):
                print(f"    vtx[{ci}] = ({cx:.0f}, {cy:.0f}, {cz:.0f})")

    sec_num += 1
    off += sec_size
