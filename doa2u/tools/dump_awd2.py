#!/usr/bin/env python3
"""AWD format analysis - focus on entry structure and audio data location."""
import struct
import sys

def analyze_awd(path):
    with open(path, 'rb') as f:
        data = f.read()

    print(f"File: {path} ({len(data)} bytes)")

    # The file starts with what looks like a RenderWare Audio section
    # Type 0x0809 = RW audio wave dictionary
    rw_type = struct.unpack_from('<I', data, 0)[0]
    print(f"RW type: 0x{rw_type:08X}")

    # Look for entry table by finding name strings
    # Each entry seems to be 0x88 (136) bytes with name at offset 0xC into the entry
    # Let's find all name positions and compute entry boundaries

    # Scan for "Beep" which we know is the first entry
    beep_pos = data.find(b'Beep\x00')
    print(f"'Beep' found at: 0x{beep_pos:06X}")

    # The entry table seems to start around 0xC0
    # Let me dump the region around each name to understand the structure

    # Known names from the grep earlier
    names = []
    pos = 0
    while pos < min(len(data), 0x3000):
        # Look for 4+ printable ASCII chars followed by null, preceded by null
        if pos > 0 and data[pos-1] == 0:
            end = pos
            while end < pos + 20 and end < len(data) and 32 <= data[end] < 127:
                end += 1
            if end - pos >= 4 and end < len(data) and data[end] == 0:
                name = data[pos:end].decode('ascii')
                # Verify it's a plausible name (not random ASCII)
                if name[0].isupper() or name[0].islower():
                    names.append((pos, name))
                    pos = end + 1
                    continue
        pos += 1

    print(f"\nFound {len(names)} named entries:")
    for i, (offset, name) in enumerate(names):
        # Dump 8 uint32s before the name
        pre_start = max(0, offset - 32)
        pre_data = data[pre_start:offset]
        pre_u32 = struct.unpack_from(f'<{len(pre_data)//4}I', pre_data)

        # Dump 8 uint32s after the name (skip name bytes)
        name_end = offset + len(name) + 1
        name_end = (name_end + 3) & ~3  # align to 4
        post_data = data[name_end:name_end+32]
        post_u32 = struct.unpack_from(f'<{min(8, len(post_data)//4)}I', post_data)

        stride = names[i+1][0] - offset if i + 1 < len(names) else 0
        print(f"\n  [{i:2d}] '{name}' @ 0x{offset:06X} (stride to next: 0x{stride:X})")
        print(f"       pre:  {' '.join(f'{x:08X}' for x in pre_u32[-8:])}")
        print(f"       post: {' '.join(f'{x:08X}' for x in post_u32)}")

    # Look at the structure between entries
    # Check if there's a WAVEFORMATEX-like structure (format tag, channels, rate)
    # in the post-name data
    print(f"\n--- Checking post-name data for audio format info ---")
    for i, (offset, name) in enumerate(names[:5]):
        name_end = offset + len(name) + 1
        name_end = (name_end + 3) & ~3
        # Print raw hex of 64 bytes after name
        chunk = data[name_end:name_end+64]
        print(f"\n  '{name}' post-name hex:")
        for j in range(0, len(chunk), 16):
            hex_str = ' '.join(f'{b:02X}' for b in chunk[j:j+16])
            ascii_str = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk[j:j+16])
            print(f"    {name_end+j:06X}: {hex_str}  {ascii_str}")

    # Look for where the actual audio data block starts
    # It's probably after all entries, look for a large block of non-zero data
    print(f"\n--- Looking for audio data start ---")
    last_name_offset = names[-1][0] if names else 0
    search_start = last_name_offset + 0x80
    # Find first big non-zero block
    for pos in range(search_start, min(len(data), search_start + 0x10000), 0x100):
        chunk = data[pos:pos+256]
        nonzero = sum(1 for b in chunk if b != 0)
        if nonzero > 200:  # mostly non-zero = audio data
            print(f"  Dense data at 0x{pos:06X} ({nonzero}/256 non-zero)")
            # Print first 32 bytes
            print(f"  {data[pos:pos+32].hex()}")
            break

if __name__ == '__main__':
    path = sys.argv[1] if len(sys.argv) > 1 else "Burnout 3 Takedown/sound/Fe.awd"
    analyze_awd(path)
