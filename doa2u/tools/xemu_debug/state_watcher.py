"""
Game state watcher for Burnout 3 running in xemu.

Monitors game state transitions by polling key memory addresses.
Logs every state change with timestamps and snapshots of surrounding memory.

This helps us understand the exact boot sequence and state machine.

Usage:
    py -3 -m tools.xemu_debug.state_watcher [--port 1234]
"""

import os
import sys
import time
import struct
import argparse
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient


# Key addresses to watch
WATCH_ADDRS = {
    'game_state':   (0x4D53BE, 'u8',  'Game state (S1-S13+)'),
    'load_state':   (0x4D53C0, 'u8',  'Load sub-state (0x00-0x17)'),
    'frame_count':  (0x4D53C4, 'u32', 'Frame counter (if exists)'),
    'rw_world':     (0x4D5370, 'u32', 'RW world pointer'),
    'car_obj':      (0x557880, 'u32', 'Car object first dword'),
    'track_env':    (0x464018, 'u32', 'Track env pointer'),
    'eip':          (None,     'reg', 'Instruction pointer'),
}

# State names (see NOTES.md)
STATE_NAMES = {
    0: 'S0_PREINIT',
    1: 'S1_INIT',
    2: 'S2_ALLOC',
    3: 'S3_GLOBAL_TXD',
    4: 'S4_PROCESS',
    5: 'S5_VLIST',
    6: 'S6_TLIST',
    7: 'S7_PRGDATA',
    8: 'S8_SCENE',
    9: 'S9_AUDIO',
    10: 'S10_UNKNOWN',
    11: 'S11_ICON',
    12: 'S12_UNKNOWN',
    13: 'S13_TRACK',
}


def read_value(client: GDBClient, addr: int, fmt: str):
    """Read a value from memory."""
    if fmt == 'u8':
        data = client.read_memory(addr, 1)
        return data[0] if data else 0
    elif fmt == 'u16':
        data = client.read_memory(addr, 2)
        return struct.unpack('<H', data)[0] if len(data) >= 2 else 0
    elif fmt == 'u32':
        return client.read_u32(addr)
    elif fmt == 'f32':
        return client.read_f32(addr)
    elif fmt == 'reg':
        return None  # Handled separately via register read
    return 0


def main():
    parser = argparse.ArgumentParser(description='Burnout 3 state watcher')
    parser.add_argument('--host', default='localhost')
    parser.add_argument('--port', type=int, default=1234)
    parser.add_argument('--interval', type=float, default=0.5,
                        help='Poll interval in seconds (default: 0.5)')
    parser.add_argument('--output', default='tools/xemu_debug/state_log.txt',
                        help='Output log file')
    args = parser.parse_args()

    client = GDBClient(args.host, args.port)
    try:
        client.connect()
    except ConnectionRefusedError:
        print(f"ERROR: Cannot connect to {args.host}:{args.port}")
        print("Start xemu with: xemu.exe -s")
        sys.exit(1)

    log_file = open(args.output, 'w')
    log_file.write(f"Burnout 3 State Watcher - {datetime.now()}\n")
    log_file.write("=" * 80 + "\n\n")

    prev_values = {}
    iteration = 0

    print("Watching game state... (Ctrl+C to stop)")
    print(f"Logging to {args.output}")
    print()

    try:
        while True:
            # Halt briefly to read consistent state
            client.halt()
            time.sleep(0.05)

            # Read registers
            regs = client.read_registers()
            eip = regs.get('eip', 0)

            # Read all watched addresses
            current = {}
            for name, (addr, fmt, desc) in WATCH_ADDRS.items():
                if fmt == 'reg':
                    current[name] = eip
                else:
                    current[name] = read_value(client, addr, fmt)

            # Check for changes
            changes = []
            for name, val in current.items():
                prev = prev_values.get(name)
                if prev is not None and prev != val:
                    _, fmt, desc = WATCH_ADDRS[name]
                    if fmt in ('u32', 'reg'):
                        change_str = f"  {name}: 0x{prev:08X} -> 0x{val:08X}  ({desc})"
                    elif fmt == 'u8':
                        old_state = STATE_NAMES.get(prev, f'?{prev}') if name == 'game_state' else f'{prev}'
                        new_state = STATE_NAMES.get(val, f'?{val}') if name == 'game_state' else f'{val}'
                        change_str = f"  {name}: {old_state} -> {new_state}  ({desc})"
                    elif fmt == 'f32':
                        change_str = f"  {name}: {prev:.4f} -> {val:.4f}  ({desc})"
                    else:
                        change_str = f"  {name}: {prev} -> {val}  ({desc})"
                    changes.append(change_str)

            if changes or iteration == 0:
                ts = datetime.now().strftime('%H:%M:%S.%f')[:-3]
                header = f"[{ts}] iter={iteration}"

                if iteration == 0:
                    header += " (initial state)"

                print(header)
                log_file.write(header + "\n")

                # Show current state
                game_state = current.get('game_state', 0)
                state_name = STATE_NAMES.get(game_state, f'UNKNOWN_{game_state}')
                status = f"  STATE={state_name} LOAD=0x{current.get('load_state', 0):02X} EIP=0x{eip:08X}"
                print(status)
                log_file.write(status + "\n")

                for c in changes:
                    print(c)
                    log_file.write(c + "\n")

                # On game state change, take a detailed snapshot
                if 'game_state' in [name for name, (addr, fmt, desc) in WATCH_ADDRS.items()
                                     if prev_values.get(name) is not None and prev_values.get(name) != current.get(name)]:
                    print("  >> STATE TRANSITION - capturing extended snapshot")
                    log_file.write("  >> STATE TRANSITION\n")

                    # Read additional context
                    car_data = client.read_memory(0x557880, 0x20)
                    rw_data = client.read_memory(0x4D5370, 0x10)

                    car_hex = ' '.join(f'{b:02X}' for b in car_data)
                    rw_hex = ' '.join(f'{b:02X}' for b in rw_data)

                    detail = f"  car[0x557880]: {car_hex}\n  rw [0x4D5370]: {rw_hex}"
                    print(detail)
                    log_file.write(detail + "\n")

                print()
                log_file.write("\n")
                log_file.flush()

            prev_values = current.copy()

            # Resume and wait
            client.continue_execution()
            time.sleep(args.interval)
            iteration += 1

    except KeyboardInterrupt:
        print("\nStopping watcher...")
    finally:
        try:
            client.continue_execution()
        except Exception:
            pass
        client.disconnect()
        log_file.close()
        print(f"Log saved to {args.output}")


if __name__ == '__main__':
    main()
