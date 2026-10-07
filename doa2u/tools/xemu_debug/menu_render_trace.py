"""
Breakpoint trace on sub_001AE6F0 (frontend render dispatch) and its callees.

Sets breakpoints on key functions in the menu render chain, captures
register state and stack arguments at each hit, then resumes.

Strategy: halt, set BP on 001AE6F0, continue, wait for hit, read regs+stack,
then single-step through calls to see the dispatch flow.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]

def hex32(v): return f"0x{v:08X}"

def read_reg(regs, name):
    """Read a register from the register dict."""
    return regs.get(name, 0)

def dump_regs(client):
    """Read and print all registers."""
    regs = client.read_registers()
    if regs:
        print(f"    EAX={hex32(regs.get('eax',0))} ECX={hex32(regs.get('ecx',0))} EDX={hex32(regs.get('edx',0))} EBX={hex32(regs.get('ebx',0))}")
        print(f"    ESP={hex32(regs.get('esp',0))} EBP={hex32(regs.get('ebp',0))} ESI={hex32(regs.get('esi',0))} EDI={hex32(regs.get('edi',0))}")
        print(f"    EIP={hex32(regs.get('eip',0))}")
    return regs

def read_stack(client, esp, count=8):
    """Read stack values."""
    data = client.read_memory(esp, count * 4)
    vals = []
    for i in range(count):
        vals.append(u32(data, i * 4))
    return vals


def trace_function_calls(client):
    """
    Multi-breakpoint approach:
    1. BP on sub_001AE6F0 entry
    2. BP on sub_001AD350 (render list dispatch)
    3. BP on sub_0034D530 (79K render func)
    4. BP on sub_001DE900 (im2d render primitive)
    5. BP on sub_001AEE20 (screen entry validator)
    6. BP on sub_001AF040 (screen list vtable[2])
    7. BP on sub_001AF180 (screen list vtable[3])
    8. BP on sub_001AEFD0 (screen list vtable[1])

    Set all BPs, continue, collect hits for ~2 seconds (a few frames).
    """

    breakpoints = {
        0x001AE6F0: 'sub_001AE6F0 (frontend render dispatch)',
        0x001AD350: 'sub_001AD350 (render list dispatch)',
        0x0034D530: 'sub_0034D530 (79K render)',
        0x001DE900: 'sub_001DE900 (im2d render prim)',
        0x001AEE20: 'sub_001AEE20 (screen entry validator)',
        0x001AF040: 'sub_001AF040 (sl vtable[2])',
        0x001AF180: 'sub_001AF180 (sl vtable[3])',
        0x001AEFD0: 'sub_001AEFD0 (sl vtable[1])',
        0x00014D20: 'sub_00014D20 (frontend render method)',
        0x000171A0: 'sub_000171A0 (frontend dispatch)',
        # im2d functions
        0x001E60B0: 'sub_001E60B0 (im2d tri - xemu)',
        0x001E6250: 'sub_001E6250 (im2d line - xemu)',
        0x001E2930: 'sub_001E2930 (im2d tri - recomp)',
        0x001E2330: 'sub_001E2330 (im2d line - recomp)',
        # Sub-calls from 1AE6F0 (identified from code bytes)
        0x001891E0: 'sub_001891E0 (called from 1AE6F0?)',
        0x00189170: 'sub_00189170 (called from 1AE6F0?)',
        0x001D0600: 'sub_001D0600 (called from 1AE6F0?)',
    }

    print("\n=== Setting breakpoints ===")
    # IMPORTANT: Must halt CPU before setting breakpoints
    print("Halting CPU...")
    client.halt()
    time.sleep(0.3)

    bp_addrs = list(breakpoints.keys())
    for addr in bp_addrs:
        try:
            client.set_breakpoint(addr)
            print(f"  BP set at {hex32(addr)}: {breakpoints[addr]}")
        except Exception as e:
            print(f"  BP FAILED at {hex32(addr)}: {e}")

    print(f"\n=== Collecting breakpoint hits (will collect ~20 hits) ===")
    print("Resuming execution...")

    hits = []
    max_hits = 30

    for hit_num in range(max_hits):
        try:
            # Continue and wait for breakpoint hit
            client.continue_execution()

            # Wait for stop (breakpoint hit)
            response = client.wait_for_stop(timeout=5.0)
            if response == 'timeout':
                print(f"  Timeout waiting for BP hit after {hit_num} hits")
                break

            # Read registers
            regs = client.read_registers()
            eip = regs.get('eip', 0)
            esp = regs.get('esp', 0)

            bp_name = breakpoints.get(eip, f"UNKNOWN ({hex32(eip)})")

            # Read stack args
            stack = read_stack(client, esp, 8) if esp else []

            hit = {
                'num': hit_num,
                'eip': eip,
                'name': bp_name,
                'regs': {k: v for k, v in regs.items() if isinstance(v, int)},
                'stack': stack,
            }
            hits.append(hit)

            print(f"\n  Hit #{hit_num}: {bp_name}")
            print(f"    EIP={hex32(eip)} ESP={hex32(esp)}")
            print(f"    EAX={hex32(regs.get('eax',0))} ECX={hex32(regs.get('ecx',0))} EDX={hex32(regs.get('edx',0))}")
            print(f"    EBX={hex32(regs.get('ebx',0))} ESI={hex32(regs.get('esi',0))} EDI={hex32(regs.get('edi',0))}")
            print(f"    EBP={hex32(regs.get('ebp',0))}")
            print(f"    Stack: {' '.join(hex32(s) for s in stack[:6])}")

            # For sub_001AE6F0, read key memory too
            if eip == 0x001AE6F0:
                # Read the two parameters (pushed on stack)
                # sub_001AE6F0(param1, param2) — stdcall/cdecl
                ret_addr = stack[0] if stack else 0
                param1 = stack[1] if len(stack) > 1 else 0
                param2 = stack[2] if len(stack) > 2 else 0
                print(f"    RetAddr={hex32(ret_addr)} Param1={hex32(param1)} Param2={hex32(param2)}")

            # For im2d calls, read vertex data info
            if eip in (0x001DE900, 0x001E60B0, 0x001E2930):
                # RwIm2DRenderPrimitive(primType, vertices, numVerts)
                prim_type = stack[1] if len(stack) > 1 else 0
                verts_ptr = stack[2] if len(stack) > 2 else 0
                num_verts = stack[3] if len(stack) > 3 else 0
                print(f"    PrimType={prim_type} Verts={hex32(verts_ptr)} NumVerts={num_verts}")

            # For sub_001AD350 (render list dispatch)
            if eip == 0x001AD350:
                param1 = stack[1] if len(stack) > 1 else 0
                param2 = stack[2] if len(stack) > 2 else 0
                print(f"    RenderList param1={hex32(param1)} param2={hex32(param2)}")
                # Read param1 structure if valid
                if param1 > 0x10000 and param1 < 0x10000000:
                    rl_data = client.read_memory(param1, 0x40)
                    print(f"    RenderList struct:")
                    for off in range(0, 0x40, 4):
                        val = u32(rl_data, off)
                        if val != 0:
                            print(f"      +{off:02X}: {hex32(val)}")

        except Exception as e:
            print(f"  Error on hit #{hit_num}: {e}")
            break

    # Clean up: remove all breakpoints before continuing
    print(f"\n=== Removing breakpoints ===")
    # Must halt first
    try:
        client.halt()
        time.sleep(0.2)
    except:
        pass

    for addr in bp_addrs:
        try:
            client.remove_breakpoint(addr)
            print(f"  Removed BP at {hex32(addr)}")
        except Exception as e:
            print(f"  Remove failed at {hex32(addr)}: {e}")

    # Resume
    print("\nResuming CPU...")
    client.continue_execution()

    # Summary
    print(f"\n{'='*60}")
    print(f"=== TRACE SUMMARY ({len(hits)} hits) ===")
    print(f"{'='*60}")

    hit_counts = {}
    for h in hits:
        name = h['name']
        hit_counts[name] = hit_counts.get(name, 0) + 1

    for name, count in sorted(hit_counts.items(), key=lambda x: -x[1]):
        print(f"  {count:4d}x  {name}")

    # Print call sequence
    print(f"\n=== Call sequence ===")
    for h in hits:
        print(f"  #{h['num']:2d}: {h['name']}")

    return hits


def main():
    print("=" * 60)
    print("  Burnout 3 - Menu Render Dispatch Trace")
    print("=" * 60)

    client = GDBClient('localhost', 1234)
    client.connect()

    try:
        hits = trace_function_calls(client)
    except Exception as e:
        print(f"\nFATAL ERROR: {e}")
        import traceback
        traceback.print_exc()

        # Emergency cleanup - try to remove BPs and resume
        print("\nEmergency cleanup...")
        try:
            client.halt()
            time.sleep(0.2)
            for addr in [0x001AE6F0, 0x001AD350, 0x0034D530, 0x001DE900,
                         0x001AEE20, 0x001AF040, 0x001AF180, 0x001AEFD0,
                         0x00014D20, 0x000171A0, 0x001E60B0, 0x001E6250,
                         0x001E2930, 0x001E2330, 0x001891E0, 0x00189170,
                         0x001D0600]:
                try:
                    client.remove_breakpoint(addr)
                except:
                    pass
            client.continue_execution()
            print("Cleanup done, CPU resumed")
        except:
            print("WARNING: Could not clean up! You may need to restart xemu.")
    finally:
        client.disconnect()


if __name__ == '__main__':
    main()
