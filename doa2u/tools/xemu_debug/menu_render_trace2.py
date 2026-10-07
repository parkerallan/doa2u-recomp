"""
Trace only the INNER functions of the menu render chain.
Skip sub_000171A0 (fires every frame and blocks inner hits).
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]
def hex32(v): return f"0x{v:08X}"

def main():
    breakpoints = {
        # Inner render chain (NOT 000171A0)
        0x00014D20: 'sub_00014D20 (frontend render method vtable[3])',
        0x001AE6F0: 'sub_001AE6F0 (frontend render dispatch)',
        0x001AD350: 'sub_001AD350 (render list dispatch)',
        0x0034D530: 'sub_0034D530 (79K render)',
        0x001DE900: 'sub_001DE900 (im2d render prim)',
        0x001E60B0: 'sub_001E60B0 (im2d tri)',
        0x001E6250: 'sub_001E6250 (im2d line)',
        # Screen list methods
        0x001AEFD0: 'sub_001AEFD0 (sl vtable[1])',
        0x001AF040: 'sub_001AF040 (sl vtable[2])',
        0x001AF180: 'sub_001AF180 (sl vtable[3])',
        # RW render pipeline
        0x001DDAF0: 'sub_001DDAF0 (RW camera render)',
        0x001D9420: 'sub_001D9420 (RW display)',
        0x001DE7E0: 'sub_001DE7E0 (RW render)',
        0x00351090: 'sub_00351090 (RW render inner)',
        # Other candidates from code bytes
        0x001891E0: 'sub_001891E0',
        0x001D0600: 'sub_001D0600',
    }

    client = GDBClient('localhost', 1234)
    client.connect()

    try:
        print("\nHalting CPU...")
        client.halt()
        time.sleep(0.3)

        print("Setting breakpoints (inner functions only)...")
        bp_addrs = list(breakpoints.keys())
        for addr in bp_addrs:
            try:
                client.set_breakpoint(addr)
                print(f"  BP: {hex32(addr)} {breakpoints[addr]}")
            except Exception as e:
                print(f"  FAIL: {hex32(addr)}: {e}")

        print(f"\nCollecting hits...")
        hits = []

        for hit_num in range(40):
            client.continue_execution()
            response = client.wait_for_stop(timeout=5.0)
            if response == 'timeout':
                print(f"  Timeout after {hit_num} hits")
                break

            regs = client.read_registers()
            eip = regs.get('eip', 0)
            esp = regs.get('esp', 0)
            bp_name = breakpoints.get(eip, f"UNKNOWN ({hex32(eip)})")

            # Read stack
            stack_data = client.read_memory(esp, 32) if esp else b'\x00'*32
            stack = [u32(stack_data, i*4) for i in range(8)]

            hit = {'num': hit_num, 'eip': eip, 'name': bp_name, 'esp': esp,
                   'eax': regs.get('eax',0), 'ecx': regs.get('ecx',0),
                   'edx': regs.get('edx',0), 'ebx': regs.get('ebx',0),
                   'esi': regs.get('esi',0), 'edi': regs.get('edi',0),
                   'ebp': regs.get('ebp',0), 'stack': stack}
            hits.append(hit)

            print(f"\n  #{hit_num}: {bp_name}")
            print(f"    EIP={hex32(eip)} ESP={hex32(esp)}")
            print(f"    EAX={hex32(hit['eax'])} ECX={hex32(hit['ecx'])} ESI={hex32(hit['esi'])} EDI={hex32(hit['edi'])}")
            print(f"    EBP={hex32(hit['ebp'])}")
            print(f"    Stack: {' '.join(hex32(s) for s in stack[:6])}")

            # Extra info for specific functions
            if eip == 0x001AE6F0:
                ret = stack[0]; p1 = stack[1]; p2 = stack[2]
                print(f"    >> RetAddr={hex32(ret)} Param1={hex32(p1)} Param2={hex32(p2)}")
            elif eip == 0x001AD350:
                print(f"    >> Param1={hex32(stack[1])} Param2={hex32(stack[2])}")
                if stack[1] > 0x10000 and stack[1] < 0x10000000:
                    rl = client.read_memory(stack[1], 0x30)
                    print(f"    >> RenderList:")
                    for off in range(0, 0x30, 4):
                        v = u32(rl, off)
                        if v: print(f"       +{off:02X}: {hex32(v)}")
            elif eip == 0x001DE900:
                print(f"    >> PrimType={stack[1]} Verts={hex32(stack[2])} NumVerts={stack[3]}")
            elif eip == 0x001E60B0:
                print(f"    >> Im2d tri args: {hex32(stack[1])} {hex32(stack[2])} {hex32(stack[3])}")
            elif eip == 0x0034D530:
                print(f"    >> 79K render args: {hex32(stack[1])} {hex32(stack[2])}")

        # Cleanup
        print(f"\n\nRemoving breakpoints...")
        client.halt()
        time.sleep(0.2)
        for addr in bp_addrs:
            try:
                client.remove_breakpoint(addr)
            except:
                pass
        client.continue_execution()
        print("CPU resumed.")

        # Summary
        print(f"\n{'='*60}")
        print(f"TRACE SUMMARY ({len(hits)} hits)")
        print(f"{'='*60}")
        counts = {}
        for h in hits:
            counts[h['name']] = counts.get(h['name'], 0) + 1
        for name, count in sorted(counts.items(), key=lambda x: -x[1]):
            print(f"  {count:4d}x  {name}")

        print(f"\nCall sequence:")
        for h in hits:
            print(f"  #{h['num']:2d}: {h['name']}")

    except Exception as e:
        print(f"\nERROR: {e}")
        import traceback; traceback.print_exc()
        # Emergency cleanup
        try:
            client.halt(); time.sleep(0.2)
            for addr in bp_addrs:
                try: client.remove_breakpoint(addr)
                except: pass
            client.continue_execution()
        except: pass
    finally:
        client.disconnect()

if __name__ == '__main__':
    main()
