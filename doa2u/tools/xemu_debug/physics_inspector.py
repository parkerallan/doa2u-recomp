"""
Physics body inspector for Burnout 3 running in xemu.

Breaks at the physics function (sub_000636D0) and logs the real
physics body structure. This is critical because our recompiled
version uses a fake physics body at 0x5FFF00 — we need to understand
the real structure to eventually replace it.

Usage:
    py -3 -m tools.xemu_debug.physics_inspector [--port 1234] [--samples 100]
"""

import os
import sys
import json
import struct
import time
import argparse
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient


# sub_000636D0: Physics force application
# Called with esi = car object (0x557880)
# Reads vel_ptr from esi+0x1B4
PHYSICS_FUNC = 0x000636D0

# sub_000110E0: Frame pump (integrates physics)
FRAME_PUMP = 0x000110E0


def inspect_physics_body(client: GDBClient, sample_num: int) -> dict:
    """Read the physics body structure from the real game."""

    regs = client.read_registers()
    esi = regs.get('esi', 0)
    eip = regs.get('eip', 0)

    result = {
        'sample': sample_num,
        'eip': eip,
        'esi': esi,
    }

    print(f"\n--- Sample {sample_num} ---")
    print(f"  EIP=0x{eip:08X}  ESI=0x{esi:08X}")

    if esi == 0 or esi > 0x10000000:
        print(f"  ESI is invalid, skipping")
        return result

    # Read car object area around +0x1B4 (velocity pointer)
    car_data = client.read_memory(esi, 0x200)

    # Get velocity pointer
    vel_ptr = struct.unpack_from('<I', car_data, 0x1B4)[0]
    result['vel_ptr'] = vel_ptr
    print(f"  vel_ptr (esi+0x1B4) = 0x{vel_ptr:08X}")

    if vel_ptr == 0 or vel_ptr > 0x10000000:
        print(f"  vel_ptr is NULL or invalid")
        return result

    # Read the velocity/physics body (read 256 bytes to discover the structure)
    phys_data = client.read_memory(vel_ptr, 0x100)
    result['phys_addr'] = vel_ptr
    result['phys_data'] = phys_data.hex()

    # Try interpreting as our known fake body layout
    # Our fake body: +0x08=accel, +0x0C=turn, +0x10=px, +0x14=py, +0x18=hdg, +0x1C=spd
    print(f"  Physics body at 0x{vel_ptr:08X}:")

    # Dump first 64 bytes as both hex and float interpretations
    for offset in range(0, 0x40, 4):
        raw = struct.unpack_from('<I', phys_data, offset)[0]
        fval = struct.unpack_from('<f', phys_data, offset)[0]

        # Label known offsets from our fake body
        label = ''
        if offset == 0x08: label = ' <-- accel?'
        elif offset == 0x0C: label = ' <-- turn_rate?'
        elif offset == 0x10: label = ' <-- pos_x?'
        elif offset == 0x14: label = ' <-- pos_y?'
        elif offset == 0x18: label = ' <-- heading?'
        elif offset == 0x1C: label = ' <-- speed?'

        # Show as float if it looks like a reasonable float value
        if abs(fval) < 100000 and abs(fval) > 0.00001 and raw != 0:
            print(f"    +0x{offset:02X}: 0x{raw:08X}  ({fval:12.4f}){label}")
            result[f'offset_{offset:02x}'] = fval
        else:
            print(f"    +0x{offset:02X}: 0x{raw:08X}  ({raw:10d}){label}")
            result[f'offset_{offset:02x}'] = raw

    # Also read nearby car object fields that might give us context
    # +0x00: might be vtable
    # +0x04: might be flags or type
    car_vtable = struct.unpack_from('<I', car_data, 0x00)[0]
    car_field4 = struct.unpack_from('<I', car_data, 0x04)[0]
    result['car_vtable'] = car_vtable
    result['car_field4'] = car_field4
    print(f"  Car vtable: 0x{car_vtable:08X}")
    print(f"  Car+0x04:   0x{car_field4:08X}")

    # Check other interesting car object offsets
    for off in [0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C,
                0x100, 0x104, 0x108, 0x10C, 0x110,
                0x1A0, 0x1A4, 0x1A8, 0x1AC, 0x1B0, 0x1B4, 0x1B8, 0x1BC]:
        if off + 4 <= len(car_data):
            raw = struct.unpack_from('<I', car_data, off)[0]
            fval = struct.unpack_from('<f', car_data, off)[0]
            if abs(fval) < 100000 and abs(fval) > 0.00001 and raw != 0:
                result[f'car_{off:03x}'] = fval
            else:
                result[f'car_{off:03x}'] = raw

    return result


def main():
    parser = argparse.ArgumentParser(description='Burnout 3 physics body inspector')
    parser.add_argument('--host', default='localhost')
    parser.add_argument('--port', type=int, default=1234)
    parser.add_argument('--output', default='tools/xemu_debug/physics_traces')
    parser.add_argument('--samples', type=int, default=50,
                        help='Number of physics frames to capture')
    parser.add_argument('--at-pump', action='store_true',
                        help='Break at frame pump instead of physics function')
    args = parser.parse_args()

    client = GDBClient(args.host, args.port)
    try:
        client.connect()
    except ConnectionRefusedError:
        print(f"ERROR: Cannot connect to {args.host}:{args.port}")
        sys.exit(1)

    os.makedirs(args.output, exist_ok=True)

    bp_addr = FRAME_PUMP if args.at_pump else PHYSICS_FUNC
    bp_name = 'frame_pump' if args.at_pump else 'physics_func'

    print(f"Setting breakpoint at {bp_name} (0x{bp_addr:08X})...")
    if not client.set_breakpoint(bp_addr):
        print("WARNING: Could not set breakpoint. Guest may need to be running.")
        # Try continuing first
        client.continue_execution()
        time.sleep(2.0)
        client.halt()
        time.sleep(0.2)
        client.set_breakpoint(bp_addr)

    samples = []
    try:
        for i in range(args.samples):
            client.continue_execution()
            stop = client.wait_for_stop(timeout=30.0)

            if stop == 'timeout':
                print("Timeout - game may not be in gameplay state yet")
                print("Let the game load fully, then re-run this tool")
                break

            sample = inspect_physics_body(client, i)
            samples.append(sample)

            # Check if we're actually hitting our breakpoint
            regs = client.read_registers()
            eip = regs.get('eip', 0)
            if eip != bp_addr and i > 3:
                print(f"  EIP=0x{eip:08X} doesn't match breakpoint — might have hit elsewhere")

    except KeyboardInterrupt:
        print("\nInterrupted.")
    finally:
        client.remove_breakpoint(bp_addr)
        try:
            client.continue_execution()
        except Exception:
            pass
        client.disconnect()

    # Save results
    output_path = os.path.join(args.output, f'physics_{bp_name}_{len(samples)}samples.json')
    with open(output_path, 'w') as f:
        json.dump(samples, f, indent=2, default=str)
    print(f"\n{len(samples)} samples saved to {output_path}")

    # Summary analysis
    if samples:
        print("\n=== Summary ===")
        vel_ptrs = set(s.get('vel_ptr', 0) for s in samples if s.get('vel_ptr', 0) != 0)
        esi_vals = set(s.get('esi', 0) for s in samples)
        print(f"  Unique ESI values: {len(esi_vals)} - {', '.join(f'0x{v:08X}' for v in sorted(esi_vals))}")
        print(f"  Unique vel_ptr values: {len(vel_ptrs)} - {', '.join(f'0x{v:08X}' for v in sorted(vel_ptrs))}")

        # Check if the physics body address is consistent
        if len(vel_ptrs) == 1:
            ptr = list(vel_ptrs)[0]
            print(f"  Physics body is at FIXED address 0x{ptr:08X}")
            if ptr == 0x5FFF00:
                print(f"  ...which matches our fake body! The game might use this address.")
            else:
                print(f"  ...our fake body is at 0x5FFF00, DIFFERENT from the real one.")
                print(f"  UPDATE: redirect our fake body to 0x{ptr:08X}")


if __name__ == '__main__':
    main()
