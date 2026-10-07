"""
Save the font atlas DXT5 data as a C header for embedding.
256x256 DXT5 = 65536 bytes from VRAM offset 0x021C4100.
"""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

def u32(data, offset=0):
    return struct.unpack_from('<I', data, offset)[0]

def main():
    # Read the saved binary
    with open('font_atlas_dxt5.bin', 'rb') as f:
        data = f.read()

    print(f"Font atlas: {len(data)} bytes")

    # Generate C header
    h_path = os.path.join('src', 'nv2a', 'font_atlas_data.h')
    with open(h_path, 'w') as f:
        f.write("/* Auto-generated: DXT5 font atlas captured from xemu VRAM.\n")
        f.write(f" * 256x256 DXT5, {len(data)} bytes from VRAM offset 0x021C4100\n")
        f.write(" * Used for menu text rendering in Burnout 3.\n")
        f.write(" */\n\n")
        f.write(f"#define FONT_ATLAS_WIDTH 256\n")
        f.write(f"#define FONT_ATLAS_HEIGHT 256\n")
        f.write(f"#define FONT_ATLAS_SIZE {len(data)}\n")
        f.write(f"#define FONT_ATLAS_DWORDS {len(data)//4}\n\n")
        f.write("static const unsigned char font_atlas_dxt5[] = {\n")

        for i in range(0, len(data), 16):
            f.write("    ")
            row = data[i:i+16]
            f.write(', '.join(f'0x{b:02X}' for b in row))
            f.write(',\n')
        f.write("};\n")

    print(f"Saved C header to {h_path}")

if __name__ == '__main__':
    main()
