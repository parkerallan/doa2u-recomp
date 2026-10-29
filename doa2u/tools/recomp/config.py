"""
Recompiler configuration - section mappings and constants.

Target: DEAD OR ALIVE ULTIMATE / DOA2 (Title ID 0x54430006), Retail, XDK 5849.
Values from: py -3 tools/xbe_parser/xbe_parser.py ../doa2ugamefiles/DOA2_261.xbe (title update, version 261)

NOTE: the size field below is the *raw* (on-disk) size so that
va_to_file_offset never points past the end of the XBE file. BSS tails
(virtual size > raw size, e.g. in .data) resolve to None and are treated
as zero-initialized, which matches Xbox load behavior.
"""

# Section virtual address -> file offset mappings
SECTIONS = [
    # (name, va_start, raw_size, raw_addr)
    (".text",     0x00011000, 0x00336B54, 0x00001000),
    ("D3D",       0x00347B60, 0x000102A0, 0x00338000),
    ("D3DX",      0x0035B6E0, 0x000094E8, 0x00349000),
    ("XGRPH",     0x00364BE0, 0x0000214C, 0x00353000),
    ("DSOUND",    0x00366D40, 0x0001D8DC, 0x00356000),
    ("XNET",      0x003848A0, 0x00012CB8, 0x00374000),
    ("XONLINE",   0x00397560, 0x00021D1C, 0x00387000),
    ("PSFD_I",    0x003B9280, 0x00000424, 0x003A9000),
    ("PSFD_B",    0x003B96C0, 0x000008C4, 0x003AA000),
    ("PSFD_P",    0x003B9FA0, 0x00000640, 0x003AB000),
    ("PSFD00",    0x003BA5E0, 0x00001768, 0x003AC000),
    ("XPP",       0x003BBD60, 0x0000912C, 0x003AE000),
    (".rdata",    0x003C4EA0, 0x000D8658, 0x003B8000),
    (".data",     0x0049D500, 0x00333638, 0x00491000),
    ("zressect",  0x0105EBA0, 0x00008800, 0x007C5000),
    ("DOLBY",     0x010673A0, 0x0000716C, 0x007CE000),
    (".data1",    0x0106E520, 0x000000B0, 0x007D6000),
    ("XON_RD",    0x0106E600, 0x00001710, 0x007D7000),
    ("$$XTIMAGE", 0x0106FD20, 0x00002800, 0x007D9000),
]

TEXT_VA_START = 0x00011000
TEXT_VA_END = 0x00347B54     # end of .text (D3D starts at 0x00347B60)
RDATA_VA_START = 0x003C4EA0
RDATA_VA_END = 0x0049D500    # start of .data
DATA_VA_START = 0x0049D500
DATA_VA_END = 0x01073F20     # base (0x10000) + image size (0x1063F20)
KERNEL_THUNK_ADDR = 0x003C4EA0
ENTRY_POINT = 0x002BF373

# CRT SEH helpers (XDK 5849 __SEH_prolog / __SEH_epilog). They move ebp for
# their caller; the lifter bridges it through g_seh_ebp.
SEH_PROLOG = 0x0033AA1C
SEH_EPILOG = 0x0033AA57
# C++ EH frame helper (__EH_prolog): also sets its caller's ebp, which
# operator new (0x338D81) then uses for `leave`.
EH_PROLOG = 0x0033BCE4


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
