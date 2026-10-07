"""
Menu rendering pipeline capture for Burnout 3 in xemu.

Captures the key data structures needed to connect the original menu
rendering pipeline in our recompiled version:
  1. Screen list vtable and methods
  2. Render context pointer at 0x35FB48
  3. Render list structure from sub_0019AE10
  4. Screen entry array contents
  5. Frontend object state

Usage:
    py -3 -m tools.xemu_debug.menu_render_capture [--port 1234]

Prerequisites:
    - xemu running with -s flag (GDB stub on port 1234)
    - Game at main menu (state 5, camera ptr = 0x4D4008)
"""

import os
import sys
import struct
import argparse
import json
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient


def u32(data, offset=0):
    """Read uint32 little-endian."""
    if offset + 4 > len(data):
        return 0
    return struct.unpack_from('<I', data, offset)[0]

def f32(data, offset=0):
    """Read float32."""
    if offset + 4 > len(data):
        return 0.0
    return struct.unpack_from('<f', data, offset)[0]

def hex32(val):
    """Format as 0x%08X."""
    return f"0x{val:08X}"


def capture_menu_state(client):
    """Capture all menu rendering data."""
    results = {}

    # ── 1. Verify we're in menu state ──
    print("\n=== STEP 1: Verify menu state ===")
    state_data = client.read_memory(0x4D53B8, 4)
    cam_data = client.read_memory(0x4D5370, 4)
    state = u32(state_data)
    cam_ptr = u32(cam_data)
    print(f"  Game state (0x4D53B8): {state}")
    print(f"  Camera ptr (0x4D5370): {hex32(cam_ptr)}")

    if cam_ptr == 0x4D4008:
        print("  >> IN MENUS (camera = 0x4D4008)")
    elif cam_ptr == 0x4D45D0:
        print("  >> IN GAMEPLAY (camera = 0x4D45D0)")
    else:
        print(f"  >> UNKNOWN camera state")

    results['game_state'] = state
    results['camera_ptr'] = hex32(cam_ptr)

    # ── 2. Game object base and outer state ──
    print("\n=== STEP 2: Game object base ===")
    # In xemu, game object base = 0x004A71A0 (from session 33)
    game_base = 0x004A71A0
    outer_state_data = client.read_memory(game_base + 0x2E1E8, 4)
    outer_state = u32(outer_state_data)
    print(f"  Game base: {hex32(game_base)}")
    print(f"  Outer state (base+0x2E1E8): {outer_state} (0x17=running)")
    results['game_base'] = hex32(game_base)
    results['outer_state'] = outer_state

    # ── 3. Screen list sub-object and vtable ──
    print("\n=== STEP 3: Screen list vtable ===")
    # Screen list ptr at 0x4A1E94 (this is MEM32 in our recomp)
    sl_ptr_data = client.read_memory(0x4A1E94, 4)
    sl_ptr = u32(sl_ptr_data)
    print(f"  Screen list ptr (0x4A1E94): {hex32(sl_ptr)}")

    if sl_ptr != 0 and sl_ptr < 0x10000000:
        # Read the screen list structure (sub-object at +0x10)
        sub_obj_addr = sl_ptr + 0x10
        sub_obj_data = client.read_memory(sub_obj_addr, 0x20)
        vtable_ptr = u32(sub_obj_data, 0x00)
        cur_idx = u32(sub_obj_data, 0x04)
        entry_count = u32(sub_obj_data, 0x08)
        entry_array = u32(sub_obj_data, 0x0C)

        print(f"  Sub-object at {hex32(sub_obj_addr)}:")
        print(f"    +0x00 vtable:      {hex32(vtable_ptr)}")
        print(f"    +0x04 cur_index:   {cur_idx}")
        print(f"    +0x08 entry_count: {entry_count}")
        print(f"    +0x0C entry_array: {hex32(entry_array)}")

        results['screen_list'] = {
            'ptr': hex32(sl_ptr),
            'sub_obj_addr': hex32(sub_obj_addr),
            'vtable_ptr': hex32(vtable_ptr),
            'cur_index': cur_idx,
            'entry_count': entry_count,
            'entry_array': hex32(entry_array),
        }

        # Read vtable methods if vtable is valid
        if vtable_ptr != 0 and vtable_ptr < 0x400000:
            vt_data = client.read_memory(vtable_ptr, 0x20)  # 8 methods
            vtable_methods = []
            print(f"  Vtable at {hex32(vtable_ptr)}:")
            for i in range(8):
                method = u32(vt_data, i * 4)
                vtable_methods.append(hex32(method))
                print(f"    [{i}] +{i*4:02X}: {hex32(method)}")
            results['screen_list']['vtable_methods'] = vtable_methods
        else:
            print(f"  !! Vtable is NULL or out of range")
            results['screen_list']['vtable_methods'] = None

        # Read first 10 screen entries from entry_array
        if entry_array != 0 and entry_array < 0x10000000:
            print(f"\n  Screen entries at {hex32(entry_array)}:")
            entries = []
            entry_size = 0x20  # Estimated entry size
            entry_data = client.read_memory(entry_array, entry_size * 20)
            for i in range(20):
                off = i * entry_size
                flag = entry_data[off + 0x1E] if off + 0x1E < len(entry_data) else 0
                e_vtable = u32(entry_data, off + 0x00)
                e_field4 = u32(entry_data, off + 0x04)
                e_field8 = u32(entry_data, off + 0x08)
                entries.append({
                    'index': i,
                    'vtable': hex32(e_vtable),
                    'field4': hex32(e_field4),
                    'field8': hex32(e_field8),
                    'flag_1E': flag,
                })
                if flag != 0 or e_vtable != 0:
                    print(f"    [{i:2d}] vtable={hex32(e_vtable)} f4={hex32(e_field4)} f8={hex32(e_field8)} flag={flag}")
            results['screen_entries'] = entries
    else:
        print(f"  !! Screen list ptr invalid: {hex32(sl_ptr)}")
        results['screen_list'] = None

    # ── 4. Render context at 0x35FB48 ──
    print("\n=== STEP 4: Render context (0x35FB48) ===")
    rc_data = client.read_memory(0x35FB48, 4)
    rc_ptr = u32(rc_data)
    print(f"  MEM32(0x35FB48): {hex32(rc_ptr)}")
    results['render_context_ptr'] = hex32(rc_ptr)

    if rc_ptr != 0 and rc_ptr < 0x10000000:
        # Read first 0x40 bytes of the render context
        ctx_data = client.read_memory(rc_ptr, 0x80)
        print(f"  Render context at {hex32(rc_ptr)}:")
        for off in range(0, 0x80, 4):
            val = u32(ctx_data, off)
            if val != 0:
                print(f"    +{off:02X}: {hex32(val)}")
        results['render_context'] = {
            'addr': hex32(rc_ptr),
            'data': [hex32(u32(ctx_data, i)) for i in range(0, 0x80, 4)]
        }

    # ── 5. Frontend object (0x4D4008) ──
    print("\n=== STEP 5: Frontend object ===")
    fe_data = client.read_memory(0x4D4008, 0x40)
    fe_vtable = u32(fe_data, 0x00)
    print(f"  Frontend obj at 0x4D4008:")
    print(f"    +0x00 vtable: {hex32(fe_vtable)}")
    for off in range(4, 0x40, 4):
        val = u32(fe_data, off)
        if val != 0:
            print(f"    +{off:02X}: {hex32(val)}")
    results['frontend_obj'] = {
        'vtable': hex32(fe_vtable),
        'data': [hex32(u32(fe_data, i)) for i in range(0, 0x40, 4)]
    }

    # Read frontend vtable methods
    if fe_vtable != 0 and fe_vtable < 0x400000:
        fev_data = client.read_memory(fe_vtable, 0x20)
        print(f"  Frontend vtable at {hex32(fe_vtable)}:")
        fe_methods = []
        for i in range(8):
            method = u32(fev_data, i * 4)
            fe_methods.append(hex32(method))
            print(f"    [{i}] +{i*4:02X}: {hex32(method)}")
        results['frontend_obj']['vtable_methods'] = fe_methods

    # ── 6. sub_001AE6F0's key addresses ──
    print("\n=== STEP 6: sub_001AE6F0 dependencies ===")
    # The function reads several key pointers
    addrs = {
        '0x35FB48': 0x35FB48,  # Render context
        '0x35FB4C': 0x35FB4C,  # Often paired
        '0x4A1E94': 0x4A1E94,  # Screen list ptr
        '0x4A1E98': 0x4A1E98,
        '0x004AF580': 0x004AF580,  # Screen list obj base
    }
    dep_values = {}
    for name, addr in addrs.items():
        data = client.read_memory(addr, 4)
        val = u32(data)
        print(f"  {name}: {hex32(val)}")
        dep_values[name] = hex32(val)
    results['dependencies'] = dep_values

    # Read screen list obj base area (0x004AF580, 0x40 bytes)
    sl_base_data = client.read_memory(0x004AF580, 0x40)
    print(f"\n  Screen list obj (0x004AF580):")
    for off in range(0, 0x40, 4):
        val = u32(sl_base_data, off)
        print(f"    +{off:02X}: {hex32(val)}")
    results['screen_list_base'] = [hex32(u32(sl_base_data, i)) for i in range(0, 0x40, 4)]

    # ── 7. RW function pointer tables ──
    print("\n=== STEP 7: RW function tables ===")
    rw_ptrs = {
        '0x759338 (rw_render)': 0x759338,
        '0x759318 (rw_init)': 0x759318,
        '0x7593E4 (rw_close)': 0x7593E4,
        '0x7592CC (im2d_tri)': 0x7592CC,
        '0x7592D0 (im2d_line)': 0x7592D0,
        '0x7592A8': 0x7592A8,
        '0x7592AC': 0x7592AC,
        '0x7592B0': 0x7592B0,
        '0x7592B4': 0x7592B4,
    }
    rw_values = {}
    for name, addr in rw_ptrs.items():
        data = client.read_memory(addr, 4)
        val = u32(data)
        print(f"  {name}: {hex32(val)}")
        rw_values[name] = hex32(val)
    results['rw_func_ptrs'] = rw_values

    # ── 8. sub_001AA100 state (B790, B794, phase field) ──
    print("\n=== STEP 8: sub_001AA100 state ===")
    # These are relative to game base + some offset
    # In our recomp, B790 = game_base + offset, let's check the raw addresses
    # From session 39: B790/B794 are at ebp+0xB790 where ebp = game base area
    # Actually these are at fixed addresses. Let me check the code...
    # sub_001AA100 uses ebp which points to game obj base
    # B790 = ebp + 0xB790
    b790_addr = game_base + 0xB790
    b794_addr = game_base + 0xB794
    b7a8_addr = game_base + 0xB7A8

    b790_data = client.read_memory(b790_addr, 4)
    b794_data = client.read_memory(b794_addr, 4)
    b7a8_data = client.read_memory(b7a8_addr, 0x20)

    print(f"  B790 ({hex32(b790_addr)}): {hex32(u32(b790_data))}")
    print(f"  B794 ({hex32(b794_addr)}): {hex32(u32(b794_data))}")
    print(f"  B7A8 ({hex32(b7a8_addr)}) scene descriptors:")
    for i in range(8):
        val = u32(b7a8_data, i * 4)
        if val != 0:
            print(f"    +{i*4:02X}: {hex32(val)}")

    results['phase_state'] = {
        'B790': hex32(u32(b790_data)),
        'B794': hex32(u32(b794_data)),
        'B7A8': [hex32(u32(b7a8_data, i*4)) for i in range(8)],
    }

    # ── 9. sub_001AE6F0 disassembly context — read the function's data deps ──
    print("\n=== STEP 9: Render list / sub_001AD350 inputs ===")
    # sub_001AE6F0 at some point calls sub_001AD350
    # sub_001AD350 takes a render list pointer
    # Let's check what's at 0x45BAD0 (screen definitions from session 39)
    sd_data = client.read_memory(0x45BAD0, 0x40)
    print(f"  Screen defs at 0x45BAD0:")
    for off in range(0, 0x40, 4):
        val = u32(sd_data, off)
        if val != 0:
            print(f"    +{off:02X}: {hex32(val)}")
    results['screen_defs_45BAD0'] = [hex32(u32(sd_data, i)) for i in range(0, 0x40, 4)]

    # ── 10. Phase field at game_base + 0x144384 ──
    print("\n=== STEP 10: Phase/init fields ===")
    phase_addr = game_base + 0x144384
    phase_data = client.read_memory(phase_addr, 4)
    phase_val = u32(phase_data)
    print(f"  Phase (base+0x144384 = {hex32(phase_addr)}): {hex32(phase_val)}")

    # Also check base+0x83E0 (screen list sub-object offset used in session 39)
    sl_sub_addr = game_base + 0x83E0
    sl_sub_data = client.read_memory(sl_sub_addr, 0x20)
    print(f"  Screen list sub (base+0x83E0 = {hex32(sl_sub_addr)}):")
    for off in range(0, 0x20, 4):
        val = u32(sl_sub_data, off)
        print(f"    +{off:02X}: {hex32(val)}")

    results['phase_field'] = hex32(phase_val)
    results['screen_list_sub_83E0'] = [hex32(u32(sl_sub_data, i)) for i in range(0, 0x20, 4)]

    return results


def main():
    parser = argparse.ArgumentParser(description='Capture menu rendering state from xemu')
    parser.add_argument('--port', type=int, default=1234)
    parser.add_argument('--output', default='tools/xemu_debug/snapshots')
    args = parser.parse_args()

    print("=" * 60)
    print("  Burnout 3 - Menu Render Pipeline Capture")
    print("=" * 60)
    print(f"\nConnecting to xemu GDB stub on port {args.port}...")
    print("Make sure the game is at the MAIN MENU before running this!")

    client = GDBClient('localhost', args.port)
    try:
        client.connect()

        # Halt CPU for consistent reads
        print("\nHalting CPU...")
        client.halt()

        results = capture_menu_state(client)

        # Resume
        print("\n\nResuming CPU...")
        client.continue_execution()

        # Save results
        os.makedirs(args.output, exist_ok=True)
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        outfile = os.path.join(args.output, f'menu_render_{timestamp}.json')
        with open(outfile, 'w') as f:
            json.dump(results, f, indent=2)
        print(f"\nResults saved to {outfile}")

        # Also save human-readable summary
        txtfile = os.path.join(args.output, f'menu_render_{timestamp}.txt')
        with open(txtfile, 'w') as f:
            f.write("Burnout 3 Menu Render Pipeline Capture\n")
            f.write(f"Date: {datetime.now().isoformat()}\n")
            f.write("=" * 60 + "\n\n")
            f.write(json.dumps(results, indent=2))
        print(f"Text saved to {txtfile}")

    except Exception as e:
        print(f"\nERROR: {e}")
        import traceback
        traceback.print_exc()
    finally:
        client.disconnect()


if __name__ == '__main__':
    main()
