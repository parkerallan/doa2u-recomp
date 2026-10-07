"""Verify section header uint16 table at +0x84 maps objects to static.dat textures."""
import struct

static_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\static.dat"
stream_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"

# Load texture names
with open(static_path, "rb") as f:
    static_data = f.read()

def is_valid_name_char(c):
    return (ord('A') <= c <= ord('Z')) or (ord('a') <= c <= ord('z')) or \
           (ord('0') <= c <= ord('9')) or c == ord('_')

tex_names = []
off = 0x100
while off < len(static_data) - 56:
    if not is_valid_name_char(static_data[off]):
        off += 1; continue
    name_len = 0
    while off + name_len < len(static_data) and is_valid_name_char(static_data[off + name_len]):
        name_len += 1
    if name_len < 4 or name_len > 30 or off + name_len >= len(static_data) or static_data[off + name_len] != 0:
        off += 1; continue
    if not any(static_data[off + i] == ord('_') for i in range(name_len)):
        off += 1; continue
    if off < 24:
        off += 1; continue
    fmt, w, h, name_sz = struct.unpack_from("<IIII", static_data, off - 20)
    if name_sz != 0x20 or fmt not in (0x0C, 0x0E, 0x0F):
        off += 1; continue
    if w < 8 or w > 2048 or h < 8 or h > 2048 or (w&(w-1)) or (h&(h-1)):
        off += 1; continue
    name = static_data[off:off+name_len].decode('ascii')
    base_size = (w//4) * (h//4) * (8 if fmt == 0x0C else 16)
    tex_names.append(name)
    off += 32 + base_size

print(f"Static.dat: {len(tex_names)} textures")

# Parse streamed.dat
with open(stream_path, "rb") as f:
    data = f.read()

sec_off = 0
sec_num = 0
total_matched = 0
total_objects = 0

while sec_off + 0x80 <= len(data):
    version = struct.unpack_from("<I", data, sec_off)[0]
    sec_size = struct.unpack_from("<I", data, sec_off + 8)[0]
    if version != 1 or sec_size == 0 or sec_off + sec_size > len(data):
        break
    wp_off = struct.unpack_from("<I", data, sec_off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, sec_off + 0x60)[0]
    vb_start = wp_off + 0x50
    expected_vb = 0x0C90 + obj_count * 0x90

    if vb_start == expected_vb and obj_count > 0:
        # Read uint16 texture indices from section+0x84
        tex_indices = []
        for oi in range(obj_count):
            idx_off = sec_off + 0x84 + oi * 2
            if idx_off + 2 <= sec_off + sec_size:
                tex_idx = struct.unpack_from("<H", data, idx_off)[0]
                tex_indices.append(tex_idx)

        # Validate
        all_valid = all(idx < len(tex_names) for idx in tex_indices)
        total_objects += len(tex_indices)
        if all_valid:
            total_matched += len(tex_indices)

        if sec_num < 6:
            print(f"\nSection {sec_num}: {obj_count} objects")
            for oi, idx in enumerate(tex_indices[:15]):
                name = tex_names[idx] if idx < len(tex_names) else f"OUT_OF_RANGE({idx})"
                print(f"  obj[{oi:2d}] -> tex[{idx:3d}] = {name}")
            if len(tex_indices) > 15:
                print(f"  ... ({len(tex_indices) - 15} more)")

    sec_num += 1
    sec_off += sec_size

print(f"\n\nTotal: {total_matched}/{total_objects} objects have valid texture indices")
print(f"({sec_num} sections processed)")
