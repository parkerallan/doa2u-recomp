import re, glob, os
# addr -> emitted function name (prefer base name; gen may have _gen suffix)
addr2name = {}
for f in glob.glob('src/game/recomp/gen/*.c'):
    for line in open(f, encoding='utf-8', errors='ignore'):
        m = re.match(r'void (sub_([0-9A-Fa-f]{8}))(_gen)?\(void\)', line)
        if m:
            a=int(m.group(2),16)
            # base name (override or gen) is callable
            addr2name[a]=m.group(1)

# Game .text only (DOA2U: 0x11000-0x344164) plus D3DX. Found that
# blanket-restoring every XDK fragment broke boot (some XDK 'ends' are not
# real fall-throughs), so XDK fragments are added one by one to KEEP_XDK
# once proven.
LO, HI = 0x11000, 0x344164
KEEP_XDK = set()
# DOA2U: every code section (CMiniport_InitHardware falls into a shared epilogue
# fragment); FIX_GAME_ONLY=1 restores the old game-.text-only scope.
ALL_CODE = os.environ.get('FIX_GAME_ONLY') is None
D3DX_LO, D3DX_HI = 0x357D00, 0x3611F0
fixed = 0
for f in glob.glob('src/game/recomp/gen/*.c'):
    lines = open(f, encoding='utf-8', errors='ignore').read().split('\n')
    out=[]; cur=None; end=None; has_ebp=False; body=[]; start_idx=None
    pend=None
    i=0
    while i < len(lines):
        line=lines[i]
        mo=re.search(r'Original: 0x([0-9A-Fa-f]+) - 0x([0-9A-Fa-f]+)', line)
        if mo: pend=int(mo.group(2),16)
        m=re.match(r'void sub_([0-9A-Fa-f]{8})(_gen)?\(void\)', line)
        if m:
            cur=int(m.group(1),16); end=pend; has_ebp=False; body=[]
            out.append(line); i+=1
            continue
        if cur is not None:
            if 'uint32_t ebp;' in line: has_ebp=True
            if line=='}':
                # decide fall-through
                last=''
                for b in reversed(body):
                    s=b.strip()
                    if not s or s.startswith('/*') or s.endswith(': ;') or s in ('{','};') or s.startswith('#') or s.startswith('loc_') or s.startswith('uint') or s.startswith('int '):
                        continue
                    last=s; break
                # A conditional tail-call (`if (...) { ...; return; }`) is a jcc:
                # the not-taken path still falls into the next function.
                term = (('return' in last and not last.startswith('if ')) or
                        last.startswith('goto ') or '__debugbreak' in last or last.endswith('break;'))
                if (not last or not term) and end in addr2name and (ALL_CODE or LO<=cur<HI or cur in KEEP_XDK or D3DX_LO<=cur<D3DX_HI):
                    tgt=addr2name[end]
                    if has_ebp:
                        ins='    g_seh_ebp = ebp; %s(); return; /* restored dropped fall-through to %s */' % (tgt,tgt)
                    else:
                        ins='    %s(); return; /* restored dropped fall-through to %s */' % (tgt,tgt)
                    if os.environ.get('FIX_DRYRUN'): print('%s: sub_%08X -> %s | %s' % (os.path.basename(f), cur, tgt, last[:100]))
                    else: out.append(ins)
                    fixed+=1
                out.append(line); cur=None; i+=1; continue
            body.append(line)
        out.append(line); i+=1
    if not os.environ.get('FIX_DRYRUN'): open(f,'w',encoding='utf-8').write('\n'.join(out))
print("CRI-range fall-throughs fixed:", fixed)
