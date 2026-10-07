"""DOA3 gen fix: conditional tail-calls (jcc -> function entry) must sync g_seh_ebp.

The translator emits `g_seh_ebp = ebp; sub_X(); return; /* tail jmp */` for
unconditional tail-jumps but `if (...) { sub_X(); return; }` for conditional
ones -- missing the sync. Callees marked "fpo_leaf: inherit caller's frame"
read `ebp = g_seh_ebp` at entry, so they inherit a STALE frame pointer and
read/write locals on the wrong stack frame (this broke XAPI CreateFileA's
OBJECT_ATTRIBUTES -> loadfile.afs never opened).

Only functions that declare a `uint32_t ebp` local are touched (others never
change ebp, so g_seh_ebp is already current there). Re-apply after regen.
"""
import re, glob

CALL = re.compile(r'\) \{ (sub_[0-9A-Fa-f]{8}(?:_gen)?\(\); return; \})')
DECL = re.compile(r'^\s+uint32_t ebp(?: = [^;]+)?;')
FUNC = re.compile(r'^void (sub_[0-9A-Fa-f]{8}(?:_gen)?|\w+)\(void\)$')

total = 0
for path in glob.glob('src/game/recomp/gen/*.c'):
    lines = open(path, encoding='utf-8', errors='ignore').read().split('\n')
    out = []
    has_ebp = False
    changed = 0
    for line in lines:
        if FUNC.match(line):
            has_ebp = False
        elif DECL.match(line):
            has_ebp = True
        elif has_ebp and ') { sub_' in line and '(); return; }' in line and 'g_seh_ebp' not in line:
            new = CALL.sub(r') { g_seh_ebp = ebp; \1', line)
            if new != line:
                line = new
                changed += 1
        out.append(line)
    if changed:
        open(path, 'w', encoding='utf-8').write('\n'.join(out))
        print(f"  {path}: {changed}")
        total += changed
print("total conditional tail-calls synced:", total)
