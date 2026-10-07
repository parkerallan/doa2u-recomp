#!/bin/bash
# Launch xemu with debugging enabled for Burnout 3 analysis.
#
# This starts xemu with:
#   -s     GDB stub on port 1234
#   -S     Pause at startup (optional, remove for auto-boot)
#   --trace  NV2A GPU tracing (optional, creates large log files)
#
# Usage:
#   bash tools/xemu_debug/launch_debug.sh [--trace] [--pause]

XEMU_DIR="C:/emu/xemu-win-release"
XEMU_EXE="$XEMU_DIR/xemu.exe"

# Check xemu exists
if [ ! -f "$XEMU_EXE" ]; then
    echo "ERROR: xemu not found at $XEMU_EXE"
    echo "Set XEMU_DIR to your xemu installation directory"
    exit 1
fi

# Parse args
PAUSE_FLAG=""
TRACE_FLAGS=""
for arg in "$@"; do
    case $arg in
        --pause)
            PAUSE_FLAG="-S"
            echo "Will pause at startup (connect GDB before continuing)"
            ;;
        --trace)
            TRACE_FLAGS='--trace "nv2a_pgraph_method" --trace "nv2a_pgraph_method_unhandled" --trace "nv2a_pgraph_surface_create_color" --trace "nv2a_pgraph_surface_create_zeta"'
            echo "GPU tracing enabled (WARNING: creates large log files)"
            ;;
        --trace-all)
            TRACE_FLAGS='--trace "nv2a_*"'
            echo "Full NV2A tracing enabled (WARNING: VERY large log files)"
            ;;
    esac
done

echo "Starting xemu with GDB stub on port 1234..."
echo "  Connect with: py -3 -m tools.xemu_debug.memory_snapshot"
echo "  Or GDB:       gdb -ex 'target remote localhost:1234'"
echo ""

# Launch xemu with GDB stub
# The -s flag enables the GDB stub on TCP port 1234
cmd.exe //c "start \"xemu-debug\" \"$XEMU_EXE\" -s $PAUSE_FLAG $TRACE_FLAGS"

echo "xemu launched. Waiting for it to start..."
sleep 3

# Verify it's running
if tasklist 2>/dev/null | grep -qi xemu; then
    echo "xemu is running. GDB stub should be available on port 1234."
    echo ""
    echo "Quick start:"
    echo "  1. Let the game boot to gameplay"
    echo "  2. Run: py -3 -m tools.xemu_debug.memory_snapshot --label gameplay"
    echo "  3. Run: py -3 -m tools.xemu_debug.state_watcher"
    echo "  4. Run: py -3 -m tools.xemu_debug.physics_inspector"
    echo "  5. Run: py -3 -m tools.xemu_debug.render_trace --single"
else
    echo "WARNING: xemu may not have started. Check for errors."
fi
