"""
Multi-state menu push buffer capture from xemu.

Captures push buffer data at different menu states for multi-state replay.
The operator navigates to each menu state in xemu, then presses Enter here
to capture that state's push buffer.

Also scans for the menu selection/screen index in Xbox memory.

Usage:
  1. Launch xemu with -s flag
  2. Boot Burnout 3 to main menu
  3. Run: py -3 tools/xemu_debug/capture_multi_menu.py
  4. Follow prompts to navigate and capture each menu state
"""
import os, sys, struct, time, json
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

NV2A_BASE = 0xFD000000
PFIFO_BASE = NV2A_BASE + 0x002000
PFIFO_CACHE1_DMA_PUT = PFIFO_BASE + 0x1240
PFIFO_CACHE1_DMA_GET = PFIFO_BASE + 0x1244

def r32(client, addr):
    data = client.read_memory(addr, 4)
    return struct.unpack('<I', data)[0] if data and len(data) >= 4 else 0

def capture_pushbuffer(client):
    """Capture the current push buffer contents."""
    dma_put = r32(client, PFIFO_CACHE1_DMA_PUT)
    dma_get = r32(client, PFIFO_CACHE1_DMA_GET)

    # Read the DMA context to find base address
    # The PUT/GET are offsets from the push buffer base
    # Base is typically at the DMA instance address
    dma_instance = r32(client, PFIFO_BASE + 0x122C)

    # Read RAMHT/RAMIN to find the actual push buffer base
    # The instance is an index into RAMIN (at physical 0x00000000 + offset)
    ramin_addr = (dma_instance >> 4) * 0x10  # RAMIN offset

    # Read DMA object from RAMIN
    dma_obj = client.read_memory(ramin_addr, 0x10)
    if dma_obj and len(dma_obj) >= 0x10:
        dma_limit = struct.unpack('<I', dma_obj[4:8])[0]
        dma_frame = struct.unpack('<I', dma_obj[8:12])[0]
        pb_base_phys = dma_frame & 0xFFFFF000
    else:
        pb_base_phys = 0

    print(f"  DMA_PUT={dma_put:#010x} DMA_GET={dma_get:#010x}")
    print(f"  DMA_INSTANCE={dma_instance:#010x} PB_BASE_PHYS={pb_base_phys:#010x}")

    # Calculate the push buffer data range
    if dma_put > dma_get:
        pb_size = dma_put - dma_get
        pb_addr = pb_base_phys + dma_get
    else:
        # PUT wrapped around, capture from base to PUT
        pb_size = dma_put
        pb_addr = pb_base_phys

    # Also capture the full "frame" from GET to PUT
    # But since we halt mid-frame, capture a generous window
    # Use the base+0 to PUT range
    capture_base = pb_base_phys
    capture_size = dma_put

    if capture_size == 0 or capture_size > 256 * 1024:
        # Fallback: capture from a known offset
        print(f"  WARNING: capture_size={capture_size}, using 64KB from base")
        capture_size = 64 * 1024

    print(f"  Capturing {capture_size} bytes from {capture_base:#010x}...")

    # Read in chunks
    data = b''
    chunk_size = 0x400
    for off in range(0, capture_size, chunk_size):
        remaining = min(chunk_size, capture_size - off)
        chunk = client.read_memory(capture_base + off, remaining)
        if chunk and len(chunk) == remaining:
            data += chunk
        else:
            data += b'\x00' * remaining

    return data, capture_base, dma_put, dma_get

def scan_menu_state(client, label=""):
    """Read various potential menu state addresses."""
    addrs = {
        'game_state': 0x4D53B8,
        'cam_ptr': 0x4D5370,
        'frontend_phase': 0x60EA00 + 0x2E1E8,  # outer state field
        'screen_flag': 0x60EA00 + 0x12B790 - 0x60EA00 + 0x4A71A0,  # B790 in xemu base
    }

    # Known screen entry addresses
    results = {}
    for name, addr in addrs.items():
        val = r32(client, addr)
        results[name] = val

    # Also scan the screen list for active entries
    scr_list = r32(client, 0x4A1E94)
    if scr_list and scr_list < 0x08000000:
        entries_base = r32(client, scr_list + 0x10 + 0xC)
        entry_count = r32(client, scr_list + 0x10 + 0x10)
        results['screen_entries'] = entry_count

        # Find active entries and their vtables
        active = []
        if entries_base and entries_base < 0x08000000 and entry_count < 2000:
            for i in range(min(entry_count, 600)):
                flag = client.read_memory(entries_base + i * 0x20 + 0x1E, 1)
                if flag and flag[0] == 2:
                    vt = r32(client, entries_base + i * 0x20)
                    active.append((i, vt))
        results['active_entries'] = len(active)

    # Scan some interesting areas for menu index
    # These are common patterns for menu selection tracking
    for addr in [0x557A70, 0x55609E, 0x4D4008, 0x60E040 + 0x14C,
                 0x60E040 + 0x130, 0x60E040 + 0x13C, 0x60E040 + 0x140]:
        val = r32(client, addr)
        if val < 20:  # Likely a small index
            results[f'idx_{addr:08X}'] = val

    print(f"\n  Menu state{f' ({label})' if label else ''}:")
    for k, v in sorted(results.items()):
        if isinstance(v, int):
            print(f"    {k}: {v} (0x{v:X})")

    return results

def save_pushbuffer(data, name, pb_base, dma_put):
    """Save push buffer data as C header."""
    out_dir = os.path.join("src", "nv2a")
    dwords = len(data) // 4

    header_path = os.path.join(out_dir, f"menu_pb_{name}.h")
    with open(header_path, 'w') as f:
        f.write(f"/* Push buffer capture: {name} */\n")
        f.write(f"/* Base: {pb_base:#010x}, PUT: {dma_put:#010x}, {len(data)} bytes */\n\n")
        f.write(f"#define MENU_PB_{name.upper()}_DWORDS {dwords}\n\n")
        f.write(f"static const uint32_t menu_pb_{name}[] = {{\n")
        for i in range(0, len(data), 16):
            chunk = data[i:min(i+16, len(data))]
            vals = struct.unpack(f'<{len(chunk)//4}I', chunk)
            f.write('    ' + ', '.join(f'0x{v:08X}' for v in vals) + ',\n')
        f.write("};\n")

    print(f"  Saved: {header_path} ({dwords} dwords)")
    return header_path

def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    captures = {}

    menu_states = [
        ("main_menu", "Main menu (WORLD TOUR highlighted at top)"),
        ("main_sel1", "Main menu with SINGLE EVENT highlighted (press DOWN once)"),
        ("main_sel2", "Main menu with MULTIPLAYER highlighted (press DOWN twice)"),
        ("world_tour", "WORLD TOUR sub-menu (press A on WORLD TOUR)"),
        ("single_event", "SINGLE EVENT sub-menu (go back, select SINGLE EVENT)"),
        ("single_race", "RACE option in SINGLE EVENT"),
    ]

    for name, description in menu_states:
        print(f"\n{'='*60}")
        print(f"STATE: {name}")
        print(f"Navigate xemu to: {description}")
        print(f"Then press ENTER here to capture...")
        input()

        print("Halting CPU...")
        client.halt()
        time.sleep(0.5)

        # Scan menu state
        state = scan_menu_state(client, name)

        # Capture push buffer
        data, pb_base, dma_put, dma_get = capture_pushbuffer(client)

        if len(data) > 0:
            path = save_pushbuffer(data, name, pb_base, dma_put)
            captures[name] = {
                'path': path,
                'size': len(data),
                'state': {k: v for k, v in state.items() if isinstance(v, int)},
            }

        print("\nResuming CPU...")
        client.continue_execution()
        time.sleep(0.5)

    # Save capture manifest
    manifest_path = os.path.join("tools", "xemu_debug", "snapshots", "menu_captures.json")
    with open(manifest_path, 'w') as f:
        json.dump(captures, f, indent=2)
    print(f"\nManifest saved: {manifest_path}")

    client.disconnect()
    print("\nDone! All menu states captured.")

if __name__ == '__main__':
    main()
