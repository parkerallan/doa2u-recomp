"""Dump some vertex colors from streamed.dat to check format."""
import struct

path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"
with open(path, "rb") as f:
    data = f.read()

off = 0
version = struct.unpack_from("<I", data, 0)[0]
sec_size = struct.unpack_from("<I", data, 8)[0]
wp_off = struct.unpack_from("<I", data, 0x54)[0]
obj_count = struct.unpack_from("<I", data, 0x60)[0]
vb_start = wp_off + 0x50

print(f"Section 0: vb_start=0x{vb_start:X}")
print(f"\nFirst 20 vertices - position and color:")
for i in range(20):
    vo = vb_start + i * 28
    x, y, z = struct.unpack_from("<fff", data, vo)
    pn = struct.unpack_from("<I", data, vo + 12)[0]
    color = struct.unpack_from("<I", data, vo + 16)[0]
    u, v = struct.unpack_from("<ff", data, vo + 20)
    a = (color >> 24) & 0xFF
    r = (color >> 16) & 0xFF
    g = (color >> 8) & 0xFF
    b = color & 0xFF
    print(f"  v[{i:3d}] pos=({x:8.1f},{y:6.1f},{z:8.1f}) "
          f"color=0x{color:08X} ARGB=({a},{r},{g},{b}) UV=({u:.3f},{v:.3f})")

# Check color distribution
print(f"\nColor distribution across all vertices in section 0:")
vb_count = 0
r_sum, g_sum, b_sum = 0, 0, 0
r_min, g_min, b_min = 255, 255, 255
r_max, g_max, b_max = 0, 0, 0
zero_count = 0
vo = vb_start
while vo + 28 <= sec_size:
    x, y, z = struct.unpack_from("<fff", data, vo)
    if abs(x) > 50000 or abs(y) > 50000 or abs(z) > 50000: break
    if abs(x) < 10 and abs(z) < 10: break
    color = struct.unpack_from("<I", data, vo + 16)[0]
    r = (color >> 16) & 0xFF
    g = (color >> 8) & 0xFF
    b = color & 0xFF
    r_sum += r; g_sum += g; b_sum += b
    if r < r_min: r_min = r
    if g < g_min: g_min = g
    if b < b_min: b_min = b
    if r > r_max: r_max = r
    if g > g_max: g_max = g
    if b > b_max: b_max = b
    if r + g + b == 0: zero_count += 1
    vb_count += 1
    vo += 28

print(f"  {vb_count} vertices")
print(f"  R: min={r_min} max={r_max} avg={r_sum/vb_count:.0f}")
print(f"  G: min={g_min} max={g_max} avg={g_sum/vb_count:.0f}")
print(f"  B: min={b_min} max={b_max} avg={b_sum/vb_count:.0f}")
print(f"  Zero color (black): {zero_count}")

# Try interpreting as BGRA instead
print(f"\nSame vertices interpreted as BGRA:")
for i in range(10):
    vo = vb_start + i * 28
    color = struct.unpack_from("<I", data, vo + 16)[0]
    b2 = (color >> 16) & 0xFF  # if BGRA
    g2 = (color >> 8) & 0xFF
    r2 = color & 0xFF
    a2 = (color >> 24) & 0xFF
    print(f"  v[{i}] as ARGB=({(color>>24)&0xFF},{(color>>16)&0xFF},{(color>>8)&0xFF},{color&0xFF}) "
          f"as ABGR=({a2},{r2},{g2},{b2})")
