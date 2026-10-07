"""
Compare memory snapshots between xemu and our recompiled version.

Takes a snapshot JSON from xemu and compares it against live memory
from our recompiled Burnout 3, highlighting differences that indicate
where our implementation diverges from the real game.

Usage:
    py -3 -m tools.xemu_debug.compare_snapshots <xemu_snapshot.json> <recomp_snapshot.json>
    py -3 -m tools.xemu_debug.compare_snapshots <xemu_snapshot.json> --live
"""

import sys
import json
import struct
import argparse


def load_snapshot(path: str) -> dict:
    with open(path) as f:
        return json.load(f)


def compare_field(name: str, xemu_val, recomp_val, tolerance: float = 0.01) -> str:
    """Compare a single field and return a human-readable diff."""
    if xemu_val is None or recomp_val is None:
        return f"  {name}: xemu={xemu_val} recomp={recomp_val} (one is missing)"

    if isinstance(xemu_val, float) and isinstance(recomp_val, float):
        if abs(xemu_val - recomp_val) < tolerance:
            return None  # Close enough
        return f"  {name}: xemu={xemu_val:.4f} recomp={recomp_val:.4f} (DIFF: {abs(xemu_val - recomp_val):.4f})"

    if xemu_val != recomp_val:
        if isinstance(xemu_val, int):
            return f"  {name}: xemu=0x{xemu_val:08X} recomp=0x{recomp_val:08X}"
        return f"  {name}: xemu={xemu_val} recomp={recomp_val}"

    return None  # Match


def compare_snapshots(xemu: dict, recomp: dict):
    """Compare two snapshots and print differences."""

    print("=" * 60)
    print("Memory Snapshot Comparison: xemu vs Recompiled")
    print("=" * 60)

    # Compare registers
    print("\n--- Registers ---")
    xemu_regs = xemu.get('registers', {})
    recomp_regs = recomp.get('registers', {})
    reg_diffs = 0
    for name in ['eax', 'ecx', 'edx', 'ebx', 'esp', 'ebp', 'esi', 'edi', 'eip']:
        diff = compare_field(name, xemu_regs.get(name), recomp_regs.get(name))
        if diff:
            print(diff)
            reg_diffs += 1
    if reg_diffs == 0:
        print("  All registers match!")

    # Compare regions
    total_diffs = 0
    total_matches = 0
    for region_name in xemu.get('regions', {}):
        if region_name not in recomp.get('regions', {}):
            print(f"\n--- {region_name}: NOT IN RECOMP SNAPSHOT ---")
            continue

        xemu_region = xemu['regions'][region_name]
        recomp_region = recomp['regions'][region_name]

        print(f"\n--- {region_name} (0x{xemu_region['addr']:08X}) ---")

        # Compare named fields
        xemu_fields = xemu_region.get('fields', {})
        recomp_fields = recomp_region.get('fields', {})

        all_fields = set(list(xemu_fields.keys()) + list(recomp_fields.keys()))
        region_diffs = 0

        for field_name in sorted(all_fields):
            diff = compare_field(field_name,
                               xemu_fields.get(field_name),
                               recomp_fields.get(field_name))
            if diff:
                print(diff)
                region_diffs += 1
            else:
                total_matches += 1

        # Compare raw data
        xemu_data = bytes.fromhex(xemu_region.get('data', ''))
        recomp_data = bytes.fromhex(recomp_region.get('data', ''))

        if xemu_data and recomp_data:
            min_len = min(len(xemu_data), len(recomp_data))
            byte_diffs = sum(1 for i in range(min_len) if xemu_data[i] != recomp_data[i])
            if byte_diffs > 0:
                pct = byte_diffs / min_len * 100
                print(f"  Raw data: {byte_diffs}/{min_len} bytes differ ({pct:.1f}%)")

                # Show first 5 differing offsets
                shown = 0
                for i in range(min_len):
                    if xemu_data[i] != recomp_data[i] and shown < 5:
                        print(f"    +0x{i:04X}: xemu=0x{xemu_data[i]:02X} recomp=0x{recomp_data[i]:02X}")
                        shown += 1
            else:
                print(f"  Raw data: {min_len} bytes match perfectly!")

        total_diffs += region_diffs

    print(f"\n{'=' * 60}")
    print(f"Summary: {total_matches} fields match, {total_diffs} fields differ")
    if total_diffs == 0:
        print("PERFECT MATCH! Our recompilation matches xemu.")
    elif total_diffs < 5:
        print("Very close! Only a few differences to investigate.")
    else:
        print("Significant differences found. Focus on the regions with most diffs.")


def main():
    parser = argparse.ArgumentParser(description='Compare xemu and recomp snapshots')
    parser.add_argument('xemu_snapshot', help='Path to xemu snapshot JSON')
    parser.add_argument('recomp_snapshot', nargs='?', help='Path to recomp snapshot JSON')
    parser.add_argument('--live', action='store_true',
                        help='Take live snapshot from running recompiled game (TODO)')
    args = parser.parse_args()

    xemu = load_snapshot(args.xemu_snapshot)

    if args.live:
        print("TODO: Live comparison against running recompiled game")
        print("For now, export a snapshot from the recomp and pass it as second argument")
        sys.exit(1)

    if not args.recomp_snapshot:
        print("ERROR: Provide a recomp snapshot path or use --live")
        sys.exit(1)

    recomp = load_snapshot(args.recomp_snapshot)
    compare_snapshots(xemu, recomp)


if __name__ == '__main__':
    main()
