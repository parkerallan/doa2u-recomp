"""
NV2A render state tracer for Burnout 3 running in xemu.

Captures D3D/NV2A state at specific breakpoints to understand
the game's rendering pipeline. Works by setting breakpoints at
known D3D-related functions and logging GPU state.

This is used to understand what render states, textures, and
transforms the game sets up for each draw call, so we can
reproduce them in our D3D8->D3D11 translation layer.

Usage:
    py -3 -m tools.xemu_debug.render_trace [--port 1234]
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


# ── Known D3D/rendering function addresses in Burnout 3 ──
# These are from our func_id analysis

RENDER_BREAKPOINTS = {
    # Main render orchestrator (currently stubbed in our recomp)
    0x0003D9E0: 'render_orchestrator',

    # Frame pump - called every frame
    0x000110E0: 'frame_pump',

    # RenderWare camera begin/end
    # TODO: fill in from func_id output when we identify them
}

# ── NV2A register addresses readable from guest ──
# The game writes to these via D3D8 calls which become NV2A push buffer commands
# We can read the game's D3D state tables from guest memory instead

# D3D8 device state offsets (relative to device pointer)
# Xbox D3D8 stores render states in the device object
D3D_STATE_OFFSETS = {
    'viewport_x':       0x0A60,
    'viewport_y':       0x0A64,
    'viewport_width':   0x0A68,
    'viewport_height':  0x0A6C,
    # World/view/proj matrices are at device + 0x0480 area
    # Texture stage states at device + 0x0B00 area
}

# ── D3D state memory locations ──
# From our static recomp analysis of the D3D8 library code

D3D_GLOBALS = {
    'device_ptr':       0x4A2340,   # IDirect3DDevice8* (verify in xemu)
    'push_buffer_ptr':  0x4A2344,   # Push buffer object
}


def capture_render_state(client: GDBClient, output_dir: str, frame_num: int):
    """Capture the current D3D render state from guest memory."""

    print(f"\n=== Render State Capture (frame {frame_num}) ===")

    # Read D3D device pointer
    device_ptr = client.read_u32(D3D_GLOBALS['device_ptr'])
    print(f"  D3D Device: 0x{device_ptr:08X}")

    state = {
        'frame': frame_num,
        'timestamp': datetime.now().isoformat(),
        'device_ptr': device_ptr,
    }

    if device_ptr == 0 or device_ptr > 0x10000000:
        print("  Device pointer is NULL or invalid - game may not have initialized D3D yet")
        return state

    # Read device object header (first 256 bytes)
    device_data = client.read_memory(device_ptr, 0x100)
    vtable_ptr = struct.unpack_from('<I', device_data, 0)[0]
    print(f"  Device vtable: 0x{vtable_ptr:08X}")
    state['vtable'] = vtable_ptr

    # Try to read viewport
    for name, offset in D3D_STATE_OFFSETS.items():
        try:
            val = client.read_u32(device_ptr + offset)
            state[name] = val
            print(f"  {name}: 0x{val:08X} ({val})")
        except Exception:
            pass

    # Read the world/view/projection matrix area (4x4 floats each = 64 bytes)
    # Xbox D3D8 stores these starting around device+0x0480
    matrix_base = device_ptr + 0x0480
    for mat_name, mat_offset in [('world', 0), ('view', 0x40), ('proj', 0x80)]:
        mat_data = client.read_memory(matrix_base + mat_offset, 64)
        if len(mat_data) == 64:
            floats = struct.unpack('<16f', mat_data)
            mat = [list(floats[i*4:(i+1)*4]) for i in range(4)]
            state[f'{mat_name}_matrix'] = mat

            # Check if it's identity or interesting
            is_identity = all(
                abs(mat[i][j] - (1.0 if i == j else 0.0)) < 0.001
                for i in range(4) for j in range(4)
            )
            if is_identity:
                print(f"  {mat_name} matrix: identity")
            else:
                print(f"  {mat_name} matrix: [{mat[0][0]:.3f}, {mat[0][1]:.3f}, {mat[0][2]:.3f}, {mat[0][3]:.3f}]")
                print(f"                     [{mat[1][0]:.3f}, {mat[1][1]:.3f}, {mat[1][2]:.3f}, {mat[1][3]:.3f}]")
                print(f"                     [{mat[2][0]:.3f}, {mat[2][1]:.3f}, {mat[2][2]:.3f}, {mat[2][3]:.3f}]")
                print(f"                     [{mat[3][0]:.3f}, {mat[3][1]:.3f}, {mat[3][2]:.3f}, {mat[3][3]:.3f}]")

    # Read texture stage 0 state
    # Xbox D3D8 texture state is around device+0x0B00
    tex_base = device_ptr + 0x0B00
    tex_data = client.read_memory(tex_base, 0x40)
    if len(tex_data) >= 0x40:
        state['texture_stage_0'] = tex_data.hex()
        print(f"  Texture stage 0 raw: {tex_data[:16].hex()}")

    # Read active texture pointer
    # Xbox D3D8 stores current textures in device state
    active_tex = device_ptr + 0x0A80
    for i in range(4):
        tex_ptr = client.read_u32(active_tex + i * 4)
        if tex_ptr != 0:
            state[f'active_texture_{i}'] = tex_ptr
            print(f"  Active texture {i}: 0x{tex_ptr:08X}")

    return state


def capture_frame_sequence(client: GDBClient, output_dir: str, num_frames: int = 10):
    """
    Capture render state over multiple frames.

    Sets a breakpoint at the frame pump and captures state at each frame.
    """
    print(f"Capturing {num_frames} frames of render state...")
    os.makedirs(output_dir, exist_ok=True)

    # Set breakpoint at frame pump
    frame_pump_addr = 0x000110E0
    if not client.set_breakpoint(frame_pump_addr):
        print(f"WARNING: Could not set breakpoint at 0x{frame_pump_addr:08X}")
        print("Trying render orchestrator instead...")
        frame_pump_addr = 0x0003D9E0
        client.set_breakpoint(frame_pump_addr)

    frames = []
    for i in range(num_frames):
        print(f"\n--- Frame {i+1}/{num_frames} ---")

        # Continue to next breakpoint
        client.continue_execution()
        stop = client.wait_for_stop(timeout=30.0)

        if stop == 'timeout':
            print("Timeout waiting for breakpoint hit")
            break

        # Capture state
        regs = client.read_registers()
        eip = regs.get('eip', 0)
        print(f"  Stopped at EIP=0x{eip:08X}")

        state = capture_render_state(client, output_dir, i)
        state['registers'] = regs
        frames.append(state)

    # Clean up breakpoint
    client.remove_breakpoint(frame_pump_addr)

    # Save all frames
    output_path = os.path.join(output_dir, 'render_trace.json')
    with open(output_path, 'w') as f:
        json.dump(frames, f, indent=2, default=str)
    print(f"\nRender trace saved to {output_path}")

    return frames


def main():
    parser = argparse.ArgumentParser(description='Burnout 3 render state tracer')
    parser.add_argument('--host', default='localhost')
    parser.add_argument('--port', type=int, default=1234)
    parser.add_argument('--output', default='tools/xemu_debug/render_traces')
    parser.add_argument('--frames', type=int, default=10,
                        help='Number of frames to capture')
    parser.add_argument('--single', action='store_true',
                        help='Just capture current state without breakpoints')
    args = parser.parse_args()

    client = GDBClient(args.host, args.port)
    try:
        client.connect()
    except ConnectionRefusedError:
        print(f"ERROR: Cannot connect to {args.host}:{args.port}")
        sys.exit(1)

    try:
        if args.single:
            client.halt()
            time.sleep(0.2)
            state = capture_render_state(client, args.output, 0)
            os.makedirs(args.output, exist_ok=True)
            with open(os.path.join(args.output, 'single_capture.json'), 'w') as f:
                json.dump(state, f, indent=2, default=str)
            client.continue_execution()
        else:
            capture_frame_sequence(client, args.output, args.frames)
    except KeyboardInterrupt:
        print("\nInterrupted.")
    finally:
        try:
            client.continue_execution()
        except Exception:
            pass
        client.disconnect()


if __name__ == '__main__':
    main()
