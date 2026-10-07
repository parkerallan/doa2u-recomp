"""
Burnout 3 - Inner State Machine & Render Orchestrator Trace

Captures two things from xemu:
1. Inner state machine (sub_001AA100) phase values at ebp+0x144384
   - Traces the progression from boot → press start → main menu → gameplay
2. Render orchestrator (sub_0003D9E0) call tree
   - Which child functions get called and with what esi/edi values

Usage:
    1. Start xemu with GDB stub:  xemu.exe -s
    2. Boot the Burnout 3 ISO normally
    3. Run this script:  py -3 -m tools.xemu_debug.menu_state_trace [--port 1234]
    4. Interact with the game in xemu (press start, navigate menus, etc.)
    5. Ctrl+C to stop. Share the output log.

The script polls (halt/read/continue) so expect some slowdown.
"""

import os
import socket
import sys
import time
import struct
import argparse
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient


# === Key addresses ===

# Inner state machine phase (sub_001AA100 reads/writes MEM32(ebp + 0x144384))
# ebp is the "game manager" base pointer. We don't know its value ahead of time,
# but we can find it from 0x3F9040 (game manager global).
GAME_MANAGER_PTR = 0x3F9040  # Points to the game manager object

# sub_001AA100 entry point (Xbox VA)
INNER_STATE_FUNC = 0x001AA100

# sub_0003D9E0 (render orchestrator) and its children
RENDER_ORCH = 0x0003D9E0
RENDER_CHILD_1 = 0x0002F330  # First call in sub_0003D9E0
RENDER_CHILD_2 = 0x0034D530  # Camera/viewport setup (conditional on edi==0)
RENDER_CHILD_3 = 0x00040660  # Main render dispatch

# sub_000165F0 outer state machine (the 12-state loader)
OUTER_STATE_FUNC = 0x000165F0

# Outer state: MEM8(0x4D53BE)
OUTER_STATE_ADDR = 0x4D53BE

# Other useful addresses
RW_WORLD_PTR = 0x4D5370
CAR_OBJ = 0x557880
TRACK_ENV = 0x464018
CAMERA_PTR_MENU = 0x4D4008
CAMERA_PTR_GAME = 0x4D45D0

# Phase names for inner state machine (from recomp_0004.c analysis)
INNER_PHASE_NAMES = {
    0: "UNINIT",
    1: "BOOT_INIT",
    2: "BOOT_WAIT",
    3: "PRESS_START",
    4: "PRESS_START_WAIT",
    5: "MAIN_MENU_INIT",
    6: "MAIN_MENU_ACTIVE",
    7: "MODE_SELECT",
    8: "TRACK_SELECT",
    9: "LOADING_INIT",
    0xA: "LOADING",
    0xB: "LOADING_DONE",
    0xC: "GAMEPLAY_INIT",
    0xD: "GAMEPLAY_ACTIVE",
    0xE: "GAMEPLAY_PAUSE",
    0xF: "RESULTS_INIT",
    0x10: "RESULTS",
    0x11: "REPLAY",
    0x12: "RETURN_MENU",
    0x13: "SHUTDOWN",
}

OUTER_STATE_NAMES = {
    0: 'S0_PREINIT', 1: 'S1_INIT', 2: 'S2_ALLOC', 3: 'S3_GLOBAL_TXD',
    4: 'S4_PROCESS', 5: 'S5_VLIST', 6: 'S6_TLIST', 7: 'S7_PRGDATA',
    8: 'S8_SCENE', 9: 'S9_AUDIO', 10: 'S10', 11: 'S11_ICON',
    12: 'S12', 13: 'S13_TRACK',
}


def read_inner_phase(client, game_mgr_base):
    """Read the inner state machine phase from ebp+0x144384."""
    if game_mgr_base == 0:
        return -1
    addr = game_mgr_base + 0x144384
    try:
        return client.read_u32(addr)
    except Exception:
        return -1


def read_game_manager_base(client):
    """Try to find the game manager base (ebp value for sub_001AA100)."""
    # The game manager pointer at 0x3F9040 should point to the object
    # ebp in sub_001AA100 is set from the outer state machine's stack frame
    # Try reading the game manager global
    ptr = client.read_u32(GAME_MANAGER_PTR)
    if 0x10000 < ptr < 0x8000000:
        return ptr
    return 0


def log_and_print(log_file, msg):
    """Print to console and write to log."""
    print(msg)
    log_file.write(msg + "\n")
    log_file.flush()


def main():
    parser = argparse.ArgumentParser(
        description='Burnout 3 inner state machine & render orchestrator trace')
    parser.add_argument('--host', default='localhost')
    parser.add_argument('--port', type=int, default=1234)
    parser.add_argument('--interval', type=float, default=0.3,
                        help='Poll interval in seconds (default: 0.3)')
    parser.add_argument('--output', default='tools/xemu_debug/menu_state_log.txt',
                        help='Output log file')
    parser.add_argument('--breakpoint', action='store_true',
                        help='Use breakpoints instead of polling (more precise but slower)')
    args = parser.parse_args()

    client = GDBClient(args.host, args.port)
    try:
        client.connect()
    except ConnectionRefusedError:
        print(f"ERROR: Cannot connect to {args.host}:{args.port}")
        print("Start xemu with: xemu.exe -s")
        sys.exit(1)

    log_file = open(args.output, 'w')
    log_and_print(log_file, f"Burnout 3 Menu State Trace - {datetime.now()}")
    log_and_print(log_file, "=" * 80)
    log_and_print(log_file, "")
    log_and_print(log_file, "Tracing inner state machine (sub_001AA100) and render orchestrator (sub_0003D9E0)")
    log_and_print(log_file, "Interact with the game in xemu. Ctrl+C to stop.")
    log_and_print(log_file, "")

    # Track previous values for change detection
    prev = {
        'outer_state': -1,
        'inner_phase': -1,
        'game_mgr': 0,
        'rw_world': 0,
        'cam_menu': 0,
        'cam_game': 0,
        'track_env': 0,
    }

    iteration = 0

    if args.breakpoint:
        # Breakpoint mode: set BP at sub_001AA100 entry
        log_and_print(log_file, "MODE: Breakpoint (setting BP at 0x001AA100)")
        client.set_breakpoint(INNER_STATE_FUNC)
        client.set_breakpoint(RENDER_ORCH)

    try:
        while True:
            ts = datetime.now().strftime('%H:%M:%S.%f')[:-3]

            if args.breakpoint:
                # Wait for breakpoint hit
                client.continue_execution()
                stop = client.wait_for_stop(timeout=10.0)
                if stop == 'timeout':
                    continue

                regs = client.read_registers()
                eip = regs.get('eip', 0)
                ebp = regs.get('ebp', 0)
                esi = regs.get('esi', 0)
                edi = regs.get('edi', 0)

                if eip == INNER_STATE_FUNC:
                    phase = read_inner_phase(client, ebp)
                    phase_name = INNER_PHASE_NAMES.get(phase, f"UNKNOWN_{phase}")
                    log_and_print(log_file,
                        f"[{ts}] BP sub_001AA100: phase={phase} ({phase_name}) "
                        f"ebp=0x{ebp:08X} esi=0x{esi:08X}")

                elif eip == RENDER_ORCH:
                    log_and_print(log_file,
                        f"[{ts}] BP sub_0003D9E0: esi=0x{esi:08X} edi=0x{edi:08X}")

                    # Read what esi points to for context
                    if 0x10000 < esi < 0x8000000:
                        esi_data = client.read_memory(esi, 16)
                        hex_str = ' '.join(f'{b:02X}' for b in esi_data)
                        log_and_print(log_file, f"  esi[0:16]: {hex_str}")

                        # esi+0x3B0 = render state ptr, esi+0x500 = render context
                        ptr_3b0 = client.read_u32(esi + 0x3B0)
                        log_and_print(log_file, f"  esi+0x3B0=0x{ptr_3b0:08X}")

            else:
                # Polling mode: halt, read state, resume
                try:
                    client.halt()
                    time.sleep(0.1)  # Give CPU time to fully stop

                    # Drain any pending data
                    client.sock.settimeout(0.3)
                    try:
                        client.sock.recv(4096)
                    except socket.timeout:
                        pass
                    client.sock.settimeout(5.0)
                except Exception as e:
                    log_and_print(log_file, f"[{ts}] halt error: {e}")
                    time.sleep(1)
                    iteration += 1
                    continue

                # Read outer state
                try:
                    outer_state = client.read_memory(OUTER_STATE_ADDR, 1)[0]
                except Exception as e:
                    log_and_print(log_file, f"[{ts}] read error: {e}")
                    try:
                        client.continue_execution()
                    except Exception:
                        pass
                    time.sleep(1)
                    iteration += 1
                    continue

                # Read all state in one block
                try:
                    game_mgr = read_game_manager_base(client)
                    inner_phase = read_inner_phase(client, game_mgr) if game_mgr else -1
                    rw_world = client.read_u32(RW_WORLD_PTR)
                    cam_menu = client.read_u32(CAMERA_PTR_MENU)
                    cam_game = client.read_u32(CAMERA_PTR_GAME)
                    track_env = client.read_u32(TRACK_ENV)
                    regs = client.read_registers()
                    eip = regs.get('eip', 0)
                except Exception as e:
                    log_and_print(log_file, f"[{ts}] bulk read error: {e}")
                    try:
                        client.continue_execution()
                    except Exception:
                        pass
                    time.sleep(1)
                    iteration += 1
                    continue

                # Detect changes
                changed = False
                changes = []

                if outer_state != prev['outer_state']:
                    oname = OUTER_STATE_NAMES.get(outer_state, f'?{outer_state}')
                    prev_name = OUTER_STATE_NAMES.get(prev['outer_state'], f'?{prev["outer_state"]}')
                    changes.append(f"  OUTER: {prev_name} -> {oname}")
                    changed = True

                if inner_phase != prev['inner_phase']:
                    pname = INNER_PHASE_NAMES.get(inner_phase, f'UNKNOWN_{inner_phase}')
                    prev_pname = INNER_PHASE_NAMES.get(prev['inner_phase'], f'UNKNOWN_{prev["inner_phase"]}')
                    changes.append(f"  INNER: {prev_pname} -> {pname} (phase {prev['inner_phase']} -> {inner_phase})")
                    changed = True

                if game_mgr != prev['game_mgr'] and game_mgr != 0:
                    changes.append(f"  GAME_MGR: 0x{prev['game_mgr']:08X} -> 0x{game_mgr:08X}")
                    changed = True

                if rw_world != prev['rw_world']:
                    changes.append(f"  RW_WORLD(0x4D5370): 0x{prev['rw_world']:08X} -> 0x{rw_world:08X}")
                    changed = True

                if cam_menu != prev['cam_menu']:
                    changes.append(f"  CAM_MENU(0x4D4008): 0x{prev['cam_menu']:08X} -> 0x{cam_menu:08X}")
                    changed = True

                if cam_game != prev['cam_game']:
                    changes.append(f"  CAM_GAME(0x4D45D0): 0x{prev['cam_game']:08X} -> 0x{cam_game:08X}")
                    changed = True

                if track_env != prev['track_env']:
                    changes.append(f"  TRACK_ENV(0x464018): 0x{prev['track_env']:08X} -> 0x{track_env:08X}")
                    changed = True

                # Print on change or every 20th iteration
                if changed or iteration == 0 or (iteration % 20 == 0):
                    outer_name = OUTER_STATE_NAMES.get(outer_state, f'?{outer_state}')
                    phase_name = INNER_PHASE_NAMES.get(inner_phase, f'?{inner_phase}')

                    header = f"[{ts}] #{iteration} outer={outer_name} inner={phase_name}({inner_phase})"
                    header += f" mgr=0x{game_mgr:08X} eip=0x{eip:08X}"
                    log_and_print(log_file, header)

                    for c in changes:
                        log_and_print(log_file, c)

                    # On inner phase change, dump extra context
                    if inner_phase != prev['inner_phase'] and game_mgr:
                        # Read game manager +0x40 (world pointer changes between menus/gameplay)
                        world_at_40 = client.read_u32(game_mgr + 0x40)
                        log_and_print(log_file, f"  mgr+0x40 (world): 0x{world_at_40:08X}")

                        # Read ebp+0x12B790 (referenced in sub_001AA100 diagnostics)
                        val_12b790 = client.read_u32(game_mgr + 0x12B790)
                        log_and_print(log_file, f"  mgr+0x12B790: 0x{val_12b790:08X}")

                        # Read 32 bytes at game_mgr+0x144380 for context around the phase
                        ctx_data = client.read_memory(game_mgr + 0x144380, 32)
                        ctx_hex = ' '.join(f'{b:02X}' for b in ctx_data)
                        log_and_print(log_file, f"  mgr+0x144380[32]: {ctx_hex}")

                    if changed:
                        log_and_print(log_file, "")

                # Update prev
                prev.update({
                    'outer_state': outer_state,
                    'inner_phase': inner_phase,
                    'game_mgr': game_mgr if game_mgr else prev['game_mgr'],
                    'rw_world': rw_world,
                    'cam_menu': cam_menu,
                    'cam_game': cam_game,
                    'track_env': track_env,
                })

                # Resume
                client.continue_execution()
                time.sleep(args.interval)

            iteration += 1

    except KeyboardInterrupt:
        log_and_print(log_file, "\nStopping trace...")
    finally:
        if args.breakpoint:
            try:
                client.remove_breakpoint(INNER_STATE_FUNC)
                client.remove_breakpoint(RENDER_ORCH)
            except Exception:
                pass
        try:
            client.continue_execution()
        except Exception:
            pass
        client.disconnect()
        log_file.close()
        print(f"\nLog saved to {args.output}")
        print("Please share this log file back so we can analyze the state transitions.")


if __name__ == '__main__':
    main()
