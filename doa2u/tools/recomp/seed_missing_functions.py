#!/usr/bin/env python3
"""
Seed missing functions into tools/disasm/output/functions.json.

The function detector under-detects call targets (functions reachable only via
`call` whose entry it didn't promote). Those become thousands of unresolved
`sub_*` symbols at link time. This tool reads a list of unresolved symbols and
appends each as a `link_seed` function whose end snaps to the next known
boundary, so `tools.recomp` emits a real body for it.

Workflow (run from the doa3/ root):
  1. Build once; capture unresolved symbols:
       cmake --build build --config Release 2>&1 \
         | grep -oE "unresolved external symbol sub_[0-9A-Fa-f]+" \
         | sed 's/unresolved external symbol //' | sort -u > unresolved.txt
  2. py -3 -m tools.recomp.seed_missing_functions unresolved.txt
  3. py -3 -m tools.func_id  ../doa3gamefiles/default.xbe
  4. py -3 -m tools.recomp   ../doa3gamefiles/default.xbe --all --split 1000
  5. cmake -S . -B build && cmake --build build --config Release

Re-apply after any fresh `tools.disasm` run (which overwrites functions.json).
"""
import json
import bisect
import os
import sys

from . import config

FUNCTIONS_PATH = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
    "disasm", "output", "functions.json")


def section_of(va):
    for name, sva, size, _raw in config.SECTIONS:
        if sva <= va < sva + size:
            return name
    return "?"


def main():
    if len(sys.argv) < 2:
        print("usage: python -m tools.recomp.seed_missing_functions <unresolved.txt>",
              file=sys.stderr)
        sys.exit(1)

    funcs = json.load(open(FUNCTIONS_PATH))
    existing_starts = {int(f["start"], 16) for f in funcs}

    bps = set()
    for f in funcs:
        bps.add(int(f["start"], 16))
        bps.add(int(f["end"], 16))
    for _name, va, size, _raw in config.SECTIONS:
        bps.add(va)
        bps.add(va + size)

    unres = sorted({
        int(line.strip().replace("sub_", ""), 16)
        for line in open(sys.argv[1]) if line.strip()
    })
    for a in unres:
        bps.add(a)
    bp = sorted(bps)

    added = skipped = 0
    for a in unres:
        if a in existing_starts:
            skipped += 1
            continue
        i = bisect.bisect_right(bp, a)
        end = bp[i] if i < len(bp) else a + 16
        sec = section_of(a)
        for _name, sva, size, _raw in config.SECTIONS:
            if _name == sec:
                end = min(end, sva + size)
                break
        if end <= a:
            end = a + 1
        funcs.append({
            "start": f"0x{a:08X}", "end": f"0x{end:08X}", "size": end - a,
            "name": f"sub_{a:08X}", "section": sec, "confidence": 0.5,
            "detection_method": "link_seed", "num_instructions": 0,
            "has_prologue": False, "calls_to": [], "called_by": [],
        })
        added += 1

    funcs.sort(key=lambda f: int(f["start"], 16))
    json.dump(funcs, open(FUNCTIONS_PATH, "w"), indent=1)   # keep the file's formatting
    print(f"added={added} skipped={skipped} total_now={len(funcs)}")


if __name__ == "__main__":
    main()
