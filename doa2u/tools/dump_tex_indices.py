"""Check if object descriptor +0x80 is a texture index."""
import struct
from collections import Counter

stream_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"
static_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\static.dat"

# Load texture names from static.dat
with open(static_path, "rb") as f:
    static_data = f.read()

def is_valid_name_char(c):
    return (ord('A') <= c <= ord('Z')) or (ord('a') <= c <= ord('z')) or \
           (ord('0') <= c <= ord('9')) or c == ord('_')

tex_names = []
off = 0x100
while off < len(static_data) - 56:
    if not is_valid_name_char(static_data[off]):
        off += 1
        continue
    name_len = 0
    while off + name_len < len(static_data) and is_valid_name_char(static_data[off + name_len]):
        name_len += 1
    if name_len < 4 or name_len > 30 or off + name_len >= len(static_data) or static_data[off + name_len] != 0:
        off += 1
        continue
    has_underscore = any(static_data[off + i] == ord('_') for i in range(name_len))
    if not has_underscore:
        off += 1
        continue
    if off < 24:
        off += 1
        continue
    fmt, w, h, name_sz = struct.unpack_from("<IIII", static_data, off - 20)
    if name_sz != 0x20:
        off += 1
        continue
    if fmt not in (0x0C, 0x0E, 0x0F):
        off += 1
        continue
    if w < 8 or w > 2048 or h < 8 or h > 2048 or (w & (w-1)) != 0 or (h & (h-1)) != 0:
        off += 1
        continue
    name = static_data[off:off+name_len].decode('ascii')
    pixel_off = off + 32
    if fmt == 0x0C:
        base_size = (w // 4) * (h // 4) * 8
    else:
        base_size = (w // 4) * (h // 4) * 16
    tex_names.append(name)
    off += 32 + base_size

print(f"Total textures in static.dat: {len(tex_names)}")
for i, n in enumerate(tex_names):
    print(f"  [{i:3d}] {n}")

# Parse streamed.dat
with open(stream_path, "rb") as f:
    data = f.read()

val80_counter = Counter()
all_objects = []

sec_off = 0
while sec_off + 0x80 <= len(data):
    version = struct.unpack_from("<I", data, sec_off)[0]
    sec_size = struct.unpack_from("<I", data, sec_off + 8)[0]
    if version != 1 or sec_size == 0 or sec_off + sec_size > len(data):
        break
    wp_off = struct.unpack_from("<I", data, sec_off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, sec_off + 0x60)[0]
    vb_start = wp_off + 0x50
    expected_vb = 0x0C90 + obj_count * 0x90
    if vb_start == expected_vb:
        for oi in range(obj_count):
            desc_base = sec_off + 0x0C90 + oi * 0x90
            if desc_base + 0x90 <= sec_off + sec_size:
                val80 = struct.unpack_from("<I", data, desc_base + 0x80)[0]
                val84 = struct.unpack_from("<I", data, desc_base + 0x84)[0]
                val88 = struct.unpack_from("<I", data, desc_base + 0x88)[0]
                val80_counter[val80] += 1
                all_objects.append((val80, val84, val88))
    sec_off += sec_size

print(f"\n+0x80 value distribution ({len(all_objects)} total objects):")
for val, count in sorted(val80_counter.items()):
    tex_name = tex_names[val] if val < len(tex_names) else "OUT OF RANGE"
    print(f"  {val:4d} ({count:4d} objs) -> {tex_name}")

# Also check if +0x80 might be something else and a different field is the texture index
# Let's check the section header for a texture list
print("\n\nChecking if there's a per-section material/texture table...")
sec_off = 0
sec_num = 0
while sec_off + 0x80 <= len(data):
    version = struct.unpack_from("<I", data, sec_off)[0]
    sec_size = struct.unpack_from("<I", data, sec_off + 8)[0]
    if version != 1 or sec_size == 0 or sec_off + sec_size > len(data):
        break
    wp_off = struct.unpack_from("<I", data, sec_off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, sec_off + 0x60)[0]
    vb_start = wp_off + 0x50
    expected_vb = 0x0C90 + obj_count * 0x90
    if vb_start == expected_vb and sec_num < 3:
        # Look at the 0x80-0x0C90 area for potential material table
        # Specifically check offsets mentioned in header
        print(f"\nSection {sec_num} header fields:")
        for hoff in range(0x64, 0x80, 4):
            val = struct.unpack_from("<I", data, sec_off + hoff)[0]
            if val != 0:
                print(f"  +0x{hoff:02X}: 0x{val:08X} ({val})")
        # Check area 0x80-0x100 for possible texture/material table
        print(f"  Region 0x80-0x100:")
        for hoff in range(0x80, 0x100, 4):
            val = struct.unpack_from("<I", data, sec_off + hoff)[0]
            if val != 0:
                print(f"    +0x{hoff:03X}: 0x{val:08X} ({val})")
    sec_num += 1
    sec_off += sec_size
