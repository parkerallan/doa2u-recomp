"""
Save raw push buffer data from xemu to a binary file for replay testing.
Also generates a C header with the data for embedding.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]

def main():
    client = GDBClient('localhost', 1234)
    client.connect()
    print("Halting CPU...")
    client.halt()
    time.sleep(0.3)

    # Read push buffer from base (0x81FC3000) — 32KB to capture a full frame
    pb_base = 0x81FC3000
    pb_size = 0x8000  # 32KB
    print(f"Reading {pb_size} bytes from {pb_base:#010x}...")
    pb_data = client.read_memory(pb_base, pb_size)

    # Find the extent of non-zero data
    last_nonzero = 0
    for i in range(0, pb_size, 4):
        if u32(pb_data, i) != 0:
            last_nonzero = i + 4
    print(f"Non-zero data extends to offset {last_nonzero:#x} ({last_nonzero} bytes)")

    # Trim to actual data + small padding
    actual_size = min(last_nonzero + 64, pb_size)
    pb_data = pb_data[:actual_size]

    # Save binary
    bin_path = os.path.join(os.path.dirname(__file__), '..', '..', 'src', 'nv2a', 'menu_pushbuffer.bin')
    bin_path = os.path.normpath(bin_path)
    with open(bin_path, 'wb') as f:
        f.write(pb_data)
    print(f"Saved {len(pb_data)} bytes to {bin_path}")

    # Generate C header
    h_path = os.path.join(os.path.dirname(__file__), '..', '..', 'src', 'nv2a', 'menu_pushbuffer_data.h')
    h_path = os.path.normpath(h_path)
    with open(h_path, 'w') as f:
        f.write("/* Auto-generated: NV2A push buffer captured from xemu during menu rendering.\n")
        f.write(f" * {len(pb_data)} bytes from {pb_base:#010x}\n")
        f.write(" * Contains INLINE_ARRAY vertex data for menu UI elements.\n")
        f.write(" * Vertex format: float X, float Y, float U, float V, D3DCOLOR (20 bytes/vert)\n")
        f.write(" */\n\n")
        f.write(f"#define MENU_PB_SIZE {len(pb_data)}\n")
        f.write(f"#define MENU_PB_DWORDS {len(pb_data)//4}\n\n")
        f.write("static const uint32_t menu_pushbuffer_data[] = {\n")

        for i in range(0, len(pb_data), 4):
            val = u32(pb_data, i)
            if i % 32 == 0:
                f.write("    ")
            f.write(f"0x{val:08X},")
            if i % 32 == 28:
                f.write("\n")
            else:
                f.write(" ")
        f.write("\n};\n")

    print(f"Saved C header to {h_path}")

    # Also scan for push buffer command headers to find the real frame start
    # Look for BEGIN_END or CLEAR commands
    print("\nScanning for command headers...")
    pos = 0
    dwords = len(pb_data) // 4
    found_headers = []
    while pos < dwords:
        word = u32(pb_data, pos * 4)
        if word == 0:
            pos += 1
            continue
        # Check for increasing method header
        if (word & 0xE0030003) == 0:
            count = (word >> 18) & 0x7FF
            method = word & 0x1FFC
            if count > 0 and count < 2048 and method < 0x2000:
                found_headers.append((pos, 'INC', method, count))
                print(f"  Offset {pos*4:#06x}: INC method={method:#06x} count={count}")
                pos += 1 + count
                continue
        # Check for non-increasing method header
        if (word & 0xE0030003) == 0x40000000:
            count = (word >> 18) & 0x7FF
            method = word & 0x1FFC
            if count > 0 and count < 2048 and method < 0x2000:
                found_headers.append((pos, 'NONINC', method, count))
                if method != 0x1818:  # Don't spam INLINE_ARRAY
                    print(f"  Offset {pos*4:#06x}: NONINC method={method:#06x} count={count}")
                else:
                    print(f"  Offset {pos*4:#06x}: NONINC INLINE_ARRAY count={count}")
                pos += 1 + count
                continue
        pos += 1

    print(f"\nFound {len(found_headers)} command headers")

    client.continue_execution()
    client.disconnect()

if __name__ == '__main__':
    main()
