#!/usr/bin/env python3
"""
Quick AWD (Audio Wave Dictionary) format analyzer for Burnout 3.

AWD is a RenderWare binary stream format containing named sound entries.
Each entry has: name, format info, and raw audio data (Xbox ADPCM or PCM).
"""
import struct
import sys
import os

def read_awd(path):
    with open(path, 'rb') as f:
        data = f.read()

    print(f"File: {path} ({len(data)} bytes)")
    print(f"Header: {data[:16].hex()}")

    # The AWD format appears to be:
    # - RW binary stream header (type, size, version)
    # - Section entries with names and audio data

    # Scan for named entries by looking for the pattern:
    # [offset][size][...][name (null-terminated ASCII)]
    # Names are at predictable intervals with known structure

    entries = []
    i = 0
    while i < len(data) - 32:
        # Look for printable ASCII strings that could be sound names
        # Names appear to be 12 bytes (null-padded) at specific offsets
        candidate = data[i:i+12]
        if all(32 <= b < 127 or b == 0 for b in candidate):
            # Find the null terminator
            null_pos = candidate.find(b'\x00')
            if null_pos > 3:
                name = candidate[:null_pos].decode('ascii')
                if name.isalnum() or any(c in name for c in '_-'):
                    # Check if this looks like a valid entry
                    # Look backwards for size/offset fields
                    if i >= 12:
                        pre = struct.unpack_from('<III', data, i - 12)
                        entries.append({
                            'name': name,
                            'offset': i,
                            'pre_fields': pre,
                        })
        i += 1

    # Filter: keep only entries that look like real sound names
    # (remove false positives from data sections)
    seen_names = set()
    unique_entries = []
    for e in entries:
        if e['name'] not in seen_names and len(e['name']) >= 4:
            seen_names.add(e['name'])
            unique_entries.append(e)

    print(f"\nFound {len(unique_entries)} unique named entries:")
    for e in unique_entries[:50]:
        print(f"  @0x{e['offset']:06X}: '{e['name']}' (pre: {e['pre_fields'][0]:08X} {e['pre_fields'][1]:08X} {e['pre_fields'][2]:08X})")

    # Now try to understand the RW binary stream structure
    # RW sections: uint32 type, uint32 size, uint32 version
    print(f"\n--- RW Stream Sections ---")
    pos = 0
    section_count = 0
    while pos < min(len(data), 0x2000) and section_count < 30:
        if pos + 12 > len(data):
            break
        sec_type, sec_size, sec_ver = struct.unpack_from('<III', data, pos)
        # Valid RW section types are typically < 0x1000
        if sec_type < 0x1000 and sec_size < len(data) and sec_ver != 0:
            print(f"  @0x{pos:06X}: type=0x{sec_type:04X} size={sec_size:6d} ver=0x{sec_ver:08X}")
            pos += 12  # Enter section (don't skip, scan children)
            section_count += 1
        else:
            pos += 4
            section_count += 1

    # Try another approach: look for Xbox ADPCM headers
    # Xbox ADPCM format tag = 0x0069
    print(f"\n--- Looking for WAVEFORMATEX structures ---")
    for i in range(0, min(len(data), 0x10000) - 18, 2):
        fmt_tag = struct.unpack_from('<H', data, i)[0]
        if fmt_tag in (0x0001, 0x0069):  # PCM or Xbox ADPCM
            channels, sample_rate, avg_bytes, block_align, bits = struct.unpack_from('<HIIHH', data, i + 2)
            if 1 <= channels <= 6 and 4000 <= sample_rate <= 48000 and bits in (4, 8, 16):
                print(f"  @0x{i:06X}: tag=0x{fmt_tag:04X} ch={channels} rate={sample_rate} align={block_align} bits={bits}")

if __name__ == '__main__':
    path = sys.argv[1] if len(sys.argv) > 1 else "Burnout 3 Takedown/sound/Fe.awd"
    read_awd(path)
