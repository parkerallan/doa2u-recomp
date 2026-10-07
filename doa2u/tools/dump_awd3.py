#!/usr/bin/env python3
"""AWD format decoder - extract and decode Xbox ADPCM to WAV."""
import struct
import sys
import wave
import os

# Xbox ADPCM step table (IMA ADPCM)
STEP_TABLE = [
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31,
    34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143,
    157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544,
    598, 658, 724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707,
    1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871,
    5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635,
    13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
]

INDEX_TABLE = [-1, -1, -1, -1, 2, 4, 6, 8]

def decode_xbox_adpcm_block(block_data, channels=1):
    """Decode one Xbox ADPCM block (36 bytes mono, 72 bytes stereo) to PCM samples."""
    block_size = 36 * channels
    if len(block_data) < block_size:
        return []

    samples = []
    channel_states = []

    # Read predictor header for each channel (4 bytes each)
    for ch in range(channels):
        offset = ch * 36
        predictor = struct.unpack_from('<h', block_data, offset)[0]
        step_index = struct.unpack_from('<H', block_data, offset + 2)[0]
        step_index = min(step_index, 88)
        channel_states.append({'predictor': predictor, 'step_index': step_index})

    # Decode 32 nibbles per channel (= 64 samples per channel, total 65 including header sample)
    samples_per_block = 64  # 32 bytes * 2 nibbles/byte

    for ch in range(channels):
        ch_samples = [channel_states[ch]['predictor']]
        offset = ch * 36 + 4  # Skip 4-byte header
        pred = channel_states[ch]['predictor']
        idx = channel_states[ch]['step_index']

        for byte_i in range(32):
            byte = block_data[offset + byte_i]
            for nibble in range(2):
                if nibble == 0:
                    code = byte & 0x0F
                else:
                    code = (byte >> 4) & 0x0F

                step = STEP_TABLE[idx]
                diff = step >> 3
                if code & 1: diff += step >> 2
                if code & 2: diff += step >> 1
                if code & 4: diff += step
                if code & 8: diff = -diff

                pred = max(-32768, min(32767, pred + diff))
                ch_samples.append(pred)

                idx += INDEX_TABLE[code & 7]
                idx = max(0, min(88, idx))

        channel_states[ch]['samples'] = ch_samples

    # Interleave channels
    if channels == 1:
        return channel_states[0]['samples']
    else:
        result = []
        n = min(len(channel_states[0]['samples']), len(channel_states[1]['samples']))
        for i in range(n):
            result.append(channel_states[0]['samples'][i])
            result.append(channel_states[1]['samples'][i])
        return result


def parse_awd(path):
    with open(path, 'rb') as f:
        data = f.read()

    print(f"File: {path} ({len(data)} bytes)")

    # Header: offset 0x08 = data section offset (little endian)
    data_section_start = struct.unpack_from('<I', data, 8)[0]
    entry_count_hint = struct.unpack_from('<I', data, 12)[0]
    print(f"Data section start: 0x{data_section_start:06X}")
    print(f"Entry count hint: {entry_count_hint}")

    # Find entries by scanning for names (preceded by null byte, followed by null)
    entries = []
    pos = 0x40  # Skip initial header
    while pos < min(data_section_start, len(data)) - 16:
        # Each entry is ~0x84-0x88 bytes
        # The name starts at a position preceded by 0x00
        if data[pos] == 0 and pos + 1 < len(data):
            # Check if next bytes are printable ASCII
            end = pos + 1
            while end < pos + 20 and end < len(data) and 32 <= data[end] < 127:
                end += 1
            name_len = end - pos - 1
            if name_len >= 3 and end < len(data) and data[end] == 0:
                name = data[pos+1:end].decode('ascii')
                if name[0].isalpha():
                    # Read fields around the name
                    # The structure before the name (at name_offset - 12):
                    # [data_offset u32] [entry_self_offset u32] [format_type u32] [padding u32]
                    # [prev_offset u32] [next_entry_start u32] [entry_data_start u32] [padding u32]
                    entry_base = pos + 1 - 12 * 4  # Rough
                    # Actually, let's read relative to name position
                    # pre[-8]: data_offset, pre[-7]: entry_self, pre[-6]: 4, pre[-5]: 0
                    # pre[-4]: prev_link, pre[-3]: next_entry, pre[-2]: ?, pre[-1]: 0
                    pre_offset = pos + 1 - 32
                    if pre_offset >= 0:
                        pre = struct.unpack_from('<8I', data, pre_offset)
                        # post-name: GUID(16), then format info
                        name_end_aligned = ((end + 1 + 3) & ~3)
                        if name_end_aligned + 48 < len(data):
                            post = struct.unpack_from('<12I', data, name_end_aligned)
                            # Format info is at post[4]: sample_rate, post[5]: channels
                            # post[6]: data_size
                            audio_offset = pre[0] + data_section_start
                            sample_rate = post[4]
                            num_channels = post[5]
                            data_size = post[6]

                            # Validate
                            if 4000 <= sample_rate <= 48000 and 1 <= num_channels <= 2:
                                entries.append({
                                    'name': name,
                                    'name_offset': pos + 1,
                                    'audio_offset': audio_offset,
                                    'sample_rate': sample_rate,
                                    'channels': num_channels,
                                    'data_size': data_size,
                                    'format': pre[2],
                                })
        pos += 1

    # Deduplicate by name
    seen = set()
    unique = []
    for e in entries:
        if e['name'] not in seen:
            seen.add(e['name'])
            unique.append(e)
    entries = unique

    print(f"\nParsed {len(entries)} entries:")
    for i, e in enumerate(entries):
        print(f"  [{i:2d}] '{e['name']}': fmt={e['format']} rate={e['sample_rate']} "
              f"ch={e['channels']} size={e['data_size']} data@0x{e['audio_offset']:06X}")

    return data, entries


def extract_wav(data, entry, out_dir):
    """Decode Xbox ADPCM entry to WAV file."""
    name = entry['name']
    offset = entry['audio_offset']
    size = entry['data_size']
    channels = entry['channels']
    sample_rate = entry['sample_rate']

    if offset + size > len(data):
        print(f"  WARNING: {name} data extends beyond file ({offset}+{size} > {len(data)})")
        size = len(data) - offset

    adpcm_data = data[offset:offset + size]

    # Xbox ADPCM: 36 bytes per block per channel = 65 samples per channel
    block_size = 36 * channels
    all_samples = []

    for block_start in range(0, len(adpcm_data) - block_size + 1, block_size):
        block = adpcm_data[block_start:block_start + block_size]
        samples = decode_xbox_adpcm_block(block, channels)
        all_samples.extend(samples)

    if not all_samples:
        print(f"  WARNING: {name} produced no samples")
        return None

    # Write WAV
    out_path = os.path.join(out_dir, f"{name}.wav")
    with wave.open(out_path, 'w') as wf:
        wf.setnchannels(channels)
        wf.setsampwidth(2)  # 16-bit
        wf.setframerate(sample_rate)
        wf.writeframes(struct.pack(f'<{len(all_samples)}h', *all_samples))

    print(f"  Extracted: {name}.wav ({len(all_samples)} samples, {sample_rate} Hz, {channels}ch)")
    return out_path


if __name__ == '__main__':
    path = sys.argv[1] if len(sys.argv) > 1 else "Burnout 3 Takedown/sound/Fe.awd"
    data, entries = parse_awd(path)

    if len(sys.argv) > 2 and sys.argv[2] == '--extract':
        out_dir = sys.argv[3] if len(sys.argv) > 3 else 'extracted_sounds'
        os.makedirs(out_dir, exist_ok=True)
        for entry in entries[:10]:  # Extract first 10
            extract_wav(data, entry, out_dir)
