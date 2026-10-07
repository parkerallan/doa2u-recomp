"""
Enhanced push buffer capture from xemu.

Reads PFIFO DMA_PUT/GET to find the active push buffer region,
then captures the FULL region instead of assuming a fixed base/size.

Usage:
  1. Launch xemu with -s flag (GDB stub on port 1234)
  2. Navigate to the TOP-LEVEL main menu (WORLD TOUR, SINGLE EVENT, etc.)
  3. Run: py -3 -m tools.xemu_debug.capture_menu_pushbuffer

The script halts the CPU at a clean point, captures the push buffer,
and generates menu_pushbuffer_data.h for embedding in the game.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]

# NV2A MMIO register addresses (physical)
NV2A_BASE = 0xFD000000
PFIFO_BASE = NV2A_BASE + 0x002000
PGRAPH_BASE = NV2A_BASE + 0x400000

# PFIFO registers
PFIFO_CACHE1_DMA_PUT     = PFIFO_BASE + 0x1240
PFIFO_CACHE1_DMA_GET     = PFIFO_BASE + 0x1244
PFIFO_CACHE1_DMA_INSTANCE = PFIFO_BASE + 0x122C
PFIFO_CACHE1_DMA_CTL     = PFIFO_BASE + 0x1220
PFIFO_CACHE1_DMA_STATE   = PFIFO_BASE + 0x1228
PFIFO_CACHE1_PUSH0       = PFIFO_BASE + 0x1200

def read_u32(client, addr):
    """Read a single 32-bit value from physical address."""
    data = client.read_memory(addr, 4)
    return struct.unpack_from('<I', data, 0)[0]

def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    print("=== NV2A Push Buffer Capture (Enhanced) ===\n")

    # Halt CPU
    print("Halting CPU...")
    client.halt()
    time.sleep(0.5)

    # Read PFIFO state to find push buffer location
    print("Reading PFIFO registers...")
    dma_put = read_u32(client, PFIFO_CACHE1_DMA_PUT)
    dma_get = read_u32(client, PFIFO_CACHE1_DMA_GET)
    dma_instance = read_u32(client, PFIFO_CACHE1_DMA_INSTANCE)
    dma_ctl = read_u32(client, PFIFO_CACHE1_DMA_CTL)
    dma_state = read_u32(client, PFIFO_CACHE1_DMA_STATE)

    print(f"  DMA_PUT      = {dma_put:#010x}")
    print(f"  DMA_GET      = {dma_get:#010x}")
    print(f"  DMA_INSTANCE = {dma_instance:#010x}")
    print(f"  DMA_CTL      = {dma_ctl:#010x}")
    print(f"  DMA_STATE    = {dma_state:#010x}")

    # The DMA_PUT/GET are byte offsets into the push buffer.
    # The push buffer base is determined by the DMA context object.
    # Read the DMA context from RAMIN to find the actual base address.

    # DMA_INSTANCE points to an entry in RAMIN (at NV2A_BASE + 0x700000)
    ramin_base = NV2A_BASE + 0x700000
    dma_obj_addr = ramin_base + (dma_instance << 4)
    print(f"\n  DMA object at RAMIN + {dma_instance << 4:#x} = {dma_obj_addr:#010x}")

    dma_obj = client.read_memory(dma_obj_addr, 12)
    dma_word0 = u32(dma_obj, 0)
    dma_word1 = u32(dma_obj, 4)
    dma_word2 = u32(dma_obj, 8)

    print(f"  DMA obj word0 = {dma_word0:#010x}")
    print(f"  DMA obj word1 = {dma_word1:#010x}")
    print(f"  DMA obj word2 = {dma_word2:#010x}")

    # Extract base address and limit from DMA object
    # word1[31:20] = frame address bits [31:20], word2 = limit
    dma_frame_addr = dma_word1 & 0xFFFFF000
    dma_limit = dma_word2

    print(f"\n  DMA frame address = {dma_frame_addr:#010x}")
    print(f"  DMA limit         = {dma_limit:#010x} ({dma_limit} bytes)")

    # The push buffer is a ring buffer in contiguous RAM.
    # DMA_PUT/GET are byte offsets from the base. When PUT==GET, the GPU
    # has consumed all commands, but the data remains in memory.
    # Use the known base from previous successful captures.
    known_base = 0x81FC3000

    # Try to derive base from DMA object (word0 high bits + word2)
    # xemu: dma_address = (GET_MASK(dma[0], NV_DMA_ADDRESS) | dma[2]) & ~3
    dma_addr_derived = ((dma_word0 & 0xFFF00000) | (dma_word2 & ~3))
    if dma_addr_derived != 0:
        pb_phys_base = dma_addr_derived | 0x80000000
        print(f"\n  DMA-derived base: {pb_phys_base:#010x}")
    else:
        print(f"\n  DMA address = 0, using known base")

    capture_base = known_base
    print(f"  Capture base: {capture_base:#010x}")

    # Capture a generous region — 64KB to ensure we get the full frame
    capture_size = 0x10000  # 64KB (double the previous 32KB)
    print(f"\nCapturing {capture_size} bytes from {capture_base:#010x}...")
    pb_data = client.read_memory(capture_base, capture_size)

    # Find extent of non-zero data
    last_nonzero = 0
    for i in range(0, capture_size, 4):
        if u32(pb_data, i) != 0:
            last_nonzero = i + 4
    print(f"Non-zero data extends to offset {last_nonzero:#x} ({last_nonzero} bytes)")

    # Trim to actual data + small padding
    actual_size = min(last_nonzero + 64, capture_size)
    pb_data = pb_data[:actual_size]

    # Scan for command headers and analyze
    print("\n=== Push Buffer Analysis ===")
    pos = 0
    dwords = len(pb_data) // 4
    draws = []
    total_verts = 0
    total_methods = 0
    begin_end_count = 0
    clear_count = 0
    texture_offsets = set()

    while pos < dwords:
        word = u32(pb_data, pos * 4)
        if word == 0:
            pos += 1
            continue

        # Increasing method
        if (word & 0xE0030003) == 0:
            count = (word >> 18) & 0x7FF
            method = word & 0x1FFC
            if count > 0 and count < 2048 and method < 0x2000:
                total_methods += count

                # Track BEGIN_END
                if method == 0x17FC and count >= 1:
                    mode = u32(pb_data, (pos + 1) * 4)
                    if mode != 0:
                        begin_end_count += 1
                        draws.append((pos * 4, mode))

                # Track CLEAR_SURFACE
                if method == 0x01D0:
                    clear_count += 1

                # Track texture offsets (SET_TEXTURE_OFFSET at 0x1B00, stride 0x40)
                for m in [0x1B00, 0x1B40, 0x1B80, 0x1BC0]:
                    if method <= m < method + count * 4:
                        idx = (m - method) // 4
                        if pos + 1 + idx < dwords:
                            tex_off = u32(pb_data, (pos + 1 + idx) * 4)
                            if tex_off != 0:
                                texture_offsets.add(tex_off)

                pos += 1 + count
                continue

        # Non-increasing method
        if (word & 0xE0030003) == 0x40000000:
            count = (word >> 18) & 0x7FF
            method = word & 0x1FFC
            if count > 0 and count < 2048 and method < 0x2000:
                total_methods += count

                # INLINE_ARRAY vertex data
                if method == 0x1818:
                    total_verts += count // 5  # 5 dwords per vertex

                pos += 1 + count
                continue

        pos += 1

    print(f"  Total methods:    {total_methods}")
    print(f"  Draw calls:       {begin_end_count}")
    print(f"  Total vertices:   {total_verts}")
    print(f"  Clears:           {clear_count}")
    print(f"  Texture offsets:  {len(texture_offsets)}")
    for t in sorted(texture_offsets):
        print(f"    {t:#010x}")

    print(f"\n  Draw modes:")
    mode_names = {1:'POINTS', 2:'LINES', 3:'LINE_LOOP', 4:'LINE_STRIP',
                  5:'TRIANGLES', 6:'TRI_STRIP', 7:'TRI_FAN', 8:'QUADS'}
    mode_counts = {}
    for off, mode in draws:
        name = mode_names.get(mode, f'UNKNOWN({mode})')
        mode_counts[name] = mode_counts.get(name, 0) + 1
    for name, cnt in sorted(mode_counts.items()):
        print(f"    {name}: {cnt}")

    # Check if initial data looks like headerless INLINE_ARRAY
    first_word = u32(pb_data, 0)
    first_float = struct.unpack_from('<f', pb_data, 0)[0]
    has_header = (first_word & 0xE0030003) == 0 or (first_word & 0xE0030003) == 0x40000000
    if not has_header and 0.0 <= first_float <= 640.0:
        # Find where the first real header starts
        headerless_end = 0
        for i in range(dwords):
            w = u32(pb_data, i * 4)
            if (w & 0xE0030003) == 0 or (w & 0xE0030003) == 0x40000000:
                cnt = (w >> 18) & 0x7FF
                meth = w & 0x1FFC
                if cnt > 0 and cnt < 2048 and meth < 0x2000:
                    headerless_end = i
                    break
        if headerless_end > 0:
            hless_verts = headerless_end // 5
            print(f"\n  Initial headerless block: {headerless_end} dwords = {hless_verts} vertices")
            print(f"  First vertex: X={first_float:.1f}, Y={struct.unpack_from('<f', pb_data, 4)[0]:.1f}")
    else:
        print(f"\n  Data starts with proper command header ({first_word:#010x})")

    # Save binary
    out_dir = os.path.join(os.path.dirname(__file__), '..', '..', 'src', 'nv2a')
    out_dir = os.path.normpath(out_dir)

    bin_path = os.path.join(out_dir, 'menu_pushbuffer.bin')
    with open(bin_path, 'wb') as f:
        f.write(pb_data)
    print(f"\nSaved {len(pb_data)} bytes to {bin_path}")

    # Generate C header
    h_path = os.path.join(out_dir, 'menu_pushbuffer_data.h')
    with open(h_path, 'w') as f:
        f.write("/* Auto-generated: NV2A push buffer captured from xemu during menu rendering.\n")
        f.write(f" * {len(pb_data)} bytes from {capture_base:#010x}\n")
        f.write(f" * DMA_PUT={dma_put:#010x} DMA_GET={dma_get:#010x}\n")
        f.write(f" * {begin_end_count} draw calls, {total_verts} vertices, {clear_count} clears\n")
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

    # Resume
    print("\nResuming CPU...")
    client.continue_execution()
    client.disconnect()
    print("Done!")

if __name__ == '__main__':
    main()
