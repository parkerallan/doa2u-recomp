"""DOA2U gen fix: force hardware busy-wait self-spins through.

The XDK D3D/DSOUND/XPP libraries poll GPU/APU registers with single-instruction
self-loops (`loc_X: if (MEM...) goto loc_X;`). Our port has no live hardware
behind most of those registers (VEH zero-pages them), so the value never
changes and the loop hangs the game (e.g. DirectSoundDoWork's DSP-FIFO drain
at loc_001C92D1). On the host the condition these gates model ("hardware
ready / FIFO drained") is always satisfiable, so drop the loops.

Only applied to loops in the XDK library sections (DOA2U: D3D through XPP,
0x344180-0x3C14C0) -- game .text keeps its loops. Run by postprocess.py.
(DOA2U: DirectSound's DownloadEffectsImage posts each command to the GP DSP
mailbox and spins until the DSP clears it; nothing runs that DSP here.)
"""
import re, glob, os

total = 0
XDK_LO, XDK_HI = 0x344180, 0x3C14C0
for f in glob.glob('src/game/recomp/gen/recomp_*.c'):
    lines = open(f, encoding='utf-8', errors='ignore').read().split('\n')
    changed = 0
    for i in range(len(lines) - 2):
        m = re.match(r'loc_([0-9A-Fa-f]{8}): ;', lines[i].strip())
        if not m:
            continue
        lab = m.group(1)
        in_xdk = XDK_LO <= int(lab, 16) < XDK_HI
        for j in (i + 1, i + 2, i + 3):
            if j >= len(lines): break
            s = lines[j].strip()
            if not s or (s.startswith('/*') and s.endswith('*/')): continue
            m2 = re.match(r'if \((.+)\) goto loc_' + lab + r'; (/\*.*\*/)?', s)
            # memory polls only in the XDK; a register-only self-loop can never
            # exit, so force it anywhere (DSOUND's `test cl,cl; jne $`)
            if m2 and (('MEM' in m2.group(1) and in_xdk) or 'MEM' not in m2.group(1)):
                indent = lines[j][:len(lines[j]) - len(lines[j].lstrip())]
                lines[j] = (indent + '/* hw busy-wait forced through (was: if ('
                            + m2.group(1)[:70] + ') goto loc_' + lab + ') */')
                changed += 1
            break
    if changed:
        open(f, 'w', encoding='utf-8').write('\n'.join(lines))
        print(f"  {os.path.basename(f)}: {changed} spins removed")
        total += changed
print("total:", total)
