/* nForce NIC emulation (nic.c): MMIO from the VEH and the IRQ 4 line; frames to and
 * from the host network go through nic_net.c (libslirp). */
#ifndef DOA2U_NIC_H
#define DOA2U_NIC_H

#include <windows.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* VEH: a guest access to 0xFEF00000..0xFEF003FF. Non-zero when handled. */
int nic_hook_handle_mmio(PCONTEXT ctx, uint32_t fault_xbox_va);

/* Game thread: moves received frames into the RX ring; non-zero while IRQ 4 is asserted. */
int nic_poll_irq(void);

/* nic_net.c: a frame the guest transmitted, to libslirp (game thread). */
void nic_net_send(const uint8_t* frame, uint32_t len);

/* A frame for the guest; any thread. */
void nic_rx_enqueue(const uint8_t* frame, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* DOA2U_NIC_H */
