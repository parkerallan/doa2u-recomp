"""
Capture D3D device context from xemu during menu rendering.

Dumps the Xbox D3D8 device context structure (16KB) so we can use it
to initialize the device context in the static recompilation.

The device context pointer is at 0x35FB48 (Xbox global).
In xemu, the game allocates this via NtAllocateVirtualMemory.

Usage:
    1. Launch xemu with -s flag: xemu.exe -s
    2. Boot Burnout 3, wait until main menu is visible
    3. Run: py -3 tools/xemu_debug/capture_d3d_device.py

The script halts the CPU, reads memory, then continues.
"""
import sys
import os
import struct
import json
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from xemu_debug.gdb_client import GDBClient


def read32(client, addr):
    """Read a 32-bit little-endian value."""
    data = client.read_memory(addr, 4)
    if data and len(data) >= 4:
        return struct.unpack('<I', data)[0]
    return None


def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    print("\n=== Halting CPU ===")
    client.halt()
    time.sleep(0.3)

    # Read game state to verify we're in menus
    game_state = read32(client, 0x4D53B8)
    cam_ptr = read32(client, 0x4D5370)
    print(f"Game state: {game_state} (5=menus)")
    print(f"Camera ptr: 0x{cam_ptr:08X} (0x4D4008=menus)")

    if game_state != 5:
        print("WARNING: Game not in state 5 (menus), data may not be useful")

    # Read D3D device context pointer
    dev_ptr = read32(client, 0x35FB48)
    print(f"\nD3D device context ptr [0x35FB48] = 0x{dev_ptr:08X}")

    if dev_ptr == 0 or dev_ptr > 0x08000000:
        print("ERROR: Device pointer looks invalid!")
        client.continue_execution()
        client.disconnect()
        return

    # Dump the device context - read in chunks
    print(f"\n=== Dumping device context at 0x{dev_ptr:08X} (16 KB) ===")
    dev_size = 0x4000  # 16 KB
    chunk_size = 0x400  # Read 1KB at a time

    full_data = b''
    for offset in range(0, dev_size, chunk_size):
        addr = dev_ptr + offset
        data = client.read_memory(addr, chunk_size)
        if data and len(data) == chunk_size:
            full_data += data
            if offset % 0x1000 == 0:
                print(f"  Read 0x{offset:04X}-0x{offset+chunk_size:04X} OK")
        else:
            print(f"  FAILED at offset 0x{offset:04X} (got {len(data) if data else 0} bytes)")
            full_data += b'\x00' * chunk_size

    print(f"\nTotal: {len(full_data)} bytes captured")

    # Print key fields
    def f32(off):
        return struct.unpack('<f', full_data[off:off+4])[0]
    def u32(off):
        return struct.unpack('<I', full_data[off:off+4])[0]

    print(f"\n=== Key device context fields ===")
    print(f"  +0x000 (PB write): 0x{u32(0):08X}")
    print(f"  +0x004 (PB end):   0x{u32(4):08X}")
    print(f"  +0x008 (PB base):  0x{u32(8):08X}")
    print(f"  +0x00C (PB size):  0x{u32(0xC):08X}")
    print(f"  +0x784 (RT surf):  0x{u32(0x784):08X}")
    print(f"  +0x794 (DS surf):  0x{u32(0x794):08X}")
    print(f"  +0x7A8 (BB surf):  0x{u32(0x7A8):08X}")
    print(f"  +0x7CC (RS flags): 0x{u32(0x7CC):08X}")
    print(f"  +0x954 (max W):    {u32(0x954)}")
    print(f"  +0x958 (max H):    {u32(0x958)}")
    print(f"  +0xCA0..+0xCE0:    state block (64 bytes)")
    for i in range(0, 64, 16):
        off = 0xCA0 + i
        print(f"    +0x{off:03X}: {u32(off):08X} {u32(off+4):08X} {u32(off+8):08X} {u32(off+12):08X}")
    print(f"  +0xEE0 (vp W):     {u32(0xEE0)}")
    print(f"  +0xEE4 (vp H):     {u32(0xEE4)}")
    print(f"  +0xEF8 (vp f0):    {f32(0xEF8):.4f}")
    print(f"  +0xEFC (vp f1):    {f32(0xEFC):.4f}")
    print(f"  +0x1A04 (RT ptr):  0x{u32(0x1A04):08X}")
    print(f"  +0x1A08 (DS ptr):  0x{u32(0x1A08):08X}")
    print(f"  +0x1AD4:           0x{u32(0x1AD4):08X}")

    # Also dump surface objects pointed to by +0x784, +0x794
    for label, off in [("RT surface (+0x784)", 0x784),
                        ("DS surface (+0x794)", 0x794),
                        ("BB surface (+0x7A8)", 0x7A8)]:
        surf_ptr = u32(off)
        if surf_ptr != 0 and surf_ptr < 0x08000000:
            print(f"\n  {label} at 0x{surf_ptr:08X}:")
            surf_data = client.read_memory(surf_ptr, 0x40)
            if surf_data and len(surf_data) >= 0x40:
                for i in range(0, 0x40, 16):
                    vals = struct.unpack('<IIII', surf_data[i:i+16])
                    print(f"    +0x{i:02X}: {vals[0]:08X} {vals[1]:08X} {vals[2]:08X} {vals[3]:08X}")

    # Also capture the render list resource at base+0x12ADB0
    game_base = 0x4A71A0  # xemu base (not 0x60EA00)
    render_base = game_base + 0x12ADB0
    print(f"\n=== Render list (base+0x12ADB0 = 0x{render_base:08X}) ===")
    rl_data = client.read_memory(render_base, 0x20)
    if rl_data and len(rl_data) >= 0x20:
        for i in range(0, 0x20, 16):
            vals = struct.unpack('<IIII', rl_data[i:i+16])
            print(f"  +0x{i:02X}: {vals[0]:08X} {vals[1]:08X} {vals[2]:08X} {vals[3]:08X}")

        res_ptr = struct.unpack('<I', rl_data[4:8])[0]
        if res_ptr != 0 and res_ptr < 0x08000000:
            print(f"\n  Resource at 0x{res_ptr:08X}:")
            res_data = client.read_memory(res_ptr, 0x80)
            if res_data and len(res_data) >= 0x80:
                for i in range(0, 0x80, 16):
                    vals = struct.unpack('<IIII', res_data[i:i+16])
                    print(f"    +0x{i:02X}: {vals[0]:08X} {vals[1]:08X} {vals[2]:08X} {vals[3]:08X}")

    # Save raw binary dump
    out_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "snapshots")
    os.makedirs(out_dir, exist_ok=True)

    bin_path = os.path.join(out_dir, "d3d_device_context.bin")
    with open(bin_path, 'wb') as f:
        f.write(full_data)
    print(f"\nSaved raw binary: {bin_path}")

    # Save as C header for embedding
    header_path = os.path.join("src", "nv2a", "d3d_device_snapshot.h")
    with open(header_path, 'w') as f:
        f.write("/* D3D8 device context snapshot from xemu — captured during menu rendering */\n")
        f.write(f"/* Source address: 0x{dev_ptr:08X}, size: {len(full_data)} bytes */\n")
        f.write(f"/* Game state: {game_state}, camera: 0x{cam_ptr:08X} */\n\n")
        f.write(f"#define D3D_DEVICE_SNAPSHOT_SIZE {len(full_data)}\n")
        f.write(f"#define D3D_DEVICE_SNAPSHOT_ADDR 0x{dev_ptr:08X}u\n\n")
        f.write("static const unsigned char d3d_device_snapshot[] = {\n")
        for i in range(0, len(full_data), 16):
            chunk = full_data[i:i+16]
            hex_bytes = ', '.join(f'0x{b:02X}' for b in chunk)
            f.write(f"    {hex_bytes},\n")
        f.write("};\n")
    print(f"Saved C header: {header_path}")

    # Resume
    print("\n=== Resuming CPU ===")
    client.continue_execution()
    client.disconnect()
    print("Done!")


if __name__ == '__main__':
    main()
