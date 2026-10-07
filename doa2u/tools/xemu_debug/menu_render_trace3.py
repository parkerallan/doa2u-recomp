"""
Two-phase trace: hit sub_00014D20 once, remove it, then collect inner hits.
Also tries single-stepping from sub_00014D20 to see call targets.
"""
import os, sys, struct, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tools.xemu_debug.gdb_client import GDBClient

def u32(data, offset=0):
    if offset + 4 > len(data): return 0
    return struct.unpack_from('<I', data, offset)[0]
def hex32(v): return f"0x{v:08X}"

def main():
    client = GDBClient('localhost', 1234)
    client.connect()

    # All inner BPs (NO outer functions)
    inner_bps = {
        0x001AE6F0: 'sub_001AE6F0 (frontend render dispatch)',
        0x001AD350: 'sub_001AD350 (render list dispatch)',
        0x0034D530: 'sub_0034D530 (79K render)',
        0x001DE900: 'sub_001DE900 (im2d render prim)',
        0x001E60B0: 'sub_001E60B0 (im2d tri)',
        0x001E6250: 'sub_001E6250 (im2d line)',
        0x001AEFD0: 'sub_001AEFD0 (sl vtable[1])',
        0x001AF040: 'sub_001AF040 (sl vtable[2])',
        0x001AF180: 'sub_001AF180 (sl vtable[3])',
        0x001DDAF0: 'sub_001DDAF0 (RW camera render)',
        0x001D9420: 'sub_001D9420 (RW display)',
        0x001DE7E0: 'sub_001DE7E0 (RW render)',
        0x00351090: 'sub_00351090 (RW render inner)',
        0x001891E0: 'sub_001891E0',
        0x001D0600: 'sub_001D0600',
        0x0034EDB0: 'sub_0034EDB0 (called from 1AD350)',
        0x001D7D10: 'sub_001D7D10 (im2d from 1AD350)',
    }

    all_bp_addrs = list(inner_bps.keys()) + [0x00014D20]

    try:
        # Phase 1: Single-step through sub_00014D20 to see what it calls
        print("\n=== Phase 1: Single-step through sub_00014D20 ===")
        print("Halting CPU...")
        client.halt()
        time.sleep(0.3)

        # Set BP only on 00014D20
        client.set_breakpoint(0x00014D20)
        print("BP set on sub_00014D20, continuing...")
        client.continue_execution()
        resp = client.wait_for_stop(timeout=5.0)

        regs = client.read_registers()
        eip = regs.get('eip', 0)
        print(f"Stopped at EIP={hex32(eip)}")

        if eip == 0x00014D20:
            # Remove the BP so we don't re-hit it
            client.remove_breakpoint(0x00014D20)

            # Single-step through the function, recording call targets
            print("\nSingle-stepping (up to 500 instructions)...")
            call_targets = []
            prev_eip = eip
            step_count = 0

            for i in range(500):
                regs = client.single_step()
                eip = regs.get('eip', 0)
                step_count += 1

                # Detect calls: if EIP jumped far from prev_eip and
                # return address is on stack
                jump_dist = abs(eip - prev_eip)
                if jump_dist > 0x100 and eip < 0x400000:
                    # Read what's at ESP (potential return address)
                    esp = regs.get('esp', 0)
                    ret_data = client.read_memory(esp, 4) if esp else b'\x00\x00\x00\x00'
                    ret_addr = u32(ret_data)

                    # If ret_addr is near prev_eip, this was a CALL
                    if abs(ret_addr - prev_eip) < 0x20:
                        fname = inner_bps.get(eip, f"sub_{eip:08X}")
                        call_targets.append((i, eip, fname, prev_eip))
                        print(f"  Step {i:3d}: CALL {hex32(eip)} ({fname}) from {hex32(prev_eip)}")

                # Detect return to caller of sub_00014D20
                if eip == 0x00017244:  # Known return address from stack
                    print(f"  Step {i:3d}: RETURNED to caller at {hex32(eip)}")
                    break

                prev_eip = eip

            print(f"\nSingle-stepped {step_count} instructions")
            print(f"Found {len(call_targets)} CALL instructions:")
            for step, addr, name, from_addr in call_targets:
                print(f"  {hex32(addr)} ({name}) called from {hex32(from_addr)}")

        # Phase 2: Set only inner BPs, remove 00014D20, collect hits
        print(f"\n\n=== Phase 2: Inner-only breakpoints ===")
        # Make sure 00014D20 BP is removed
        try:
            client.remove_breakpoint(0x00014D20)
        except:
            pass

        # Halt if needed
        try:
            client.halt()
            time.sleep(0.2)
        except:
            pass

        for addr in inner_bps:
            client.set_breakpoint(addr)

        print(f"Set {len(inner_bps)} inner BPs, collecting hits...")
        hits = []

        for hit_num in range(30):
            client.continue_execution()
            response = client.wait_for_stop(timeout=5.0)
            if response == 'timeout':
                print(f"  Timeout after {hit_num} hits")
                break

            regs = client.read_registers()
            eip = regs.get('eip', 0)
            esp = regs.get('esp', 0)
            name = inner_bps.get(eip, f"UNKNOWN ({hex32(eip)})")

            stack_data = client.read_memory(esp, 32) if esp else b'\x00'*32
            stack = [u32(stack_data, i*4) for i in range(8)]

            hits.append({'eip': eip, 'name': name, 'stack': stack,
                         'esi': regs.get('esi',0), 'edi': regs.get('edi',0),
                         'eax': regs.get('eax',0), 'ecx': regs.get('ecx',0),
                         'ebp': regs.get('ebp',0)})

            print(f"  #{hit_num}: {name}")
            print(f"    EIP={hex32(eip)} RetAddr={hex32(stack[0])}")
            print(f"    ESI={hex32(regs.get('esi',0))} EDI={hex32(regs.get('edi',0))}")
            print(f"    Stack: {' '.join(hex32(s) for s in stack[:5])}")

            if eip == 0x001AE6F0:
                print(f"    >> Param1={hex32(stack[1])} Param2={hex32(stack[2])}")
            elif eip == 0x001AD350:
                print(f"    >> Param1={hex32(stack[1])} Param2={hex32(stack[2])}")
            elif eip == 0x001DE900:
                print(f"    >> PrimType={stack[1]} Verts={hex32(stack[2])} N={stack[3]}")
            elif eip == 0x001E60B0:
                print(f"    >> Im2dTri: {hex32(stack[1])} {hex32(stack[2])} {hex32(stack[3])}")

    except Exception as e:
        print(f"\nERROR: {e}")
        import traceback; traceback.print_exc()
    finally:
        # Cleanup
        print("\nCleaning up breakpoints...")
        try:
            client.halt(); time.sleep(0.2)
        except: pass
        for addr in all_bp_addrs:
            try: client.remove_breakpoint(addr)
            except: pass
        for addr in inner_bps:
            try: client.remove_breakpoint(addr)
            except: pass
        try:
            client.continue_execution()
            print("CPU resumed.")
        except: pass
        client.disconnect()

if __name__ == '__main__':
    main()
