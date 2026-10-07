# RECOMP BUG #8 (part 2) fix: make the x87 FPU stack GLOBAL in existing gen
# files (RE-APPLY after regen — or regen with the fixed translator.py, which
# now emits g_fp_stack/g_fp_top directly).
#
# The translator gave each function private `double _fp_stack[8]; int
# _fp_top;` locals, so ANY x87 value crossing a call boundary (fld+call
# helpers, float returns in ST0) read uninitialized garbage. Real x87 state
# is global. g_fp_stack/g_fp_top are defined in src/kernel/xbox_memory_layout.c
# and declared in src/game/recomp/recomp_types.h; fibers save/restore them.
import glob

total = 0
for f in glob.glob('src/game/recomp/gen/*.c'):
    s = open(f, encoding='utf-8', errors='ignore').read()
    o = s
    s = s.replace("    double _fp_stack[8];\n", "")
    s = s.replace("    int _fp_top = 0;\n", "")
    import re as _re
    s = _re.sub(r"(?<![gA-Za-z0-9_])_fp_stack", "g_fp_stack", s)
    s = _re.sub(r"(?<![gA-Za-z0-9_])_fp_top", "g_fp_top", s)
    if s != o:
        open(f, 'w', encoding='utf-8').write(s)
        total += 1
print("gen files converted to global FPU stack:", total)
