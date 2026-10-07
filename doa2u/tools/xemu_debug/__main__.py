"""
xemu debug tools for Burnout 3 static recompilation.

Launch xemu with -s flag to enable GDB stub on port 1234,
then use these tools to inspect the game's runtime behavior.

Usage:
    py -3 -m tools.xemu_debug <command> [args]

Commands:
    snapshot    - Take a memory snapshot of key game addresses
    watch       - Monitor game state transitions in real-time
    physics     - Inspect the physics body structure at sub_000636D0
    render      - Capture D3D render state at frame boundaries
    compare     - Compare xemu snapshot against recompiled version
"""

import sys

COMMANDS = {
    'snapshot':   'tools.xemu_debug.memory_snapshot',
    'watch':      'tools.xemu_debug.state_watcher',
    'physics':    'tools.xemu_debug.physics_inspector',
    'render':     'tools.xemu_debug.render_trace',
    'compare':    'tools.xemu_debug.compare_snapshots',
    'renderdoc':  'tools.xemu_debug.renderdoc_capture',
}

def main():
    if len(sys.argv) < 2 or sys.argv[1] in ('-h', '--help', 'help'):
        print(__doc__)
        print("Available commands:")
        for name, module in COMMANDS.items():
            print(f"  {name:12s}  ({module})")
        print()
        print("Example:")
        print("  # 1. Start xemu with GDB stub:")
        print("  #    bash tools/xemu_debug/launch_debug.sh")
        print("  # 2. Let game boot to gameplay, then:")
        print("  py -3 -m tools.xemu_debug snapshot --label gameplay")
        print("  py -3 -m tools.xemu_debug watch")
        print("  py -3 -m tools.xemu_debug physics --samples 20")
        print("  py -3 -m tools.xemu_debug render --single")
        return

    cmd = sys.argv[1]
    if cmd not in COMMANDS:
        print(f"Unknown command: {cmd}")
        print(f"Available: {', '.join(COMMANDS.keys())}")
        sys.exit(1)

    # Remove the command name from argv and run the module
    sys.argv = [sys.argv[0]] + sys.argv[2:]
    module = COMMANDS[cmd]

    import importlib
    mod = importlib.import_module(module)
    mod.main()


if __name__ == '__main__':
    main()
