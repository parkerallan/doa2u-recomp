"""
Full regen of src/game/recomp/gen: seed, translate until nothing seedable is missing, postprocess.
usage: py -3 -m tools.recomp.regen <xbe>
"""
import subprocess
import sys

xbe = sys.argv[1]
py = sys.executable


def run(*args):
    r = subprocess.run([py, "-m"] + list(args), capture_output=True, text=True, encoding="utf-8")
    if r.returncode:
        sys.exit(f"{' '.join(args)} failed:\n{r.stdout}\n{r.stderr}")
    return r.stdout


for tool, arg in (("tools.recomp.seed_data_pointers", xbe),
                  ("tools.recomp.seed_immediates", xbe),
                  ("tools.recomp.seed_symbol_cache", "tools/recomp/doa2u_cxbx_symbols.ini")):
    print(run(tool, arg, "seed_list.tmp").strip())
    print(run("tools.recomp.seed_missing_functions", "seed_list.tmp").strip())

for i in range(10):
    run("tools.recomp", xbe, "--all", "--split", "1000")
    out = run("tools.recomp.find_missing", "seed_list.tmp")
    print(f"pass {i + 1}: {out.splitlines()[0]}")
    if "seedable=0" in out:
        break
    print(run("tools.recomp.seed_missing_functions", "seed_list.tmp").strip())

print(run("tools.recomp.postprocess").strip().splitlines()[-1])
