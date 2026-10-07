"""
Capture texture offsets from fresh push buffer data + PGRAPH registers.
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

    # Read PGRAPH texture registers directly from NV2A MMIO
    # PGRAPH base = 0xFD400000
    # Texture registers at PGRAPH + 0x1B00 (stage 0), +0x40 per stage
    print("\n=== PGRAPH Texture Registers (current state) ===")
    pgraph = 0xFD400000
    for stage in range(4):
        base = 0x1B00 + stage * 0x40
        offset_data = client.read_memory(pgraph + base, 4)
        format_data = client.read_memory(pgraph + base + 4, 4)
        control_data = client.read_memory(pgraph + base + 8, 4)
        addr_data = client.read_memory(pgraph + base + 0x0C, 4)  # control1
        filter_data = client.read_memory(pgraph + base + 0x10, 4)
        rect_data = client.read_memory(pgraph + base + 0x14, 4)

        off = u32(offset_data)
        fmt = u32(format_data)
        ctl = u32(control_data)
        flt = u32(filter_data)
        rct = u32(rect_data)

        color_fmt = (fmt >> 8) & 0xFF
        width = (rct >> 16) & 0xFFFF
        height = rct & 0xFFFF
        enabled = (ctl >> 30) & 1

        print(f"  Stage {stage}: offset={hex32(off)} format={hex32(fmt)} (color=0x{color_fmt:02X})")
        print(f"           control={hex32(ctl)} enabled={enabled}")
        print(f"           filter={hex32(flt)} rect={width}x{height}")

    # Now read fresh push buffer (find current DMA_PUT/GET to locate recent commands)
    print("\n=== PFIFO DMA State ===")
    pfifo_put = u32(client.read_memory(0xFD002000 + 0x1240, 4))
    pfifo_get = u32(client.read_memory(0xFD002000 + 0x1244, 4))
    print(f"  DMA_PUT: {hex32(pfifo_put)}")
    print(f"  DMA_GET: {hex32(pfifo_get)}")

    # Read render context for push buffer pointers
    rc = client.read_memory(0x0035D6A0, 0x50)
    pb_base_phys = u32(rc, 0x24)  # Push buffer base (physical)
    pb_write_off = u32(rc, 0x44)  # Write offset
    print(f"  PB base: {hex32(pb_base_phys)}")
    print(f"  PB write offset: {hex32(pb_write_off)}")

    # Read a large chunk centered around recent activity
    # Read 64KB from base to capture full frame
    print(f"\n=== Reading 64KB push buffer from {hex32(pb_base_phys)} ===")
    pb_data = client.read_memory(pb_base_phys, 0x10000)

    # Scan for ALL method 0x1B00 (SET_TEXTURE_OFFSET) in the push buffer
    print("\n=== All texture offset commands in push buffer ===")
    pos = 0
    dwords = len(pb_data) // 4
    tex_offset_values = []
    tex_format_values = []

    while pos < dwords:
        header = u32(pb_data, pos * 4)
        if header == 0:
            pos += 1
            continue

        if (header & 0xE0030003) == 0:  # Increasing
            count = (header >> 18) & 0x7FF
            method = header & 0x1FFC
            if count == 0 or pos + 1 + count > dwords:
                pos += 1
                continue

            # Check if this batch starts at a texture method
            if method == 0x1B00 and count >= 2:
                tex_off = u32(pb_data, (pos + 1) * 4)
                tex_fmt = u32(pb_data, (pos + 2) * 4)
                color_fmt = (tex_fmt >> 8) & 0xFF
                tex_offset_values.append(tex_off)
                tex_format_values.append(tex_fmt)
                print(f"  PB+{pos*4:#06x}: TEX0 offset={hex32(tex_off)} format={hex32(tex_fmt)} (color=0x{color_fmt:02X})")

            # Also check stage 1-3
            for stg_base in (0x1B40, 0x1B80, 0x1BC0):
                if method == stg_base and count >= 2:
                    stage = (stg_base - 0x1B00) // 0x40
                    tex_off = u32(pb_data, (pos + 1) * 4)
                    tex_fmt = u32(pb_data, (pos + 2) * 4)
                    print(f"  PB+{pos*4:#06x}: TEX{stage} offset={hex32(tex_off)} format={hex32(tex_fmt)}")

            pos += 1 + count

        elif (header & 0xE0030003) == 0x40000000:  # Non-increasing
            count = (header >> 18) & 0x7FF
            if count == 0 or pos + 1 + count > dwords:
                pos += 1
                continue
            pos += 1 + count
        else:
            pos += 1

    print(f"\nFound {len(tex_offset_values)} texture offset commands")
    unique = sorted(set(tex_offset_values))
    print(f"{len(unique)} unique texture VRAM offsets:")
    for off in unique:
        print(f"  {hex32(off)}")

    # For each unique offset, read first 16 bytes of texture data
    print(f"\n=== Texture data at each VRAM offset ===")
    for off in unique:
        if off == 0:
            continue
        va = 0x80000000 + off
        try:
            data = client.read_memory(va, 32)
            hx = ' '.join(f'{data[j]:02X}' for j in range(min(32, len(data))))
            print(f"  {hex32(off)} (VA {hex32(va)}): {hx}")

            # Also read the NV2A texture descriptor that might be before the data
            # Xbox D3D8 stores texture descriptors in PRAMIN
        except:
            print(f"  {hex32(off)}: READ FAILED")

    # Also read the RW texture dictionary to find what addresses textures were uploaded to
    # RW stores texture objects with their GPU addresses
    # Check if MEM32(texture_ptr + offset) contains the VRAM address
    print(f"\n=== Trying to match TXD textures to VRAM offsets ===")
    # The game's D3D8 texture objects store their VRAM address internally
    # Xbox D3D8 texture struct has the data pointer at offset +0x1C or similar
    # Let's check a known texture to find the pattern

    # Global.txd was loaded — textures are D3D8 objects in game memory
    # The txd_loader creates textures via CreateTexture which allocates VRAM
    # Let's scan the game's texture tracking
    # RW texture dictionary is typically at a known RW global
    # The game loaded textures at boot — check if we can find their VRAM addresses

    print("\nResuming CPU...")
    client.continue_execution()
    client.disconnect()

if __name__ == '__main__':
    main()
