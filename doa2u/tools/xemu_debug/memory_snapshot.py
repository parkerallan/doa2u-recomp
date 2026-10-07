"""
Memory snapshot tool for Burnout 3 running in xemu.

Connects to xemu's GDB stub and dumps key memory regions that are important
for understanding the game's runtime behavior. Compares what xemu sees with
what our recompiled version expects.

Usage:
    py -3 -m tools.xemu_debug.memory_snapshot [--port 1234] [--output snapshots/]
"""

import os
import sys
import json
import struct
import argparse
import time
from datetime import datetime

# Add project root to path
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient


# ── Key memory regions for Burnout 3 ──────────────────────

REGIONS = {
    # Game objects
    'car_object': {
        'addr': 0x557880, 'size': 0x200,
        'desc': 'Car object (esi in sub_000636D0)',
        'fields': {
            0x1B4: ('vel_ptr', 'u32', 'Velocity body pointer'),
        }
    },
    'rw_world_ptr': {
        'addr': 0x4D5370, 'size': 0x10,
        'desc': 'RW world pointer (read 300+ times, never properly init)',
        'fields': {
            0x00: ('world_ptr', 'u32', 'Should be RpWorld*, is it?'),
        }
    },
    'track_env': {
        'addr': 0x464018, 'size': 0x100,
        'desc': 'Track environment object',
        'fields': {
            0x00: ('env_ptr', 'u32', 'Track env pointer'),
        }
    },

    # Physics
    'physics_body': {
        'addr': 0x5FFF00, 'size': 0x40,
        'desc': 'Physics body (fake in our recomp, real in xemu)',
        'fields': {
            0x08: ('accel', 'f32', 'Acceleration'),
            0x0C: ('turn_rate', 'f32', 'Turn rate'),
            0x10: ('pos_x', 'f32', 'Position X'),
            0x14: ('pos_y', 'f32', 'Position Y'),
            0x18: ('heading', 'f32', 'Heading angle (radians)'),
            0x1C: ('speed', 'f32', 'Scalar speed'),
        }
    },

    # Game state
    'game_state': {
        'addr': 0x4D53BE, 'size': 0x4,
        'desc': 'Game state byte',
        'fields': {
            0x00: ('state', 'u8', 'Current game state (0-13+)'),
        }
    },
    'load_state': {
        'addr': 0x4D53C0, 'size': 0x4,
        'desc': 'Load sub-state',
        'fields': {
            0x00: ('load_state', 'u8', 'Load progress (0x00-0x17)'),
        }
    },

    # Input
    'throttle': {
        'addr': 0x4D652C, 'size': 0x8,
        'desc': 'Throttle and steering accumulators',
        'fields': {
            0x00: ('throttle', 'f32', 'Throttle value'),
            0x04: ('steering', 'f32', 'Steering value'),
        }
    },

    # Load queue
    'load_queue_1': {
        'addr': 0x4AEDDC, 'size': 0x80,
        'desc': 'Load queue object 1 (complex/RW)',
        'fields': {
            0x00: ('head', 'u32', 'Queue head index'),
            0x04: ('tail', 'u32', 'Queue tail index'),
        }
    },

    # Gameplay variables (our fake memory map)
    'takedown_count': {
        'addr': 0x5FFD00, 'size': 0x40,
        'desc': 'Gameplay variables block',
        'fields': {
            0x00: ('takedowns', 'u32', 'Takedown count'),
            0x04: ('flash_timer', 'f32', 'Flash timer'),
            0x08: ('boost_meter', 'f32', 'Boost 0-100'),
            0x0C: ('boost_btn', 'u32', 'Boost button state'),
            0x10: ('road_curve', 'f32', 'Road curve at player'),
            0x14: ('distance', 'u32', 'Distance traveled'),
            0x18: ('shake_timer', 'f32', 'Screen shake'),
            0x24: ('score', 'u32', 'Score'),
            0x28: ('multiplier', 'f32', 'Score multiplier 1-8'),
        }
    },

    # RenderWare engine state
    'rw_engine': {
        'addr': 0x4D53A0, 'size': 0x40,
        'desc': 'RenderWare engine globals area',
        'fields': {}
    },

    # D3D device pointer area
    'd3d_device': {
        'addr': 0x4A2340, 'size': 0x10,
        'desc': 'D3D device pointer',
        'fields': {
            0x00: ('device_ptr', 'u32', 'IDirect3DDevice8*'),
        }
    },
}

# ── Additional probing regions to discover ──────────────────
# These are addresses we want to follow from pointers found above
FOLLOW_POINTERS = [
    ('car_object', 0x1B4, 0x40, 'Velocity body (from car+0x1B4)'),
    ('rw_world_ptr', 0x00, 0x100, 'RW world object (from 0x4D5370)'),
    ('track_env', 0x00, 0x100, 'Track env object (from 0x464018)'),
    ('d3d_device', 0x00, 0x100, 'D3D device vtable (from device ptr)'),
]


def format_field(data: bytes, offset: int, fmt: str, name: str, desc: str) -> str:
    """Format a field value for display."""
    try:
        if fmt == 'u32':
            val = struct.unpack_from('<I', data, offset)[0]
            return f"  +0x{offset:02X} {name:16s} = 0x{val:08X} ({val:10d})  # {desc}"
        elif fmt == 'f32':
            val = struct.unpack_from('<f', data, offset)[0]
            return f"  +0x{offset:02X} {name:16s} = {val:12.4f}              # {desc}"
        elif fmt == 'u8':
            val = data[offset]
            return f"  +0x{offset:02X} {name:16s} = 0x{val:02X} ({val:3d})              # {desc}"
        elif fmt == 'u16':
            val = struct.unpack_from('<H', data, offset)[0]
            return f"  +0x{offset:02X} {name:16s} = 0x{val:04X} ({val:5d})          # {desc}"
    except (struct.error, IndexError):
        return f"  +0x{offset:02X} {name:16s} = <read error>               # {desc}"


def hex_dump(data: bytes, base_addr: int, width: int = 16) -> str:
    """Format a hex dump with address and ASCII."""
    lines = []
    for i in range(0, len(data), width):
        chunk = data[i:i+width]
        hex_part = ' '.join(f'{b:02X}' for b in chunk)
        ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
        lines.append(f"  0x{base_addr + i:08X}: {hex_part:<{width*3}}  {ascii_part}")
    return '\n'.join(lines)


def take_snapshot(client: GDBClient, output_dir: str, label: str = ''):
    """Take a complete memory snapshot of all key regions."""
    timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
    if label:
        filename = f"snapshot_{label}_{timestamp}"
    else:
        filename = f"snapshot_{timestamp}"

    # Read registers
    print("\n=== CPU Registers ===")
    regs = client.read_registers()
    for name in ['eax', 'ecx', 'edx', 'ebx', 'esp', 'ebp', 'esi', 'edi', 'eip']:
        if name in regs:
            print(f"  {name} = 0x{regs[name]:08X}")

    # Read all regions
    snapshot = {
        'timestamp': timestamp,
        'label': label,
        'registers': regs,
        'regions': {},
    }

    for region_name, region_info in REGIONS.items():
        addr = region_info['addr']
        size = region_info['size']
        desc = region_info['desc']

        print(f"\n=== {desc} (0x{addr:08X}, {size} bytes) ===")
        data = client.read_memory(addr, size)

        # Display named fields
        for offset, (name, fmt, field_desc) in region_info.get('fields', {}).items():
            print(format_field(data, offset, fmt, name, field_desc))

        # Display hex dump (first 64 bytes)
        dump_size = min(size, 64)
        print(hex_dump(data[:dump_size], addr))

        # Store in snapshot
        snapshot['regions'][region_name] = {
            'addr': addr,
            'size': size,
            'data': data.hex(),
            'fields': {}
        }
        for offset, (name, fmt, field_desc) in region_info.get('fields', {}).items():
            try:
                if fmt == 'u32':
                    val = struct.unpack_from('<I', data, offset)[0]
                elif fmt == 'f32':
                    val = struct.unpack_from('<f', data, offset)[0]
                elif fmt == 'u8':
                    val = data[offset]
                elif fmt == 'u16':
                    val = struct.unpack_from('<H', data, offset)[0]
                else:
                    val = None
                snapshot['regions'][region_name]['fields'][name] = val
            except (struct.error, IndexError):
                snapshot['regions'][region_name]['fields'][name] = None

    # Follow pointers
    print("\n=== Following Pointers ===")
    for region_name, offset, follow_size, desc in FOLLOW_POINTERS:
        region = REGIONS.get(region_name)
        if not region:
            continue
        data = client.read_memory(region['addr'], region['size'])
        try:
            ptr = struct.unpack_from('<I', data, offset)[0]
        except struct.error:
            continue

        if ptr == 0 or ptr > 0x10000000:
            print(f"\n  {desc}: ptr = 0x{ptr:08X} (NULL or out of range, skipping)")
            continue

        print(f"\n  {desc}: ptr = 0x{ptr:08X}")
        follow_data = client.read_memory(ptr, follow_size)
        print(hex_dump(follow_data[:64], ptr))

        snapshot['regions'][f'follow_{region_name}_{offset:x}'] = {
            'addr': ptr,
            'size': follow_size,
            'data': follow_data.hex(),
            'desc': desc,
        }

    # Save snapshot
    os.makedirs(output_dir, exist_ok=True)
    json_path = os.path.join(output_dir, f"{filename}.json")
    with open(json_path, 'w') as f:
        json.dump(snapshot, f, indent=2, default=str)
    print(f"\nSnapshot saved to {json_path}")

    # Save human-readable report
    txt_path = os.path.join(output_dir, f"{filename}.txt")
    with open(txt_path, 'w') as f:
        f.write(f"Burnout 3 Memory Snapshot: {label or 'unlabeled'}\n")
        f.write(f"Timestamp: {timestamp}\n")
        f.write(f"{'=' * 60}\n\n")
        f.write("Registers:\n")
        for name in ['eax', 'ecx', 'edx', 'ebx', 'esp', 'ebp', 'esi', 'edi', 'eip']:
            if name in regs:
                f.write(f"  {name} = 0x{regs[name]:08X}\n")
        f.write("\n")
        for region_name, region_info in REGIONS.items():
            addr = region_info['addr']
            size = region_info['size']
            data_hex = snapshot['regions'][region_name]['data']
            data = bytes.fromhex(data_hex)
            f.write(f"{region_info['desc']} (0x{addr:08X}):\n")
            for offset, (name, fmt, desc) in region_info.get('fields', {}).items():
                f.write(format_field(data, offset, fmt, name, desc) + '\n')
            f.write(hex_dump(data[:min(size, 64)], addr) + '\n\n')
    print(f"Report saved to {txt_path}")

    return snapshot


def main():
    parser = argparse.ArgumentParser(description='Burnout 3 memory snapshot from xemu')
    parser.add_argument('--host', default='localhost', help='GDB host (default: localhost)')
    parser.add_argument('--port', type=int, default=1234, help='GDB port (default: 1234)')
    parser.add_argument('--output', default='tools/xemu_debug/snapshots',
                        help='Output directory for snapshots')
    parser.add_argument('--label', default='', help='Label for this snapshot')
    parser.add_argument('--continuous', action='store_true',
                        help='Take snapshots continuously every 5 seconds')
    args = parser.parse_args()

    client = GDBClient(args.host, args.port)
    try:
        client.connect()
    except ConnectionRefusedError:
        print(f"ERROR: Cannot connect to GDB stub at {args.host}:{args.port}")
        print("Make sure xemu is running with -s flag:")
        print('  xemu.exe -s -S')
        sys.exit(1)

    try:
        # Halt the guest to read consistent memory
        print("Halting guest...")
        client.halt()
        time.sleep(0.2)

        if args.continuous:
            i = 0
            while True:
                take_snapshot(client, args.output, label=f"{args.label}_{i:04d}" if args.label else f"auto_{i:04d}")
                client.continue_execution()
                time.sleep(5.0)
                client.halt()
                time.sleep(0.2)
                i += 1
        else:
            take_snapshot(client, args.output, label=args.label)

        # Resume guest
        print("\nResuming guest...")
        client.continue_execution()

    except KeyboardInterrupt:
        print("\nInterrupted. Resuming guest...")
        try:
            client.continue_execution()
        except Exception:
            pass
    finally:
        client.disconnect()


if __name__ == '__main__':
    main()
