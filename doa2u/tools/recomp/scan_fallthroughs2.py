"""Re-scan for dropped fall-throughs missed by fix_fallthroughs.py.

fix_fallthroughs.py classifies a fragment as already-terminated when its last
statement contains the substring 'int3' (meant to catch a trap instruction).
The recompiler emits a trap as `__debugbreak(); /* int3 */`, but the substring
also matches the `(int32_t)` cast that every sign-extending shift or multiply
produces -- so any fragment ending in one was silently skipped.

Byte-preserving: each file keeps its own line ending; only the inserted line is
new.  DRYRUN=1 to report without writing.
"""
import re, glob, os, sys

addr2name = {}
for f in glob.glob('src/game/recomp/gen/*.c'):
    for line in open(f, encoding='utf-8', errors='ignore'):
        m = re.match(r'void (sub_([0-9A-Fa-f]{8}))(_gen)?\(void\)', line)
        if m:
            addr2name[int(m.group(2), 16)] = m.group(1)

LO, HI = 0x11000, 0x1B0DE0
KEEP_XDK = {0x1B4611, 0x1C3FDD, 0x1B1388, 0x1B18C9, 0x1BB96C, 0x1B60A3, 0x1E6774}
D3DX_LO, D3DX_HI = 0x1C35C0, 0x1C64A0
DRY = os.environ.get('DRYRUN')

total = 0
for f in sorted(glob.glob('src/game/recomp/gen/*.c')):
    raw = open(f, 'rb').read()
    nl = '\r\n' if raw.count(b'\r\n') > raw.count(b'\n') // 2 else '\n'
    text = raw.decode('utf-8', 'surrogateescape')
    lines = text.split(nl)
    out = []; cur = None; end = None; has_ebp = False; body = []; pend = None
    n = 0
    for line in lines:
        mo = re.search(r'Original: 0x([0-9A-Fa-f]+) - 0x([0-9A-Fa-f]+)', line)
        if mo: pend = int(mo.group(2), 16)
        m = re.match(r'void sub_([0-9A-Fa-f]{8})(_gen)?\(void\)', line)
        if m:
            cur = int(m.group(1), 16); end = pend; has_ebp = False; body = []
            out.append(line); continue
        if cur is not None:
            if 'uint32_t ebp;' in line: has_ebp = True
            if line == '}':
                last = ''
                for b in reversed(body):
                    s = b.strip()
                    if (not s or s.startswith('/*') or s.startswith('*') or
                            s.endswith(': ;') or s in ('{', '};') or
                            s.startswith('#') or s.startswith('loc_') or
                            s.startswith('uint') or s.startswith('int ')):
                        continue
                    last = s; break
                term = (('return' in last and not last.startswith('if ')) or
                        last.startswith('goto ') or '__debugbreak' in last or
                        last.endswith('break;'))
                if ((not last or not term) and end in addr2name and
                        (LO <= cur < HI or cur in KEEP_XDK or D3DX_LO <= cur < D3DX_HI)):
                    tgt = addr2name[end]
                    if has_ebp:
                        ins = ('    g_seh_ebp = ebp; %s(); return; '
                               '/* DOA3: restored dropped fall-through to %s */' % (tgt, tgt))
                    else:
                        ins = ('    %s(); return; '
                               '/* DOA3: restored dropped fall-through to %s */' % (tgt, tgt))
                    if DRY:
                        print('%-18s sub_%08X -> %s | %s' %
                              (os.path.basename(f), cur, tgt, last[:70]))
                    else:
                        out.append(ins)
                    n += 1; total += 1
                out.append(line); cur = None; continue
            body.append(line)
        out.append(line)
    if n and not DRY:
        open(f, 'wb').write(nl.join(out).encode('utf-8', 'surrogateescape'))
        print('%s: %d' % (os.path.basename(f), n))
print('total:', total)
