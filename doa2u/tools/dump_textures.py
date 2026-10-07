"""List all texture names in Global.txd and check for texture data in track files."""
import struct

# 1. List Global.txd texture names
txd_path = r"Burnout 3 Takedown\Data\Global.txd"
with open(txd_path, "rb") as f:
    txd = f.read()

magic = struct.unpack_from("<I", txd, 0)[0]
print(f"Global.txd: {len(txd)} bytes, magic=0x{magic:08X}")
count = struct.unpack_from("<I", txd, 12)[0]
print(f"  Texture count from header: {count}")

# Parse TOC to find texture entries
toc_off = 16
entries = []
while toc_off + 16 <= len(txd):
    idx = struct.unpack_from("<I", txd, toc_off)[0]
    if idx == 0: break
    offset = struct.unpack_from("<I", txd, toc_off + 8)[0]
    entries.append((idx, offset))
    toc_off += 16

print(f"  TOC entries: {len(entries)}")
# Read texture names from each entry
names = []
for idx, offset in entries:
    if offset + 0x80 <= len(txd):
        name_bytes = txd[offset + 0x48 : offset + 0x48 + 24]
        name = name_bytes.split(b'\x00')[0].decode('ascii', errors='replace')
        fmt = struct.unpack_from("<I", txd, offset + 0x34)[0]
        w = struct.unpack_from("<H", txd, offset + 0x38)[0]
        h = struct.unpack_from("<H", txd, offset + 0x3A)[0]
        names.append(name)
        # Only print track-related names
        lower = name.lower()
        if any(x in lower for x in ['road', 'asphalt', 'track', 'barrier', 'wall',
                                      'build', 'ground', 'grass', 'conc', 'brick',
                                      'fence', 'sign', 'guard', 'rail', 'bridge',
                                      'tunnel', 'pavement', 'curb', 'lane', 'mark']):
            print(f"    [{idx}] {name} ({w}x{h} fmt=0x{fmt:X})")

print(f"\n  All texture names:")
for n in sorted(set(names)):
    print(f"    {n}")

# 2. Check type-1 sections in streamed.dat for texture data
print(f"\n\n=== Checking streamed.dat type-1 sections for texture data ===")
dat_path = r"Burnout 3 Takedown\Tracks\AS\C1_V1\streamed.dat"
with open(dat_path, "rb") as f:
    data = f.read()

off = 0
sec_num = 0
while off + 0x80 <= len(data):
    version = struct.unpack_from("<I", data, off)[0]
    sec_size = struct.unpack_from("<I", data, off + 8)[0]
    if version != 1 or sec_size == 0 or off + sec_size > len(data):
        break

    wp_off = struct.unpack_from("<I", data, off + 0x54)[0]
    obj_count = struct.unpack_from("<I", data, off + 0x60)[0]
    vb_start = wp_off + 0x50
    expected_vb = 0x0C90 + obj_count * 0x90
    is_type0 = (vb_start == expected_vb)

    if not is_type0 and sec_num < 6:
        print(f"\n  Section {sec_num} (type-1) at 0x{off:X}, size={sec_size}")
        print(f"    wp_off=0x{wp_off:X} obj_count={obj_count} vb_start=0x{vb_start:X} expected=0x{expected_vb:X}")
        # Look for DXT magic or texture-like patterns
        # DXT1/DXT3/DXT5 data has specific patterns
        # Check for TXD-like magic
        for search_off in [0, 0x80, 0x100, vb_start]:
            if off + search_off + 4 <= off + sec_size:
                val = struct.unpack_from("<I", data, off + search_off)[0]
                print(f"    +0x{search_off:X}: 0x{val:08X}")

        # Scan for recognizable strings in the section
        sec_data = data[off:off+sec_size]
        # Look for ASCII strings (texture names?)
        strings_found = []
        i = 0
        while i < len(sec_data) - 4:
            # Check for printable ASCII run of 4+ chars
            run_start = i
            while i < len(sec_data) and 32 <= sec_data[i] < 127:
                i += 1
            if i - run_start >= 4:
                s = sec_data[run_start:i].decode('ascii')
                strings_found.append((run_start, s))
            i += 1
        if strings_found:
            print(f"    ASCII strings found: {len(strings_found)}")
            for s_off, s in strings_found[:20]:
                print(f"      +0x{s_off:X}: '{s}'")

    sec_num += 1
    off += sec_size

# 3. Check static.dat header
print(f"\n\n=== Checking static.dat ===")
with open(r"Burnout 3 Takedown\Tracks\AS\C1_V1\static.dat", "rb") as f:
    static = f.read(4096)
print(f"  Size: {len(static)} bytes (first 4096)")
print(f"  First 16 bytes: {' '.join(f'{b:02X}' for b in static[:16])}")
# Look for ASCII strings
i = 0
strings = []
while i < len(static) - 4:
    run_start = i
    while i < len(static) and 32 <= static[i] < 127:
        i += 1
    if i - run_start >= 4:
        strings.append((run_start, static[run_start:i].decode('ascii')))
    i += 1
if strings:
    print(f"  ASCII strings in first 4096 bytes:")
    for s_off, s in strings[:30]:
        print(f"    +0x{s_off:X}: '{s}'")

# 4. Check enviro.dat
print(f"\n\n=== Checking enviro.dat ===")
with open(r"Burnout 3 Takedown\Tracks\AS\C1_V1\enviro.dat", "rb") as f:
    enviro = f.read()
print(f"  Size: {len(enviro)} bytes")
# Scan for texture name strings
i = 0
strings = []
while i < len(enviro) - 4:
    run_start = i
    while i < len(enviro) and 32 <= enviro[i] < 127:
        i += 1
    if i - run_start >= 4:
        strings.append((run_start, enviro[run_start:i].decode('ascii')))
    i += 1
if strings:
    print(f"  ASCII strings:")
    for s_off, s in strings[:50]:
        print(f"    +0x{s_off:X}: '{s}'")
