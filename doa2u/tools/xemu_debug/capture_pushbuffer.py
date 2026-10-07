"""
Capture NV2A push buffer contents from xemu during menu rendering.

The render context at 0x0035D6A0 contains push buffer DMA pointers.
From capture1: 0x81FC3000 and 0x821C3000 are the push buffer put/get.
Xbox physical memory at 0x8xxxxxxx = virtual address 0x8xxxxxxx.

We need to:
1. Find the push buffer base, put, get pointers
2. Read the push buffer content
3. Parse NV2A method/data pairs
4. Identify what D3D8 operations menus use
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]
def f32(data, offset=0):
    if offset + 4 > len(data): return 0.0
    return struct.unpack_from('<f', data, offset)[0]
def hex32(v): return f"0x{v:08X}"

# NV2A method names (subset for readability)
NV2A_METHODS = {
    0x0100: "NOP",
    0x0180: "SET_OBJECT",
    0x0184: "SET_CONTEXT_DMA_NOTIFIES",
    0x019C: "SET_CONTEXT_DMA_COLOR",
    0x01A0: "SET_CONTEXT_DMA_ZETA",
    0x01A4: "SET_SURFACE_CLIP_HORIZONTAL",
    0x01A8: "SET_SURFACE_CLIP_VERTICAL",
    0x01D0: "CLEAR_SURFACE",
    0x01D4: "SET_CLEAR_COLOR",  # actually CLEAR_RECT_HORIZONTAL
    0x01D8: "CLEAR_RECT_VERTICAL",
    0x0200: "SET_SURFACE_FORMAT",
    0x0204: "SET_SURFACE_PITCH",
    0x0208: "SET_SURFACE_COLOR_OFFSET",
    0x020C: "SET_SURFACE_ZETA_OFFSET",
    0x0300: "SET_BLEND_FUNC_SFACTOR",
    0x0304: "SET_BLEND_FUNC_DFACTOR",
    0x0308: "SET_BLEND_COLOR",
    0x030C: "SET_BLEND_EQUATION",
    0x0310: "SET_COLOR_MATERIAL",
    0x033C: "SET_DEPTH_FUNC",
    0x0340: "SET_DEPTH_MASK",
    0x0344: "SET_DEPTH_TEST_ENABLE",
    0x0348: "SET_STENCIL_TEST_ENABLE",
    0x034C: "SET_STENCIL_MASK",
    0x0350: "SET_STENCIL_FUNC",
    0x0354: "SET_STENCIL_FUNC_REF",
    0x0358: "SET_STENCIL_FUNC_MASK",
    0x035C: "SET_STENCIL_OP_FAIL",
    0x0360: "SET_STENCIL_OP_ZFAIL",
    0x0364: "SET_STENCIL_OP_ZPASS",
    0x0368: "SET_SHADE_MODE",
    0x03A0: "SET_COLOR_MASK",
    0x03B0: "SET_ALPHA_TEST_ENABLE",
    0x03B4: "SET_ALPHA_FUNC",
    0x03B8: "SET_ALPHA_REF",
    0x03D0: "SET_CULL_FACE_ENABLE",
    0x03D4: "SET_CULL_FACE",
    0x03D8: "SET_FRONT_FACE",
    0x0A20: "SET_VIEWPORT_OFFSET",  # 4 floats
    0x0A60: "SET_POINT_PARAMS_ENABLE",
    0x0AF0: "SET_VIEWPORT_SCALE",  # 4 floats
    0x0B00: "SET_TRANSFORM_PROGRAM_START",
    0x0B04: "SET_TRANSFORM_CONSTANT_LOAD",
    0x0B80: "SET_TRANSFORM_PROGRAM",  # up to 128 slots
    0x0E00: "SET_TRANSFORM_CONSTANT",  # 4 floats per constant
    0x1680: "SET_VERTEX_DATA_ARRAY_FORMAT",  # 16 attrs × 4 bytes
    0x1740: "SET_VERTEX_DATA_ARRAY_OFFSET",  # 16 attrs × 4 bytes
    0x17FC: "SET_BEGIN_END",
    0x1800: "INLINE_ARRAY_ELEMENTS",  # index buffer
    0x1818: "INLINE_ARRAY",  # vertex data (non-incrementing)
    0x1880: "SET_VERTEX4F",  # per-vertex, auto-incrementing 16 * 0x10
    0x1B00: "SET_TEXTURE0_FORMAT",
    0x1B04: "SET_TEXTURE0_ADDRESS",
    0x1B08: "SET_TEXTURE0_CONTROL0",
    0x1B0C: "SET_TEXTURE0_CONTROL1",
    0x1B10: "SET_TEXTURE0_FILTER",
    0x1B14: "SET_TEXTURE0_IMAGE_RECT",
    0x1B40: "SET_TEXTURE1_FORMAT",
    0x1D6C: "SET_COMBINER_FACTOR0",
    0x1D70: "SET_COMBINER_FACTOR1",
    0x1D80: "SET_COMBINER_ALPHA_ICW",
    0x1D88: "SET_COMBINER_SPECULAR_FOG_CW0",
    0x1D8C: "SET_COMBINER_SPECULAR_FOG_CW1",
    0x1D60: "SET_COMBINER_COLOR_ICW",
    0x1E40: "SET_COMBINER_COLOR_OCW",
    0x1E48: "SET_COMBINER_ALPHA_OCW",
    0x1E20: "SET_SHADER_STAGE_PROGRAM",
    0x1E70: "SET_COMBINER_CONTROL",
    0x1E94: "SET_SHADOW_ZSLOPE_THRESHOLD",
    0x1EA4: "SET_SPECULAR_PARAMS",
    0x0394: "SET_TRANSFORM_EXECUTION_MODE",
    0x0398: "SET_TRANSFORM_PROGRAM_CXT_WRITE_EN",
    0x039C: "SET_TRANSFORM_PROGRAM_LOAD",
    0x03E0: "SET_TEXTURE_MATRIX_ENABLE",  # 4 stages
    0x03F0: "SET_PROJECTION_MATRIX",  # next 16 floats
    0x0440: "SET_MODELVIEW0_MATRIX",  # next 16 floats
    0x0480: "SET_INVERSE_MODELVIEW0_MATRIX",
    0x04C0: "SET_COMPOSITE_MATRIX",
    0x1E60: "SET_SHADER_OTHER_STAGE_INPUT",
    0x0228: "SET_CONTROL0",
    0x17F8: "SET_VERTEX_DATA2S",  # short2 format
    0x1500: "SET_VERTEX_DATA4UB",  # packed byte4
    0x1518: "SET_VERTEX_DATA4F_M",  # per-attr float4
}

# Begin/End draw mode names
DRAW_MODES = {
    0: "END", 1: "POINTS", 2: "LINES", 3: "LINE_LOOP",
    4: "LINE_STRIP", 5: "TRIANGLES", 6: "TRIANGLE_STRIP",
    7: "TRIANGLE_FAN", 8: "QUADS", 9: "QUAD_STRIP", 10: "POLYGON"
}


def get_method_name(method):
    """Look up method name, handling ranges."""
    if method in NV2A_METHODS:
        return NV2A_METHODS[method]
    # Check for array methods
    if 0x1680 <= method < 0x16C0:
        attr = (method - 0x1680) // 4
        return f"SET_VERTEX_DATA_ARRAY_FORMAT[{attr}]"
    if 0x1740 <= method < 0x1780:
        attr = (method - 0x1740) // 4
        return f"SET_VERTEX_DATA_ARRAY_OFFSET[{attr}]"
    if 0x1B00 <= method < 0x1C00:
        tex = (method - 0x1B00) // 0x40
        sub = (method - 0x1B00) % 0x40
        return f"SET_TEXTURE{tex}_REG_{sub:02X}"
    if 0x0E00 <= method < 0x1000:
        idx = (method - 0x0E00) // 16
        comp = (method - 0x0E00) % 16 // 4
        return f"SET_TRANSFORM_CONSTANT[{idx}].{['x','y','z','w'][comp]}"
    if 0x0B80 <= method < 0x0C00:
        idx = (method - 0x0B80) // 4
        return f"SET_TRANSFORM_PROGRAM[{idx}]"
    if 0x03F0 <= method < 0x0440:
        idx = (method - 0x03F0) // 4
        return f"SET_PROJECTION_MATRIX[{idx}]"
    if 0x0440 <= method < 0x0480:
        idx = (method - 0x0440) // 4
        return f"SET_MODELVIEW0_MATRIX[{idx}]"
    return f"UNKNOWN_0x{method:04X}"


def parse_pushbuffer(data, base_addr, max_dwords=4096):
    """Parse NV2A push buffer commands."""
    methods = []
    pos = 0
    dword_count = len(data) // 4

    while pos < min(dword_count, max_dwords):
        header = u32(data, pos * 4)
        if header == 0:
            pos += 1
            continue

        # Decode header
        if (header & 0xE0030003) == 0:
            # Increasing method
            count = (header >> 18) & 0x7FF
            subchannel = (header >> 13) & 7
            method = header & 0x1FFC

            if count == 0 or pos + 1 + count > dword_count:
                break

            for i in range(count):
                param = u32(data, (pos + 1 + i) * 4)
                m = method + i * 4
                name = get_method_name(m)
                methods.append({
                    'addr': base_addr + (pos + 1 + i) * 4,
                    'method': m,
                    'param': param,
                    'name': name,
                    'subchannel': subchannel,
                    'type': 'INC',
                })
            pos += 1 + count

        elif (header & 0xE0030003) == 0x40000000:
            # Non-increasing method
            count = (header >> 18) & 0x7FF
            subchannel = (header >> 13) & 7
            method = header & 0x1FFC

            if count == 0 or pos + 1 + count > dword_count:
                break

            for i in range(count):
                param = u32(data, (pos + 1 + i) * 4)
                name = get_method_name(method)
                methods.append({
                    'addr': base_addr + (pos + 1 + i) * 4,
                    'method': method,
                    'param': param,
                    'name': name,
                    'subchannel': subchannel,
                    'type': 'NONINC',
                })
            pos += 1 + count

        elif (header & 3) == 2:
            # Old-style jump
            pos += 1
        else:
            # Unknown or end
            pos += 1
            if pos > 10 and all(u32(data, j*4) == 0 for j in range(pos, min(pos+4, dword_count))):
                break

    return methods


def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    print("Halting CPU...")
    client.halt()
    time.sleep(0.3)

    # ── Read PFIFO registers to find push buffer location ──
    print("\n=== PFIFO Registers ===")
    # NV_PFIFO base is 0xFD002000
    # Key registers:
    # PFIFO_CACHE1_DMA_PUT  = 0x40
    # PFIFO_CACHE1_DMA_GET  = 0x44
    # PFIFO_CACHE1_DMA_INSTANCE = 0x50 (DMA context object)
    pfifo_base = 0xFD002000
    for name, off in [
        ("INTR_0", 0x100), ("INTR_EN_0", 0x140),
        ("CACHE1_PUT", 0x1210), ("CACHE1_GET", 0x1270),
        ("CACHE1_DMA_PUT", 0x1240), ("CACHE1_DMA_GET", 0x1244),
        ("CACHE1_DMA_INSTANCE", 0x122C),
        ("CACHE1_DMA_CTL", 0x1228),
        ("CACHE1_DMA_STATE", 0x1230),
        ("CACHE1_DMA_FETCH", 0x1234),
        ("CACHE1_ENGINE", 0x1280),
        ("CACHE1_PUSH0", 0x1200), ("CACHE1_PUSH1", 0x1204),
    ]:
        data = client.read_memory(pfifo_base + off, 4)
        val = u32(data)
        print(f"  PFIFO+{off:04X} ({name}): {hex32(val)}")

    # ── Read the render context at 0x35D6A0 more carefully ──
    print("\n=== Render Context (0x0035D6A0) - First 0x50 bytes ===")
    rc = client.read_memory(0x0035D6A0, 0x50)
    for off in range(0, 0x50, 4):
        val = u32(rc, off)
        fval = f32(rc, off)
        print(f"  +{off:03X}: {hex32(val)}  (float: {fval:.4f})")

    # The render context +0x24 = 0x81FC3000, +0x28 = 0x821C3000
    # These look like DMA push buffer BASE and LIMIT
    pb_base = u32(rc, 0x24)  # 0x81FC3000
    pb_limit = u32(rc, 0x28)  # 0x821C3000
    pb_pos = u32(rc, 0x2C)    # current position offset?
    print(f"\n  Push buffer base:  {hex32(pb_base)}")
    print(f"  Push buffer limit: {hex32(pb_limit)}")
    print(f"  Push buffer pos:   {hex32(pb_pos)}")

    # Also check PGRAPH DMA_PUT/GET
    print("\n=== PGRAPH Registers ===")
    pgraph_base = 0xFD400000
    for name, off in [
        ("INTR", 0x100), ("CTX_SWITCH1", 0x14C),
        ("DMA_PUT", 0x640), ("DMA_GET", 0x644),
        ("REF", 0x050), ("STATUS", 0x700),
    ]:
        data = client.read_memory(pgraph_base + off, 4)
        val = u32(data)
        print(f"  PGRAPH+{off:04X} ({name}): {hex32(val)}")

    # ── Read push buffer content ──
    # On Xbox, 0x80000000 = physical memory base
    # So 0x81FC3000 = phys addr 0x01FC3000
    # xemu GDB stub maps virtual memory including 0x80000000+
    print(f"\n=== Push Buffer Content ===")
    print(f"  Reading from {hex32(pb_base)}...")

    # Read 16KB of push buffer from base
    pb_size = 0x4000
    try:
        pb_data = client.read_memory(pb_base, pb_size)
        nonzero = sum(1 for i in range(0, pb_size, 4) if u32(pb_data, i) != 0)
        print(f"  Read {pb_size} bytes, {nonzero} non-zero dwords")

        if nonzero > 0:
            # Hex dump first 0x100 bytes
            print(f"\n  First 0x100 bytes:")
            for off in range(0, min(0x100, pb_size), 16):
                hx = ' '.join(f'{pb_data[off+j]:02X}' for j in range(16))
                print(f"    {pb_base+off:08X}: {hx}")

            # Parse push buffer
            print(f"\n  Parsed methods:")
            methods = parse_pushbuffer(pb_data, pb_base, max_dwords=2048)
            print(f"  Found {len(methods)} method calls")

            # Print unique methods
            unique = {}
            for m in methods:
                key = m['name']
                if key not in unique:
                    unique[key] = []
                unique[key].append(m)

            print(f"\n  Unique methods ({len(unique)}):")
            for name in sorted(unique.keys()):
                entries = unique[name]
                first = entries[0]
                if len(entries) <= 3:
                    vals = ', '.join(hex32(e['param']) for e in entries)
                    print(f"    {name}: {vals}")
                else:
                    print(f"    {name}: {len(entries)} calls (first={hex32(first['param'])})")

            # Print full method list (first 200)
            print(f"\n  Full method sequence (first 200):")
            for i, m in enumerate(methods[:200]):
                param = m['param']
                extra = ""
                if 'BEGIN_END' in m['name']:
                    extra = f" [{DRAW_MODES.get(param, '?')}]"
                elif 'VIEWPORT' in m['name'] or 'MATRIX' in m['name']:
                    extra = f" (float: {f32(struct.pack('<I', param)):.4f})"
                elif 'CLEAR_SURFACE' in m['name']:
                    flags = []
                    if param & 0x01: flags.append('COLOR')
                    if param & 0x02: flags.append('DEPTH')
                    if param & 0x04: flags.append('STENCIL')
                    extra = f" [{'+'.join(flags)}]"
                print(f"    [{i:3d}] {m['type']:6s} {m['name']:40s} = {hex32(param)}{extra}")

    except Exception as e:
        print(f"  ERROR reading push buffer: {e}")
        import traceback; traceback.print_exc()

    # Also try reading from the PFIFO DMA target
    print(f"\n=== Alternative: Read from DMA_PUT area ===")
    pfifo_put_data = client.read_memory(0xFD002000 + 0x1240, 4)
    pfifo_get_data = client.read_memory(0xFD002000 + 0x1244, 4)
    dma_put = u32(pfifo_put_data)
    dma_get = u32(pfifo_get_data)
    print(f"  DMA_PUT: {hex32(dma_put)}")
    print(f"  DMA_GET: {hex32(dma_get)}")

    if dma_put > dma_get and dma_put < 0x200000:
        # These are offsets into the push buffer
        # The actual push buffer is at a physical address
        # Read DMA instance to find base
        dma_inst_data = client.read_memory(0xFD002000 + 0x122C, 4)
        dma_inst = u32(dma_inst_data)
        print(f"  DMA_INSTANCE: {hex32(dma_inst)}")

        # DMA object is in RAMIN at offset = dma_inst * 16
        # RAMIN base is at PRAMIN = 0xFD700000
        ramin_off = dma_inst * 16
        ramin_data = client.read_memory(0xFD700000 + ramin_off, 16)
        dma_class = u32(ramin_data, 0)
        dma_limit = u32(ramin_data, 4)
        dma_base = u32(ramin_data, 8)
        print(f"  DMA Object at RAMIN+{hex32(ramin_off)}:")
        print(f"    class: {hex32(dma_class)}")
        print(f"    limit: {hex32(dma_limit)}")
        print(f"    base:  {hex32(dma_base)}")

        # Read push buffer from base + get offset
        if dma_base < 0x10000000:
            pb_va = 0x80000000 + dma_base
            print(f"\n  Push buffer VA: {hex32(pb_va)} + GET offset {hex32(dma_get)}")
            recent = client.read_memory(pb_va + dma_get, min(0x1000, dma_put - dma_get + 0x100))
            print(f"  Read {len(recent)} bytes from GET to PUT+0x100")

            methods2 = parse_pushbuffer(recent, pb_va + dma_get, max_dwords=1024)
            print(f"  Parsed {len(methods2)} methods from recent commands")
            for i, m in enumerate(methods2[:100]):
                print(f"    [{i:3d}] {m['type']:6s} {m['name']:40s} = {hex32(m['param'])}")

    print("\nResuming CPU...")
    client.continue_execution()
    client.disconnect()

import struct
if __name__ == '__main__':
    main()
