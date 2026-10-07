"""
Capture render list resource from xemu during menu rendering.

Dumps the render list resource structure to understand how sub_001AD350
reads it and what entries are populated during active menu rendering.

The render list resource is at:
  game_base + 0x12ADB0 + 4 = resource pointer

In xemu: game_base = 0x004A71A0, so render_base = 0x005D1F50
In recomp: game_base = 0x0060EA00, so render_base = 0x007397B0

sub_001AD350 reads:
  - [render_base+0] = state flags
  - [render_base+4] = resource pointer
  - resource[+0x08] = ?
  - resource[+0x14] = priority info
  - resource[+0x24] = render entry table (KEY!)
  - entry_table[+0x04] = sub-table pointer
  - entry_table[ecx*8] = entry descriptors

Usage:
    1. Launch xemu with -s, boot to main menu
    2. Run: py -3 tools/xemu_debug/capture_render_list.py
"""
import sys
import os
import struct
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from xemu_debug.gdb_client import GDBClient


def read32(client, addr):
    data = client.read_memory(addr, 4)
    if data and len(data) >= 4:
        return struct.unpack('<I', data)[0]
    return 0


def dump_mem(client, addr, size, label=""):
    """Dump memory as hex dwords."""
    data = client.read_memory(addr, size)
    if not data or len(data) < size:
        print(f"  Failed to read {size} bytes at 0x{addr:08X}")
        return None
    if label:
        print(f"\n=== {label} (0x{addr:08X}, {size} bytes) ===")
    for i in range(0, size, 16):
        chunk = data[i:min(i+16, size)]
        vals = struct.unpack(f'<{len(chunk)//4}I', chunk)
        hex_str = ' '.join(f'{v:08X}' for v in vals)
        print(f"  +0x{i:03X}: {hex_str}")
    return data


def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    print("\n=== Halting CPU ===")
    client.halt()
    time.sleep(0.3)

    game_state = read32(client, 0x4D53B8)
    cam_ptr = read32(client, 0x4D5370)
    print(f"Game state: {game_state} (5=menus)")
    print(f"Camera ptr: 0x{cam_ptr:08X} (0x4D4008=menus)")

    # Game base in xemu
    game_base = 0x004A71A0
    render_base_addr = game_base + 0x12ADB0  # = 0x005D1F50

    print(f"\n=== Render Base (game_base + 0x12ADB0 = 0x{render_base_addr:08X}) ===")
    dump_mem(client, render_base_addr, 0x40, "Render base structure")

    res_ptr = read32(client, render_base_addr + 4)
    print(f"\nResource pointer [render_base+4] = 0x{res_ptr:08X}")

    if res_ptr != 0 and res_ptr < 0x08000000:
        dump_mem(client, res_ptr, 0x100, f"Resource at 0x{res_ptr:08X}")

        # Key fields
        entry_tbl = read32(client, res_ptr + 0x24)
        print(f"\n  res[+0x08] = 0x{read32(client, res_ptr + 0x08):08X}")
        print(f"  res[+0x14] = 0x{read32(client, res_ptr + 0x14):08X}")
        print(f"  res[+0x24] = 0x{entry_tbl:08X}  (RENDER ENTRY TABLE)")

        if entry_tbl != 0 and entry_tbl < 0x08000000:
            dump_mem(client, entry_tbl, 0x100, f"Render entry table at 0x{entry_tbl:08X}")

            # sub_001AD350 iterates: for each entry at table[ecx*8]
            # Read the iteration bounds from resource
            # Check offsets +0x14 and +0x15 for start/end indices
            res_data = client.read_memory(res_ptr, 0x30)
            if res_data:
                byte_14 = res_data[0x14]
                byte_15 = res_data[0x15]
                print(f"\n  Iteration bounds: [+0x14]={byte_14} [+0x15]={byte_15}")

                # Walk entries: table[+4] = sub-table, sub-table[entry_idx*8] → draw data
                sub_tbl = read32(client, entry_tbl + 4)
                print(f"  entry_table[+4] (sub-table) = 0x{sub_tbl:08X}")
                if sub_tbl != 0 and sub_tbl < 0x08000000:
                    dump_mem(client, sub_tbl, 0x80, f"Sub-table at 0x{sub_tbl:08X}")

                    # Check entry count from entry_table[+0] (uint16)
                    et_data = client.read_memory(entry_tbl, 8)
                    if et_data:
                        entry_count = struct.unpack('<H', et_data[0:2])[0]
                        print(f"\n  Entry count (uint16 at table[0]) = {entry_count}")
        else:
            print("  Entry table is NULL — render list is EMPTY")

    # Also check sub_0003FEE0's call to sub_001AD350 with render_base
    # The gen code uses render_base = 0x7397B0 in recomp (game_base 0x60EA00)
    # In xemu it would be at render_base_addr (0x5D1F50)
    # But sub_0003FEE0 is called from sub_001AE6F0 which may use different base

    # Check the actual sub_001AE6F0 render_base:
    # render_base = MEM32(ebp+8) + 0x12ADB0 where ebp+8 = base_obj
    # In xemu, base_obj should be 0x4A71A0
    # So render_base = 0x4A71A0 + 0x12ADB0 = 0x5D1F50 (same)

    # Also dump the sub_0003D9E0 render state (esi+0x9B0/0x9B8)
    # esi = game render obj = 0x4D6170 in both xemu and recomp
    game_render = 0x4D6170
    print(f"\n=== Game render object (0x{game_render:08X}) ===")
    print(f"  +0x9B0 = 0x{read32(client, game_render + 0x9B0):08X}")
    print(f"  +0x9B8 = 0x{read32(client, game_render + 0x9B8):08X}")
    print(f"  +0x9A8 = 0x{read32(client, game_render + 0x9A8):08X}")
    print(f"  +0x3B0 = 0x{read32(client, game_render + 0x3B0):08X}")
    print(f"  +0x3C0 = 0x{read32(client, game_render + 0x3C0):08X}")

    # Check the D3D device context and what sub_0003FEE0 sees
    dev = read32(client, 0x35FB48)
    print(f"\n=== D3D Device Context ===")
    print(f"  [0x35FB48] = 0x{dev:08X}")
    if dev != 0 and dev < 0x08000000:
        # Check the render list at device+0x9B8
        print(f"  dev+0x9B8 = 0x{read32(client, dev + 0x9B8):08X}")

    # Also check the screen list vtable to see if entries have render data
    scr_list = read32(client, 0x4A1E94)
    print(f"\n=== Screen list ===")
    print(f"  [0x4A1E94] = 0x{scr_list:08X}")
    if scr_list != 0 and scr_list < 0x08000000:
        # Vtable at +0x00
        vt = read32(client, scr_list)
        entries_base = read32(client, scr_list + 0x10 + 0xC)
        entry_count = read32(client, scr_list + 0x10 + 0x10)
        print(f"  vtable = 0x{vt:08X}")
        print(f"  entries_base = 0x{entries_base:08X}")
        print(f"  entry_count = {entry_count}")

        # Show first few active entries
        if entries_base != 0 and entries_base < 0x08000000 and entry_count > 0:
            shown = 0
            for i in range(min(entry_count, 600)):
                ent_addr = entries_base + i * 0x20
                flag = client.read_memory(ent_addr + 0x1E, 1)
                if flag and flag[0] == 2:  # flag=2 = active
                    vt_val = read32(client, ent_addr)
                    name_data = client.read_memory(ent_addr + 4, 0x1A)
                    name = ""
                    if name_data:
                        for b in name_data:
                            if b == 0: break
                            if 0x20 <= b < 0x7F: name += chr(b)
                            else: break
                    if shown < 10:
                        print(f"    [{i}] vt=0x{vt_val:08X} flag=2 name='{name}'")
                    shown += 1
            print(f"  Total active entries (flag=2): {shown}")

    print("\n=== Resuming CPU ===")
    client.continue_execution()
    client.disconnect()
    print("Done!")


if __name__ == '__main__':
    main()
