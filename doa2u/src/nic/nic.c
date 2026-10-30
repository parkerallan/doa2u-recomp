/* nForce NIC at Xbox VA 0xFEF00000 (IRQ 4) for XNET's own driver, per the cxbx NVNet
 * trace and the driver (0x389171 reset, 0x3893A0 RX, 0x3894F9 TX done, 0x3899E4 DPC). */

#include "kernel.h"
#include "nic.h"
#include <stdio.h>
#include <string.h>

extern ptrdiff_t g_xbox_mem_offset;
#define NIC_PTR(va) ((uint8_t*)((uintptr_t)(va) + g_xbox_mem_offset))

#define NIC_BASE        0xFEF00000u
#define NIC_SIZE        0x400u
#define REG_IRQ_STATUS  0x000   /* write 1 to clear */
#define REG_IRQ_MASK    0x004
#define REG_TXRX_CTL    0x144   /* bit 0 kicks TX; reads report bit 3 idle */
#define REG_TX_RING     0x100   /* 8-byte descriptors: buffer, flags << 16 | length */
#define REG_RX_RING     0x104
#define REG_RING_SIZES  0x108   /* (rx - 1) << 16 | (tx - 1) */
#define REG_MII_STATUS  0x180   /* write 1 to clear */
#define REG_MII_CTL     0x190   /* PHY 1 reg in bits 0-4, 0x400 = write, 0x8000 = busy */
#define REG_MII_DATA    0x194
#define IRQ_RX          0x02
#define IRQ_TX_OK       0x10

static uint32_t s_regs[NIC_SIZE / 4];
static uint32_t s_tx_idx, s_rx_idx;
static uint8_t  s_tx_frame[0x800];
static uint32_t s_tx_len;
static int      s_held_logged;   /* capped "RX held" warnings */

/* Host-thread RX queue, moved into the guest ring on the game thread. */
#define RXQ_MAX 64
static struct { uint16_t len; LONGLONG t; uint8_t data[0x600]; } s_rxq[RXQ_MAX];
static int s_rxq_head, s_rxq_count;
static SRWLOCK s_rxq_lock = SRWLOCK_INIT;

/* Walk the TX ring while descriptors are NIC-owned (0x8000); 0x0001 marks a frame's
 * last fragment, the length field is length - 1. Clearing 0x8000 hands it back. */
static void nic_kick_tx(void)
{
    uint32_t ring = s_regs[REG_TX_RING / 4];
    uint32_t size = (s_regs[REG_RING_SIZES / 4] & 0xFFFF) + 1;
    uint32_t n;

    if (!ring)
        return;
    for (n = 0; n < size; n++) {
        uint8_t* desc = NIC_PTR(ring + s_tx_idx * 8);
        uint32_t buf = *(uint32_t*)desc, ctl = *(uint32_t*)(desc + 4);
        uint32_t len = (ctl & 0xFFFF) + 1;
        if (!(ctl & 0x80000000u))
            break;
        if (s_tx_len + len <= sizeof(s_tx_frame)) {
            memcpy(s_tx_frame + s_tx_len, NIC_PTR(buf), len);
            s_tx_len += len;
        }
        *(uint32_t*)(desc + 4) = ctl & ~0x80000000u;
        if (ctl & 0x00010000u) {
            extern void doa2u_netdiag_tx(void);
            nic_net_send(s_tx_frame, s_tx_len);
            doa2u_netdiag_tx();
            s_tx_len = 0;
        }
        s_tx_idx = (s_tx_idx + 1) % size;
    }
    s_regs[REG_IRQ_STATUS / 4] |= IRQ_TX_OK;
}

static uint32_t nic_mii_read(uint32_t phy, uint32_t reg)
{
    if (phy != 1)
        return 0;
    switch (reg) {
    case 1: return 0x0024;           /* BMSR: auto-negotiation complete, link up */
    case 4: return 0x01E0;           /* ADVERTISE: 10/100 half/full */
    case 5: return 0x01E0;           /* LPA: partner the same */
    default: return 0;
    }
}

static uint32_t nic_reg_read32(uint32_t off)
{
    uint32_t v = s_regs[off / 4];
    if (off == REG_TXRX_CTL)
        v |= 0x08;                   /* idle */
    return v;
}

static void nic_reg_write32(uint32_t off, uint32_t v)
{
    switch (off) {
    case REG_IRQ_STATUS:
    case REG_MII_STATUS:
    case 0x088:
    case 0x098:
        s_regs[off / 4] &= ~v;
        break;
    case REG_TXRX_CTL:
        s_regs[off / 4] = v & ~1u;
        if (v & 1)
            nic_kick_tx();
        break;
    case REG_TX_RING:
        s_regs[off / 4] = v;
        s_tx_idx = 0;
        s_tx_len = 0;
        break;
    case REG_RX_RING:
        s_regs[off / 4] = v;
        s_rx_idx = 0;
        break;
    case REG_MII_CTL:
        if (v & 0x400) {
            /* PHY register writes are accepted and ignored */
        } else {
            s_regs[REG_MII_DATA / 4] = nic_mii_read((v >> 5) & 0x1F, v & 0x1F);
        }
        s_regs[off / 4] = v & ~0x8000u;
        break;
    default:
        s_regs[off / 4] = v;
        break;
    }
}

static uint64_t nic_read(uint32_t off, int size)
{
    uint32_t v;
    if (off >= NIC_SIZE)
        return 0;
    v = nic_reg_read32(off & ~3u) >> ((off & 3) * 8);
    if (size == 1) return v & 0xFF;
    if (size == 2) return v & 0xFFFF;
    return v;
}

static void nic_write(uint32_t off, uint64_t val, int size)
{
    uint32_t shift, mask, cur;
    if (off >= NIC_SIZE)
        return;
    if (size >= 4) {
        nic_reg_write32(off & ~3u, (uint32_t)val);
        return;
    }
    shift = (off & 3) * 8;
    mask = (size == 1 ? 0xFFu : 0xFFFFu) << shift;
    cur = s_regs[(off & ~3u) / 4];
    nic_reg_write32(off & ~3u, (cur & ~mask) | (((uint32_t)val << shift) & mask));
}

void nic_rx_enqueue(const uint8_t* frame, uint32_t len)
{
    if (len == 0 || len > sizeof(s_rxq[0].data))
        return;
    AcquireSRWLockExclusive(&s_rxq_lock);
    if (s_rxq_count < RXQ_MAX) {
        int slot = (s_rxq_head + s_rxq_count) % RXQ_MAX;
        extern void doa2u_netdiag_rx_arrive(LONGLONG);
        LARGE_INTEGER t;
        QueryPerformanceCounter(&t);
        s_rxq[slot].len = (uint16_t)len;
        s_rxq[slot].t = t.QuadPart;
        memcpy(s_rxq[slot].data, frame, len);
        s_rxq_count++;
        doa2u_netdiag_rx_arrive(t.QuadPart);
    }
    ReleaseSRWLockExclusive(&s_rxq_lock);
}

/* Game thread: queued frames into RX descriptors the driver armed (0x8000 | 0x7FD);
 * the NIC writes 0x0001 (valid) | frame length, as the driver's RX loop reads it. */
static void nic_deliver_rx(void)
{
    extern void doa2u_netdiag_rx(int, int, LONGLONG);
    uint32_t ring = s_regs[REG_RX_RING / 4];
    uint32_t size = (s_regs[REG_RING_SIZES / 4] >> 16) + 1;
    int delivered = 0, held = 0;
    LONGLONG oldest = 0;

    if (!ring)
        return;
    AcquireSRWLockExclusive(&s_rxq_lock);
    while (s_rxq_count) {
        uint8_t* desc = NIC_PTR(ring + s_rx_idx * 8);
        uint32_t buf = *(uint32_t*)desc, ctl = *(uint32_t*)(desc + 4);
        uint32_t len = s_rxq[s_rxq_head].len;
        if (!(ctl & 0x80000000u) || len > (ctl & 0xFFFF) + 1) {
            if (s_held_logged < 200) {
                s_held_logged++;
                xbox_log(XBOX_LOG_WARN, "NIC", "RX held: desc %u ctl %08X, %d frame(s) waiting",
                         s_rx_idx, ctl, s_rxq_count);
            }
            held = s_rxq_count;
            break;
        }
        if (!delivered) oldest = s_rxq[s_rxq_head].t;
        memcpy(NIC_PTR(buf), s_rxq[s_rxq_head].data, len);
        *(uint32_t*)(desc + 4) = 0x00010000u | len;
        s_rxq_head = (s_rxq_head + 1) % RXQ_MAX;
        s_rxq_count--;
        s_rx_idx = (s_rx_idx + 1) % size;
        s_regs[REG_IRQ_STATUS / 4] |= IRQ_RX;
        delivered++;
    }
    ReleaseSRWLockExclusive(&s_rxq_lock);
    doa2u_netdiag_rx(delivered, held, oldest);
}

int nic_poll_irq(void)
{
    nic_deliver_rx();
    return (s_regs[REG_IRQ_STATUS / 4] & s_regs[REG_IRQ_MASK / 4]) != 0;
}

/* ============================================================
 * VEH decoder (from apu_mmio_hook.c), plus TEST/CMP/OR/AND imm forms:
 * the recompiled driver polls bits with `test byte ptr [m], imm8`.
 * ============================================================ */

static uint64_t* ctx_reg64(PCONTEXT ctx, int reg)
{
    switch (reg & 0xF) {
    case 0:  return (uint64_t*)&ctx->Rax;
    case 1:  return (uint64_t*)&ctx->Rcx;
    case 2:  return (uint64_t*)&ctx->Rdx;
    case 3:  return (uint64_t*)&ctx->Rbx;
    case 4:  return (uint64_t*)&ctx->Rsp;
    case 5:  return (uint64_t*)&ctx->Rbp;
    case 6:  return (uint64_t*)&ctx->Rsi;
    case 7:  return (uint64_t*)&ctx->Rdi;
    case 8:  return (uint64_t*)&ctx->R8;
    case 9:  return (uint64_t*)&ctx->R9;
    case 10: return (uint64_t*)&ctx->R10;
    case 11: return (uint64_t*)&ctx->R11;
    case 12: return (uint64_t*)&ctx->R12;
    case 13: return (uint64_t*)&ctx->R13;
    case 14: return (uint64_t*)&ctx->R14;
    default: return (uint64_t*)&ctx->R15;
    }
}

static int decode_modrm_len(const uint8_t* ip)
{
    uint8_t modrm = *ip;
    int mod = (modrm >> 6) & 3, rm = modrm & 7, len = 1;
    if (mod == 3) return 1;
    if (rm == 4) len += 1;                      /* SIB */
    if (mod == 0 && rm == 5) len += 4;          /* disp32 / RIP-relative */
    else if (mod == 1) len += 1;
    else if (mod == 2) len += 4;
    return len;
}

/* Flags for a logical result (TEST/AND/OR) or a subtraction (CMP). */
static void set_flags(PCONTEXT ctx, uint64_t a, uint64_t b, int size, int is_sub)
{
    uint64_t mask = size >= 8 ? ~0ULL : ((1ULL << (size * 8)) - 1);
    uint64_t r;
    a &= mask; b &= mask;
    r = (is_sub ? a - b : a) & mask;
    ctx->EFlags &= ~(0x0001u | 0x0004u | 0x0040u | 0x0080u | 0x0800u);
    if (r == 0) ctx->EFlags |= 0x0040;
    if (r & (1ULL << (size * 8 - 1))) ctx->EFlags |= 0x0080;
    if (is_sub) {
        uint64_t sign = 1ULL << (size * 8 - 1);
        if (a < b) ctx->EFlags |= 0x0001;
        if (((a ^ b) & (a ^ r)) & sign) ctx->EFlags |= 0x0800;
    }
    {
        int ones = 0, i;
        for (i = 0; i < 8; i++) ones += (int)((r >> i) & 1);
        if (!(ones & 1)) ctx->EFlags |= 0x0004;
    }
}

static int nic_decode(PCONTEXT ctx, uint32_t off)
{
    const uint8_t* ip = (const uint8_t*)ctx->Rip;
    int pre = 0, has_66 = 0, rex = 0, size, ml, reg;
    const uint8_t* op;

    for (;;) {
        uint8_t b = ip[pre];
        if (b == 0x66) { has_66 = 1; pre++; }
        else if (b == 0xF2 || b == 0xF3) pre++;
        else if (b >= 0x40 && b <= 0x4F) { rex = b; pre++; }
        else break;
    }
    op = ip + pre;
    size = (rex & 8) ? 8 : has_66 ? 2 : 4;

    switch (op[0]) {
    case 0x88: case 0x89:                               /* MOV m, r */
        if (op[0] == 0x88) size = 1;
        ml = decode_modrm_len(op + 1);
        reg = ((op[1] >> 3) & 7) | ((rex & 4) ? 8 : 0);
        nic_write(off, *ctx_reg64(ctx, reg), size);
        ctx->Rip += pre + 1 + ml;
        return 1;
    case 0xC6: case 0xC7:                               /* MOV m, imm */
        ml = decode_modrm_len(op + 1);
        if (op[0] == 0xC6) {
            nic_write(off, op[1 + ml], 1);
            ctx->Rip += pre + 1 + ml + 1;
        } else if (size == 2) {
            nic_write(off, *(const uint16_t*)(op + 1 + ml), 2);
            ctx->Rip += pre + 1 + ml + 2;
        } else {
            nic_write(off, (uint32_t)*(const int32_t*)(op + 1 + ml), size);
            ctx->Rip += pre + 1 + ml + 4;
        }
        return 1;
    case 0x8A: case 0x8B: {                             /* MOV r, m */
        uint64_t v, *dst;
        if (op[0] == 0x8A) size = 1;
        ml = decode_modrm_len(op + 1);
        reg = ((op[1] >> 3) & 7) | ((rex & 4) ? 8 : 0);
        v = nic_read(off, size);
        dst = ctx_reg64(ctx, reg);
        if (size == 1) *dst = (*dst & ~0xFFULL) | (v & 0xFF);
        else if (size == 2) *dst = (*dst & ~0xFFFFULL) | (v & 0xFFFF);
        else *dst = v & 0xFFFFFFFFu;
        ctx->Rip += pre + 1 + ml;
        return 1;
    }
    case 0x0F:
        if (op[1] == 0xB6 || op[1] == 0xB7) {           /* MOVZX r, m8/m16 */
            ml = decode_modrm_len(op + 2);
            reg = ((op[2] >> 3) & 7) | ((rex & 4) ? 8 : 0);
            *ctx_reg64(ctx, reg) = nic_read(off, op[1] == 0xB6 ? 1 : 2);
            ctx->Rip += pre + 2 + ml;
            return 1;
        }
        break;
    case 0x84: case 0x85:                               /* TEST m, r */
    case 0x38: case 0x39:                               /* CMP m, r */
        if (!(op[0] & 1)) size = 1;
        ml = decode_modrm_len(op + 1);
        reg = ((op[1] >> 3) & 7) | ((rex & 4) ? 8 : 0);
        if (op[0] >= 0x84)
            set_flags(ctx, nic_read(off, size) & *ctx_reg64(ctx, reg), 0, size, 0);
        else
            set_flags(ctx, nic_read(off, size), *ctx_reg64(ctx, reg), size, 1);
        ctx->Rip += pre + 1 + ml;
        return 1;
    case 0xF6: case 0xF7:                               /* TEST m, imm */
        if (((op[1] >> 3) & 7) != 0) break;
        ml = decode_modrm_len(op + 1);
        if (op[0] == 0xF6) {
            set_flags(ctx, nic_read(off, 1) & op[1 + ml], 0, 1, 0);
            ctx->Rip += pre + 1 + ml + 1;
        } else {
            uint32_t imm = size == 2 ? *(const uint16_t*)(op + 1 + ml) : *(const uint32_t*)(op + 1 + ml);
            set_flags(ctx, nic_read(off, size) & imm, 0, size, 0);
            ctx->Rip += pre + 1 + ml + (size == 2 ? 2 : 4);
        }
        return 1;
    case 0x80: case 0x81: case 0x83: {                  /* OR/AND/CMP m, imm */
        int sub = (op[1] >> 3) & 7, ilen;
        uint64_t imm, m;
        if (op[0] == 0x80) size = 1;
        ml = decode_modrm_len(op + 1);
        if (op[0] == 0x81) {
            ilen = size == 2 ? 2 : 4;
            imm = size == 2 ? *(const uint16_t*)(op + 1 + ml) : (uint64_t)(int64_t)*(const int32_t*)(op + 1 + ml);
        } else {
            ilen = 1;
            imm = (uint64_t)(int64_t)(int8_t)op[1 + ml];
        }
        m = nic_read(off, size);
        if (sub == 7) set_flags(ctx, m, imm, size, 1);
        else if (sub == 1) { nic_write(off, m | imm, size); set_flags(ctx, m | imm, 0, size, 0); }
        else if (sub == 4) { nic_write(off, m & imm, size); set_flags(ctx, m & imm, 0, size, 0); }
        else break;
        ctx->Rip += pre + 1 + ml + ilen;
        return 1;
    }
    case 0x08: case 0x09: case 0x20: case 0x21: {       /* OR/AND m, r */
        uint64_t m, r;
        if (!(op[0] & 1)) size = 1;
        ml = decode_modrm_len(op + 1);
        reg = ((op[1] >> 3) & 7) | ((rex & 4) ? 8 : 0);
        m = nic_read(off, size);
        r = *ctx_reg64(ctx, reg);
        m = op[0] >= 0x20 ? (m & r) : (m | r);
        nic_write(off, m, size);
        set_flags(ctx, m, 0, size, 0);
        ctx->Rip += pre + 1 + ml;
        return 1;
    }
    }
    xbox_log(XBOX_LOG_WARN, "NIC", "unhandled MMIO instruction at off 0x%03X: %02X %02X %02X %02X %02X",
             off, ip[0], ip[1], ip[2], ip[3], ip[4]);
    return 0;
}

int nic_hook_handle_mmio(PCONTEXT ctx, uint32_t fault_xbox_va)
{
    return nic_decode(ctx, fault_xbox_va - NIC_BASE);
}
