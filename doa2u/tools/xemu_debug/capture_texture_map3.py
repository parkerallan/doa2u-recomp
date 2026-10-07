"""
Match NV2A texture VRAM offsets to Global.txd entries by reading
Xbox D3D8 texture object internals.

Xbox D3D8 texture objects store the VRAM address at a known offset.
We can scan all loaded textures to build the mapping.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]
def hex32(v): return f"0x{v:08X}"

# Known VRAM offsets from push buffer capture
VRAM_OFFSETS = [
    0x021C4100, 0x02EC0400, 0x03C1ED00, 0x03C24700, 0x03C24B80,
    0x03C7BE00, 0x03C95700, 0x03CA1A80, 0x03CB9200, 0x03D57000,
]

# NV2A format decode: bits 20-23 = log2(width), bits 24-27 = log2(height)
def decode_format(fmt):
    color = (fmt >> 8) & 0xFF
    log2w = (fmt >> 20) & 0xF
    log2h = (fmt >> 24) & 0xF
    w = 1 << log2w if log2w else 0
    h = 1 << log2h if log2h else 0
    fmt_names = {0x06: 'A8R8G8B8', 0x07: 'X8R8G8B8', 0x0B: 'A1R5G5B5',
                 0x0C: 'DXT1', 0x0E: 'DXT3', 0x0F: 'DXT5', 0x12: 'A8R8G8B8',
                 0x1A: 'A8L8', 0x29: 'A8'}
    return w, h, fmt_names.get(color, f'0x{color:02X}')

def main():
    client = GDBClient('localhost', 1234)
    client.connect()
    print("Halting CPU...")
    client.halt()
    time.sleep(0.3)

    # Known format register values from capture
    fmt_map = {
        0x021C4100: 0x08810F29,
        0x02EC0400: 0x00011229,
        0x03C1ED00: 0x06810B29,
        0x03C24700: 0x05610C29,
        0x03C24B80: 0x07710F29,
        0x03C7BE00: 0x06710F29,
        0x03C95700: 0x04510F29,
        0x03CA1A80: 0x05510F29,
        0x03CB9200: 0x04410C29,
        0x03D57000: 0x05510F29,
    }

    print("\n=== Decoded texture dimensions ===")
    for off in sorted(VRAM_OFFSETS):
        fmt = fmt_map.get(off, 0)
        w, h, name = decode_format(fmt)
        print(f"  {hex32(off)}: {w}x{h} {name}")

    # Now scan the RW texture dictionary in game memory
    # RW stores loaded textures in a hash table / linked list
    # The game's Global.txd creates RwTexture objects during txd_load
    # Each RwTexture has: name, raster -> platform data -> VRAM address

    # Approach: scan VRAM around 0x03C00000-0x03D60000 for texture headers
    # Xbox D3D8 textures are allocated contiguously in VRAM

    # Alternative: read the RW texture dictionary directly
    # RW global texture dictionary is typically at a known address
    # In xemu session 33, we found the game manager at 0x3F9040

    # Let's try reading the RwTexDictionary that Global.txd loaded into
    # The txd is likely stored at a RW global pointer

    # For now, let's match by dimensions:
    # From our Global.txd dump:
    #   B3Logo: 256x64 fmt=0x0B (A1R5G5B5) => matches 0x03C1ED00 (256x128 A1R5G5B5 close!)
    #   ramp: 256x512 fmt=0x0F (DXT5) => matches 0x03C24B80 (128x256 DXT5) or 0x021C4100 (256x256 DXT5)

    # Actually, let me just read what's at the RW texture addresses
    # RW stores the current texture dictionary at a global pointer
    # Common RW address: check around 0x759xxx area (RW globals)

    print("\n=== Searching for RW texture dictionary ===")
    # RW texture dictionary find function uses a global hash table
    # The hash table pointer is typically at _rwTexDictList or similar
    # Let's check common RW global areas

    # Instead, let's match by dimension + format more precisely
    print("\n=== Matching by dimension + format ===")
    # Our Global.txd textures with their formats:
    txd_entries = [
        ("16_curve", 16, 16, 0x0F),
        ("16_curveb", 16, 16, 0x0F),
        ("A_Button", 32, 32, 0x0F),
        ("Aftertouch", 64, 64, 0x0F),
        ("Arrow", 64, 32, 0x0F),
        ("B3Logo", 256, 64, 0x0B),
        ("B_Button", 32, 32, 0x0F),
        ("Bad", 64, 64, 0x0F),
        ("bg", 64, 32, 0x0C),
        ("big_curve", 128, 128, 0x0F),
        ("blobbyshadow", 128, 128, 0x0F),
        ("BoostBits", 64, 256, 0x0F),
        ("check", 256, 128, 0x0F),
        ("CrackedGlass", 256, 128, 0x0F),
        ("EATrax", 256, 128, 0x0F),
        ("FE", 32, 32, 0x0F),
        ("finish", 256, 128, 0x0F),
        ("ramp", 256, 512, 0x0F),
        ("SmashedGlass", 256, 128, 0x0F),
        ("VehicleUnderside", 512, 256, 0x0C),
        ("WaterFresnel", 256, 256, 0x0F),
    ]

    nv2a_textures = []
    for off in sorted(VRAM_OFFSETS):
        fmt = fmt_map.get(off, 0)
        w, h, fname = decode_format(fmt)
        nv2a_textures.append((off, w, h, fname, (fmt >> 8) & 0xFF))

    for noff, nw, nh, nfname, nfmt in nv2a_textures:
        matches = []
        for name, tw, th, tfmt in txd_entries:
            if tw == nw and th == nh and tfmt == nfmt:
                matches.append(name)
        match_str = ', '.join(matches) if matches else 'NO MATCH'
        print(f"  {hex32(noff)} {nw:4d}x{nh:<4d} {nfname:10s} => {match_str}")

    # Let's also dump ALL texture names from Global.txd with sizes
    # Read the full list from the game's stderr output
    print("\n=== Need full TXD list for matching ===")
    print("Run the game with texture dump enabled to get all 189 entries")

    print("\nResuming CPU...")
    client.continue_execution()
    client.disconnect()

if __name__ == '__main__':
    main()
