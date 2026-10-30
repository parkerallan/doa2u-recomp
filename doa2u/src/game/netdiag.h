#pragma once
#include <stdint.h>

/* Network slowdown diagnostics: doa2u_net.log next to the exe, one summary line per
 * second once the NIC is up, plus a line for every wait or frame gap over 50 ms. */
void doa2u_netdiag_frame(void);
void doa2u_netdiag_wait(uint32_t obj, uint32_t caller, double ms, int timed_out);
void doa2u_netdiag_tx(void);
void doa2u_netdiag_rx(int delivered, int held);
