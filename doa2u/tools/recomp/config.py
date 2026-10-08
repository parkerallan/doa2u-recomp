"""
Recompiler configuration - section mappings and constants.

Target: DEAD OR ALIVE ULTIMATE / DOA2 (Title ID 0x54430006), Retail, XDK 5849.
Values from: py -3 tools/xbe_parser/xbe_parser.py ../doa2ugamefiles/DOA2.xbe

NOTE: the size field below is the *raw* (on-disk) size so that
va_to_file_offset never points past the end of the XBE file. BSS tails
(virtual size > raw size, e.g. in .data) resolve to None and are treated
as zero-initialized, which matches Xbox load behavior.
"""

# Section virtual address -> file offset mappings
SECTIONS = [
    # (name, va_start, raw_size, raw_addr)
    (".text",     0x00011000, 0x00333164, 0x00001000),
    ("D3D",       0x00344180, 0x000102A0, 0x00335000),
    ("D3DX",      0x00357D00, 0x000094E8, 0x00346000),
    ("XGRPH",     0x00361200, 0x0000214C, 0x00350000),
    ("DSOUND",    0x00363360, 0x0001D8DC, 0x00353000),
    ("XNET",      0x00380EC0, 0x00012CB8, 0x00371000),
    ("XONLINE",   0x00393B80, 0x00021D1C, 0x00384000),
    ("PSFD_I",    0x003B58A0, 0x00000424, 0x003A6000),
    ("PSFD_B",    0x003B5CE0, 0x000008C4, 0x003A7000),
    ("PSFD_P",    0x003B65C0, 0x00000640, 0x003A8000),
    ("PSFD00",    0x003B6C00, 0x00001768, 0x003A9000),
    ("XPP",       0x003B8380, 0x0000912C, 0x003AB000),
    (".rdata",    0x003C14C0, 0x000D60B8, 0x003B5000),
    (".data",     0x00497580, 0x00333238, 0x0048C000),
    ("zressect",  0x01058760, 0x00008800, 0x007C0000),
    ("DOLBY",     0x01060F60, 0x0000716C, 0x007C9000),
    (".data1",    0x010680E0, 0x000000B0, 0x007D1000),
    ("XON_RD",    0x010681C0, 0x00001710, 0x007D2000),
    ("$$XTIMAGE", 0x010698E0, 0x00002800, 0x007D4000),
]

TEXT_VA_START = 0x00011000
TEXT_VA_END = 0x00344164     # end of .text (D3D starts at 0x00344180)
RDATA_VA_START = 0x003C14C0
RDATA_VA_END = 0x00497580    # start of .data
DATA_VA_START = 0x00497580
DATA_VA_END = 0x0106DAE0     # base (0x10000) + image size (0x105DAE0)
KERNEL_THUNK_ADDR = 0x003C14C0
ENTRY_POINT = 0x002BBB93

# CRT SEH helpers (XDK 5849 __SEH_prolog / __SEH_epilog). They move ebp for
# their caller; the lifter bridges it through g_seh_ebp.
SEH_PROLOG = 0x0033720C
SEH_EPILOG = 0x00337247
# C++ EH frame helper (__EH_prolog): also sets its caller's ebp, which
# operator new (0x335565) then uses for `leave`.
EH_PROLOG = 0x003384D4


def va_to_file_offset(va):
    """Convert virtual address to XBE file offset."""
    for _, sec_va, sec_size, sec_raw in SECTIONS:
        if sec_va <= va < sec_va + sec_size:
            return va - sec_va + sec_raw
    return None


def is_code_address(va):
    """Check if VA is in an executable section (.text or XDK library sections)."""
    if TEXT_VA_START <= va < TEXT_VA_END:
        return True
    # XDK library sections also contain executable code
    for name, sec_va, sec_size, _ in SECTIONS:
        if name in (".text", ".rdata", ".data", ".data1", "zressect", "XON_RD", "$$XTIMAGE"):
            continue  # skip data sections
        if sec_va <= va < sec_va + sec_size:
            return True
    return False


def is_data_address(va):
    """Check if VA is in .rdata or .data (including BSS)."""
    return RDATA_VA_START <= va <= DATA_VA_END
