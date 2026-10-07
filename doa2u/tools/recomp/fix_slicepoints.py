"""
Put a fiber slice check (RECOMP_SLICE_POINT) on every backward goto so polling loops
let the worker fibers run.
"""
import glob
import re

LABEL = re.compile(r"^loc_([0-9A-F]{8}): ;")
GOTO = re.compile(r"(?<!RECOMP_SLICE_POINT\(\); )goto loc_([0-9A-F]{8});")
total = 0
for path in glob.glob("src/game/recomp/gen/recomp_*.c"):
    if path.endswith("recomp_dispatch.c"):
        continue
    lines = open(path, encoding="utf-8", errors="surrogateescape").read().split("\n")
    cur = None
    changed = 0
    for i, line in enumerate(lines):
        s = line.strip()
        m = LABEL.match(s)
        if m:
            cur = int(m.group(1), 16)
            continue
        if s.startswith("void ") and s.endswith("(void)"):
            cur = None
            continue
        if cur is None or "goto loc_" not in line or "_jt ==" in line:
            continue

        def rep(g):
            global total
            nonlocal_changed[0] += 1
            return "{ RECOMP_SLICE_POINT(); goto loc_%s; }" % g.group(1)

        nonlocal_changed = [0]
        new = GOTO.sub(lambda g: rep(g) if int(g.group(1), 16) <= cur else g.group(0), line)
        if new != line:
            lines[i] = new
            changed += nonlocal_changed[0]
    if changed:
        open(path, "w", encoding="utf-8", errors="surrogateescape").write("\n".join(lines))
        total += changed
print("loop back-edges with a slice point:", total)
