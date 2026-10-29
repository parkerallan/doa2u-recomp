"""
Configuration constants for Dead or Alive 2 Ultimate disassembly tool.

Defines address ranges, section boundaries, instruction classification,
and other constants used throughout the disassembler.

Values derived from: py -3 tools/xbe_parser/xbe_parser.py ../doa2ugamefiles/DOA2_261.xbe (title update, version 261)
  Title: DEAD OR ALIVE ULTIMATE (DOA2, Title ID 0x54430006), Retail, XDK 5849
"""

# ============================================================
# XBE Memory Layout
# ============================================================

XBE_BASE_ADDRESS = 0x00010000
XBE_IMAGE_SIZE = 0x01063F20  # 16.39 MB

# Entry point (retail, XOR-decoded from 0xA8D7A4D8)
ENTRY_POINT = 0x002BF373

# Kernel thunk table start (in .rdata)
KERNEL_THUNK_ADDR = 0x003C4EA0

# ============================================================
# Section Definitions
# ============================================================

# Executable code sections (name, va_start, va_size)
# These are the sections we'll disassemble.
EXECUTABLE_SECTIONS = [
    (".text",    0x00011000, 0x00336B54),
    ("D3D",      0x00347B60, 0x00013B6C),
    ("D3DX",     0x0035B6E0, 0x000094F0),
    ("XGRPH",    0x00364BE0, 0x0000214C),
    ("DSOUND",   0x00366D40, 0x0001DB44),
    ("XNET",     0x003848A0, 0x00012CB8),
    ("XONLINE",  0x00397560, 0x00021D1C),
    ("PSFD_I",   0x003B9280, 0x00000424),
    ("PSFD_B",   0x003B96C0, 0x000008C4),
    ("PSFD_P",   0x003B9FA0, 0x00000640),
    ("PSFD00",   0x003BA5E0, 0x00001768),
    ("XPP",      0x003BBD60, 0x0000912C),
    ("DOLBY",    0x010673A0, 0x00007180),
]

# Data sections
DATA_SECTIONS = [
    (".rdata",    0x003C4EA0, 0x000D8660),
    (".data",     0x0049D500, 0x00BC169C),
    ("zressect",  0x0105EBA0, 0x00008800),
    (".data1",    0x0106E520, 0x000000E0),
    ("XON_RD",    0x0106E600, 0x00001710),
    ("$$XTIMAGE", 0x0106FD20, 0x00002800),
]

# All sections by name for quick lookup
ALL_SECTIONS = {
    s[0]: {"va": s[1], "size": s[2]}
    for s in EXECUTABLE_SECTIONS + DATA_SECTIONS
}

# ============================================================
# Instruction Classification
# ============================================================

# x86 control flow instructions (mnemonic sets)
CALL_MNEMONICS = {"call"}
RET_MNEMONICS = {"ret", "retn", "retf"}
JMP_MNEMONICS = {"jmp"}
COND_JMP_MNEMONICS = {
    "jo", "jno", "jb", "jnb", "jnae", "jae", "jc", "jnc",
    "jz", "je", "jnz", "jne", "jbe", "jna", "ja", "jnbe",
    "js", "jns", "jp", "jpe", "jnp", "jpo",
    "jl", "jnge", "jge", "jnl", "jle", "jng", "jg", "jnle",
    "jcxz", "jecxz",
    "loop", "loope", "loopz", "loopne", "loopnz",
}
BRANCH_MNEMONICS = JMP_MNEMONICS | COND_JMP_MNEMONICS

# NOP-like instructions
NOP_MNEMONICS = {"nop"}

# Instructions that terminate a basic block
TERMINATOR_MNEMONICS = RET_MNEMONICS | JMP_MNEMONICS | COND_JMP_MNEMONICS

# ============================================================
# Function Detection
# ============================================================

# Standard MSVC x86 function prologue patterns (byte sequences)
# push ebp; mov ebp, esp
PROLOGUE_PUSH_EBP_MOV = bytes([0x55, 0x8B, 0xEC])
# push ebp; mov ebp, esp (with rex/other encoding)
PROLOGUE_PUSH_EBP_MOV_ALT = bytes([0x55, 0x89, 0xE5])

# CC padding byte (int 3 / debug break)
CC_PADDING = 0xCC

# Minimum CC padding run length to consider as function boundary
MIN_CC_RUN = 1

# ============================================================
# Function Detection Confidence Scores
# ============================================================

CONFIDENCE_KNOWN = 1.0       # Entry point, known addresses
CONFIDENCE_PROLOGUE = 0.95   # Standard prologue pattern
CONFIDENCE_CALL_TARGET = 0.90  # Destination of a call instruction
CONFIDENCE_CC_BOUNDARY = 0.85  # After CC padding run following ret

# ============================================================
# Disassembly Engine Settings
# ============================================================

# Chunk size for linear sweep (64 KB)
SWEEP_CHUNK_SIZE = 0x10000

# x86-32 mode
CS_MODE = 32

# ============================================================
# Output Settings
# ============================================================

# Default output directory (relative to tool root)
DEFAULT_OUTPUT_DIR = "tools/disasm/output"

# Maximum string length to extract from .rdata
MAX_STRING_LENGTH = 256

# Minimum string length to consider valid
MIN_STRING_LENGTH = 4

# ============================================================
# Cache Settings
# ============================================================

CACHE_FILENAME = ".disasm_cache.json"
CACHE_VERSION = 1
