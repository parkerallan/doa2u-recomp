"""Post-process freshly generated code. Run from the project root after
`py -3 -m tools.recomp <xbe> --all --split 1000`:

    py -3 -m tools.recomp.postprocess

Steps, in order (each is idempotent):
  1. fix_fallthroughs      restore fall-throughs into split-off fragments
  2. fix_cond_tailcall_ebp sync g_seh_ebp on conditional tail-calls
  3. fix_entry_flags       branches at a split function's entry that read the
                           predecessor's flags (re-evaluate its cmp/test)
  4. fix_ftol_inline       inline CRT _ftol2 (0x003354E0)
     fix_selfspins         XDK hardware busy-waits on memory forced through
     fix_slicepoints       fiber slice check on every loop back-edge
  5. overrides             every sub_XXXXXXXX defined in recomp_manual.c has its
                           generated body renamed sub_XXXXXXXX_gen, so the manual
                           version is the one the dispatch table and callers bind
"""
import glob
import re
import runpy
import sys

for tool in ("fix_fallthroughs", "fix_cond_tailcall_ebp", "fix_entry_flags", "fix_ftol_inline",
             "fix_selfspins", "fix_slicepoints"):
    print(f"--- {tool}")
    sys.argv = [tool]
    runpy.run_path(f"tools/recomp/{tool}.py", run_name="__main__")

print("--- overrides")
manual = open("src/game/recomp/recomp_manual.c", encoding="utf-8", errors="ignore").read()
overridden = set(re.findall(r"^void (sub_[0-9A-F]{8})\(void\)", manual, re.M))
# wrapper macros that define sub_X around sub_X_gen
overridden |= set(re.findall(r"(?:ABI_CHECK|CALL_LOG)\((sub_[0-9A-F]{8})\)", manual))
renamed = 0
for path in glob.glob("src/game/recomp/gen/recomp_*.c"):
    if path.endswith("recomp_dispatch.c"):
        continue
    text = open(path, encoding="utf-8", errors="surrogateescape").read()
    def ren(m):
        # rename to _gen when overridden, back to the plain name when the
        # override has since been removed from recomp_manual.c
        global renamed
        name, gen = m.group(1), bool(m.group(2))
        if (name in overridden) != gen:
            renamed += 1
            return f"void {name}{'_gen' if name in overridden else ''}(void)\n{{"
        return m.group(0)
    new = re.sub(r"^void (sub_[0-9A-F]{8})(_gen)?\(void\)\n\{", ren, text, flags=re.M)
    if new != text:
        open(path, "w", encoding="utf-8", errors="surrogateescape").write(new)
print(f"overridden in recomp_manual.c: {len(overridden)}, gen bodies renamed this run: {renamed}")
