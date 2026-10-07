"""
Follow-up capture: screen entry vtables, render context deep dive,
and sub_001AE6F0 call chain tracing.
"""
import os, sys, struct, json
from datetime import datetime
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

    # ── 1. Screen entry vtable deep dive ──
    # Entries are at 0x004B01B0, 0x20 bytes each, 536 entries
    # Each entry has a vtable at +0x00, flag at +0x1E
    # Let's read ALL active entries and decode their vtable methods
    print("\n=== Screen Entry Vtable Analysis ===")
    entry_base = 0x004B01B0
    entry_size = 0x20

    # Read a batch of entries (first 50)
    batch = client.read_memory(entry_base, entry_size * 50)

    # Collect unique vtables
    unique_vtables = set()
    active_entries = []
    for i in range(50):
        off = i * entry_size
        vt = u32(batch, off)
        flag = batch[off + 0x1E] if off + 0x1E < len(batch) else 0
        if flag != 0 and vt != 0:
            active_entries.append((i, vt, flag))
            unique_vtables.add(vt)
            # Print full entry data
            entry_hex = ' '.join(f'{batch[off+j]:02X}' for j in range(entry_size))
            print(f"  [{i:3d}] flag={flag} vt={hex32(vt)} | {entry_hex}")

    print(f"\n  Active entries: {len(active_entries)}")
    print(f"  Unique vtables: {len(unique_vtables)}")

    # Read each unique vtable's methods
    print("\n=== Unique Vtable Methods ===")
    vtable_map = {}
    for vt in sorted(unique_vtables):
        vt_data = client.read_memory(vt, 0x30)  # Read 12 methods
        methods = [u32(vt_data, i*4) for i in range(12)]
        vtable_map[hex32(vt)] = [hex32(m) for m in methods]
        print(f"\n  Vtable {hex32(vt)}:")
        for j, m in enumerate(methods):
            if m != 0:
                print(f"    [{j:2d}] +{j*4:02X}: {hex32(m)}")

    # ── 2. Screen list container vtable methods ──
    # vtable at 0x003A9FA4 — methods [0]=0x249B0, [1]=0x1AEFD0, [2]=0x1AF040, [3]=0x1AF180
    print("\n=== Screen List Container Vtable (0x003A9FA4) ===")
    sl_vt_data = client.read_memory(0x003A9FA4, 0x30)
    for i in range(12):
        m = u32(sl_vt_data, i*4)
        if m != 0:
            print(f"  [{i:2d}] +{i*4:02X}: {hex32(m)}")

    # ── 3. Render context deep dive ──
    # 0x35FB48 -> 0x0035D6A0
    # The values 0x82xxxxxx are Xbox physical memory addresses (contiguous RAM)
    # 0x8205A184, 0x820C2A18, 0x81FC3000, etc.
    print("\n=== Render Context Deep Dive (0x0035D6A0) ===")
    rc = client.read_memory(0x0035D6A0, 0x200)
    print("  Full dump:")
    for off in range(0, 0x200, 4):
        val = u32(rc, off)
        if val != 0:
            print(f"    +{off:03X}: {hex32(val)}")

    # ── 4. 0x35FB4C -> 0x00400104 — what's there? ──
    print("\n=== 0x35FB4C -> 0x00400104 ===")
    fb4c = client.read_memory(0x00400104, 0x80)
    for off in range(0, 0x80, 4):
        val = u32(fb4c, off)
        if val != 0:
            print(f"  +{off:02X}: {hex32(val)}")

    # ── 5. Read sub_001AE6F0 disassembly area to understand call pattern ──
    # The function is at 0x001AE6F0 in Xbox VA space
    # Let's read the first 0x100 bytes of the function code
    print("\n=== sub_001AE6F0 code bytes (first 0x100) ===")
    code = client.read_memory(0x001AE6F0, 0x100)
    # Print as hex dump
    for off in range(0, 0x100, 16):
        hex_bytes = ' '.join(f'{code[off+j]:02X}' for j in range(min(16, len(code)-off)))
        print(f"  {0x001AE6F0+off:08X}: {hex_bytes}")

    # ── 6. Check what sub_001AD350 reads ──
    # It's the render list dispatch — let's see what esi/parameters it expects
    print("\n=== sub_001AD350 code bytes (first 0x80) ===")
    code2 = client.read_memory(0x001AD350, 0x80)
    for off in range(0, 0x80, 16):
        hex_bytes = ' '.join(f'{code2[off+j]:02X}' for j in range(min(16, len(code2)-off)))
        print(f"  {0x001AD350+off:08X}: {hex_bytes}")

    # ── 7. im2d function table — correct addresses from xemu ──
    print("\n=== im2d function table (corrected) ===")
    # xemu shows 0x7592CC = 0x001E60B0, 0x7592D0 = 0x001E6250
    # Our recomp had 0x1E2930 and 0x1E2330 — DIFFERENT!
    # Let's check more of the table
    im2d_table = client.read_memory(0x7592A0, 0x60)
    for off in range(0, 0x60, 4):
        val = u32(im2d_table, off)
        addr = 0x7592A0 + off
        if val != 0:
            print(f"  {hex32(addr)}: {hex32(val)}")

    # ── 8. B790 -> 0x00411590 — what's there? ──
    print("\n=== B790 -> 0x00411590 (screen def?) ===")
    b790_target = client.read_memory(0x00411590, 0x80)
    for off in range(0, 0x80, 4):
        val = u32(b790_target, off)
        if val != 0:
            print(f"  +{off:02X}: {hex32(val)}")

    # ── 9. More screen entries (50-100) ──
    print("\n=== Screen entries 50-100 ===")
    batch2 = client.read_memory(entry_base + 50 * entry_size, entry_size * 50)
    for i in range(50):
        off = i * entry_size
        vt = u32(batch2, off)
        flag = batch2[off + 0x1E] if off + 0x1E < len(batch2) else 0
        if flag != 0 and vt != 0:
            print(f"  [{50+i:3d}] flag={flag} vt={hex32(vt)}")

    print("\n\nResuming CPU...")
    client.continue_execution()
    client.disconnect()

if __name__ == '__main__':
    main()
