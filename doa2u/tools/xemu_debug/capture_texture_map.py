"""
Capture NV2A texture offset→name mapping from xemu.

For each draw batch in the push buffer, records what texture offset
is set in the NV2A PGRAPH registers. Then reads the texture data at
those VRAM offsets to identify which Global.txd entry they correspond to.

Strategy: Read PGRAPH texture state registers directly from NV2A MMIO.
The texture offset register at PGRAPH+0x1B00 contains the VRAM offset
of the currently bound texture. We can match these against the known
texture upload addresses.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]
def hex32(v): return f"0x{v:08X}"

def main():
    client = GDBClient('localhost', 1234)
    client.connect()
    print("Halting CPU...")
    client.halt()
    time.sleep(0.3)

    # ── 1. Re-read the push buffer to find per-batch texture offsets ──
    # The push buffer has INC method=0x1B00 count=2 before each textured draw.
    # 0x1B00 = SET_TEXTURE_OFFSET, 0x1B04 = SET_TEXTURE_FORMAT
    print("\n=== Scanning push buffer for per-batch texture offsets ===")
    pb_base = 0x81FC3000
    pb_data = client.read_memory(pb_base, 0x8000)

    # Parse push buffer and extract texture offsets per draw batch
    pos = 0
    dwords = len(pb_data) // 4
    draws = []
    current_tex_offset = [0, 0, 0, 0]  # 4 stages
    current_tex_format = [0, 0, 0, 0]
    draw_idx = 0

    while pos < dwords:
        header = u32(pb_data, pos * 4)
        if header == 0:
            pos += 1
            continue

        # Increasing method
        if (header & 0xE0030003) == 0:
            count = (header >> 18) & 0x7FF
            method = header & 0x1FFC
            if count == 0 or pos + 1 + count > dwords:
                pos += 1
                continue

            for i in range(count):
                m = method + i * 4
                p = u32(pb_data, (pos + 1 + i) * 4)

                # Track texture offset (0x1B00 + stage*0x40)
                if m in (0x1B00, 0x1B40, 0x1B80, 0x1BC0):
                    stage = (m - 0x1B00) // 0x40
                    current_tex_offset[stage] = p

                # Track texture format (0x1B04 + stage*0x40)
                if m in (0x1B04, 0x1B44, 0x1B84, 0x1BC4):
                    stage = (m - 0x1B04) // 0x40
                    current_tex_format[stage] = p

                # Track BEGIN_END
                if m == 0x17FC and p != 0:
                    draw_idx += 1

                if m == 0x17FC and p == 0:
                    # END — record this draw's texture state
                    draws.append({
                        'idx': draw_idx,
                        'tex_offset': list(current_tex_offset),
                        'tex_format': list(current_tex_format),
                        'pb_offset': pos * 4,
                    })

            pos += 1 + count

        # Non-increasing method
        elif (header & 0xE0030003) == 0x40000000:
            count = (header >> 18) & 0x7FF
            method = header & 0x1FFC
            if count == 0 or pos + 1 + count > dwords:
                pos += 1
                continue
            pos += 1 + count
        else:
            pos += 1

    print(f"Found {len(draws)} draw batches with texture state:")
    unique_offsets = set()
    for d in draws:
        tex0 = d['tex_offset'][0]
        fmt0 = d['tex_format'][0]
        unique_offsets.add(tex0)
        # Decode format: bits 8-15 = color format code
        color_fmt = (fmt0 >> 8) & 0xFF
        fmt_names = {0x06: 'A8R8G8B8', 0x07: 'X8R8G8B8', 0x0C: 'DXT1',
                     0x0E: 'DXT3', 0x0F: 'DXT5', 0x0B: 'A1R5G5B5',
                     0x29: 'A8', 0x1A: 'A8L8'}
        fmt_name = fmt_names.get(color_fmt, f'0x{color_fmt:02X}')
        print(f"  Draw #{d['idx']:2d}: tex0_offset={hex32(tex0)} format={hex32(fmt0)} ({fmt_name})")

    print(f"\n{len(unique_offsets)} unique texture offsets:")
    for off in sorted(unique_offsets):
        print(f"  {hex32(off)}")

    # ── 2. For each unique offset, read the first 64 bytes of texture data ──
    # These are VRAM offsets — on Xbox, VRAM is at physical 0x00000000
    # In xemu, VRAM is accessible at virtual address = physical address + 0x80000000
    print(f"\n=== Reading texture data at each offset ===")
    tex_data = {}
    for off in sorted(unique_offsets):
        if off == 0:
            continue
        # VRAM physical address — accessible via 0x80000000 + offset on Xbox
        vram_va = 0x80000000 + off
        try:
            data = client.read_memory(vram_va, 64)
            # Check if it looks like DXT or raw pixel data
            header_u32 = [u32(data, i*4) for i in range(4)]
            tex_data[off] = {
                'va': vram_va,
                'header': header_u32,
                'raw': data[:32],
            }
            hx = ' '.join(f'{data[j]:02X}' for j in range(min(32, len(data))))
            print(f"  {hex32(off)} (VA {hex32(vram_va)}): {hx}")
        except Exception as e:
            print(f"  {hex32(off)}: READ FAILED: {e}")

    # ── 3. Try to match texture offsets against known TXD textures ──
    # The game uploads Global.txd textures to VRAM during loading.
    # We can find the upload addresses by searching for texture data patterns.
    # Alternative: read the D3D8 device's texture tracking structures.

    # Read the D3D8 device texture pool — Xbox D3D8 tracks allocated textures
    # The device at MEM32(0x35FB48) has internal texture management
    print(f"\n=== Searching for texture management structures ===")

    # Check RenderWare's texture dictionary at known addresses
    # RW stores loaded textures with their VRAM addresses
    # The TXD was loaded and textures were created — RW tracks them

    # Let's check if the game has a font/text texture
    # Common Xbox game pattern: font atlas uploaded to specific VRAM region
    # Check addresses near the captured texture offsets

    # Read the first unique offset's surrounding VRAM area
    for off in sorted(unique_offsets):
        if off == 0:
            continue
        # Check 256 bytes before the texture for a header/descriptor
        if off >= 256:
            pre_data = client.read_memory(0x80000000 + off - 64, 64)
            hx = ' '.join(f'{pre_data[j]:02X}' for j in range(min(32, len(pre_data))))
            print(f"  Pre-{hex32(off)}: {hx}")
        break  # Just check first one

    print("\nResuming CPU...")
    client.continue_execution()
    client.disconnect()

    # ── 4. Generate C mapping table ──
    print(f"\n=== C Mapping Table ===")
    print("static const struct { uint32_t nv2a_offset; const char *txd_name; } texture_map[] = {")
    for off in sorted(unique_offsets):
        if off == 0:
            continue
        print(f"    {{ 0x{off:08X}, \"UNKNOWN\" }},  /* TODO: identify */")
    print("};")

if __name__ == '__main__':
    main()
