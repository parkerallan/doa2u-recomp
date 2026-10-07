"""Dump object descriptor fields from streamed.dat to find texture references."""
import struct

static_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\static.dat"
stream_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"

# First, load static.dat texture names for cross-reference
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
    if w < 8 or w > 2048 or h < 8 or h > 2048:
        off += 1
        continue
    if (w & (w-1)) != 0 or (h & (h-1)) != 0:
        off += 1
        continue
    name = static_data[off:off+name_len].decode('ascii')
    # Compute pixel data offset in static.dat
    pixel_off = off + 32
    if fmt == 0x0C:
        base_size = (w // 4) * (h // 4) * 8
    else:
        base_size = (w // 4) * (h // 4) * 16
    tex_names.append({
        'name': name, 'offset': off - 20, 'pixel_off': pixel_off,
        'size': base_size, 'w': w, 'h': h, 'fmt': fmt
    })
    off += 32 + base_size
    continue

print(f"Found {len(tex_names)} textures in static.dat")
for i, t in enumerate(tex_names[:10]):
    print(f"  [{i}] {t['name']} ({t['w']}x{t['h']} fmt=0x{t['fmt']:X} at 0x{t['offset']:X})")

# Now parse streamed.dat and dump object descriptors
with open(stream_path, "rb") as f:
    data = f.read()

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
    is_type0 = (vb_start == expected_vb)

    if is_type0 and sec_num < 4:
        print(f"\n=== Section {sec_num} at 0x{sec_off:X}, size={sec_size}, obj_count={obj_count} ===")

        for oi in range(min(obj_count, 8)):
            desc_base = sec_off + 0x0C90 + oi * 0x90
            print(f"\n  Object {oi} descriptor at file+0x{desc_base:X} (sec+0x{0x0C90 + oi * 0x90:X}):")

            # Dump all 0x90 bytes as uint32s
            for field_off in range(0, 0x90, 4):
                val = struct.unpack_from("<I", data, desc_base + field_off)[0]
                fval = struct.unpack_from("<f", data, desc_base + field_off)[0]
                if val != 0:
                    # Check if value could be a static.dat offset
                    match = ""
                    for t in tex_names:
                        if abs(val - t['offset']) < 0x100:
                            match = f" -> near tex '{t['name']}' (off=0x{t['offset']:X})"
                            break
                    # Check if small index
                    if val < len(tex_names):
                        match += f" [tex_idx -> '{tex_names[val]['name']}']" if val < len(tex_names) else ""
                    print(f"    +0x{field_off:02X}: 0x{val:08X} ({val:10d}) float={fval:.4f}{match}")

    sec_num += 1
    sec_off += sec_size

# Also look at the area before object descriptors (0x0C90 region)
# There might be a texture index table in the header
print("\n\n=== Section 0 header region (0x80-0x0C90) ===")
sec0_off = 0
sec0_size = struct.unpack_from("<I", data, 8)[0]
# Dump non-zero values in 0x80-0x200 range
for off in range(0x64, 0x100, 4):
    val = struct.unpack_from("<I", data, sec0_off + off)[0]
    if val != 0:
        fval = struct.unpack_from("<f", data, sec0_off + off)[0]
        print(f"  +0x{off:03X}: 0x{val:08X} ({val:10d}) float={fval:.6f}")

# Check a wider area for texture name strings in streamed.dat section 0
print("\n\n=== Looking for texture name references in section 0 ===")
sec = data[sec0_off:sec0_off + sec0_size]
# Look for ASCII strings in descriptor area
i = 0x0C90
while i < min(0x0C90 + 32 * 0x90, len(sec) - 4):
    run_start = i
    while i < len(sec) and 32 <= sec[i] < 127:
        i += 1
    if i - run_start >= 4:
        s = sec[run_start:i].decode('ascii')
        print(f"  sec+0x{run_start:X}: '{s}'")
    i += 1
