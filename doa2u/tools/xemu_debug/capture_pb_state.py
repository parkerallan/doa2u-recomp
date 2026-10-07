"""
Capture push buffer for a single menu state.
Usage: py -3 tools/xemu_debug/capture_pb_state.py <state_name>
Navigate xemu to the desired state first, then run this script.
"""
import sys, struct, time, os
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

NV2A_BASE = 0xFD000000
PFIFO_BASE = NV2A_BASE + 0x002000

def r32(c, a):
    d = c.read_memory(a, 4)
    return struct.unpack('<I', d)[0] if d and len(d) >= 4 else 0

def main():
    if len(sys.argv) < 2:
        print("Usage: py -3 tools/xemu_debug/capture_pb_state.py <state_name>")
        sys.exit(1)

    name = sys.argv[1].replace(' ', '_').lower()

    c = GDBClient('localhost', 1234)
    c.connect()

    print(f"Capturing state: {name}")
    c.halt()
    time.sleep(0.5)

    # Read PFIFO
    dma_put = r32(c, PFIFO_BASE + 0x1240)
    dma_get = r32(c, PFIFO_BASE + 0x1244)
    dma_inst = r32(c, PFIFO_BASE + 0x122C)

    # Known push buffer base from previous captures
    pb_base = 0x81FC3000
    cap_size = 65536  # 64KB captures full frame
    print(f"  PB base=0x{pb_base:08X} PUT=0x{dma_put:X} size={cap_size}")

    data = b''
    for off in range(0, cap_size, 0x400):
        rem = min(0x400, cap_size - off)
        chunk = c.read_memory(pb_base + off, rem)
        data += chunk if chunk and len(chunk) == rem else b'\x00' * rem

    dwords = len(data) // 4
    path = os.path.join("src", "nv2a", f"menu_pb_{name}.h")
    with open(path, 'w') as f:
        f.write(f'/* Push buffer: {name} ({dwords} dwords, {len(data)} bytes) */\n')
        f.write(f'#define MENU_PB_{name.upper()}_DWORDS {dwords}\n\n')
        f.write(f'static const uint32_t menu_pb_{name}[] = {{\n')
        for i in range(0, len(data), 16):
            chunk = data[i:min(i+16, len(data))]
            vals = struct.unpack(f'<{len(chunk)//4}I', chunk)
            f.write('    ' + ', '.join(f'0x{v:08X}' for v in vals) + ',\n')
        f.write('};\n')

    print(f"  Saved: {path} ({dwords} dwords)")

    c.continue_execution()
    c.disconnect()
    print("Done!")

if __name__ == '__main__':
    main()
