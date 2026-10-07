/* Kernel bridges added for DOA2U (151 imports) and ordinal tables rebuilt from the real
 * export list (kernel_exports.h). #included by kernel_bridge.c. */
#include "kernel_exports.h"

extern uint32_t xbox_HeapAlloc(uint32_t size, uint32_t alignment);
extern void     xbox_HeapFree(uint32_t xbox_va);
extern uint32_t xbox_HeapReserveTop(uint32_t size, uint32_t alignment);

static void bridge_return_zero(void)    { g_eax = 0; }
static void bridge_return_true(void)    { g_eax = 1; }
static void bridge_status_unsuccessful(void) { g_eax = 0xC0000001u; }

/* AvSendTVEncoderOption(RegisterBase, Option, Param, Result*) */
static void bridge_AvSendTVEncoderOption(void)
{
    if (STACK_ARG(3)) BRIDGE_MEM32(STACK_ARG(3)) = 0;
}

/* DbgBreakPoint: nothing to break into. */
static void bridge_DbgBreakPoint(void) {}

/* ExFreePool(P): pool blocks come from the guest heap. */
static void bridge_ExFreePool(void)
{
    if (STACK_ARG(0)) xbox_HeapFree(STACK_ARG(0));
}

/* ExQueryNonVolatileSetting: XC_VIDEO (8) from the video settings (bit 16 = widescreen);
 * any other index reads back as zeros. */
extern unsigned video_xc_video_value(void);
static void bridge_ExQueryNonVolatileSetting(void)
{
    uint32_t index = STACK_ARG(0), type = STACK_ARG(1), value = STACK_ARG(2);
    uint32_t len = STACK_ARG(3), result = STACK_ARG(4), n = len;
    if (value && n) {
        if (n > 0x100) n = 0x100;
        memset(XBOX_TO_NATIVE(value), 0, n);
        if (index == 8 && len >= 4) BRIDGE_MEM32(value) = video_xc_video_value();
    }
    if (type) BRIDGE_MEM32(type) = 4;            /* REG_DWORD */
    if (result) BRIDGE_MEM32(result) = len < 4 ? len : 4;
    g_eax = 0;
}

/* HalReadWritePCISpace(Bus, Slot, Register, Buffer, Length, Write): no PCI
 * config space here; reads come back zero. */
static void bridge_HalReadWritePCISpace(void)
{
    uint32_t buf = STACK_ARG(3), len = STACK_ARG(4);
    if (!STACK_ARG(5) && buf && len && len <= 256)
        memset(XBOX_TO_NATIVE(buf), 0, len);
}

/* HalReturnToFirmware / HalInitiateShutdown: the title asked to reboot or
 * leave (back to the dashboard); end the process. */
static void bridge_HalReturnToFirmware(void)
{
    /* 2 = quick reboot (XAPI startup): can't restart the guest here, so carry on. */
    if (STACK_ARG(0) == 2) {
        fprintf(stderr, "[KERNEL] HalReturnToFirmware(quick reboot) ignored%c", 10);
        return;
    }
    fprintf(stderr, "[EXIT] HalReturnToFirmware(%u)%c", STACK_ARG(0), 10);
    fflush(stderr);
    ExitProcess(0);
}

/* IoCreateDevice: a zeroed DEVICE_OBJECT (0x48 bytes) followed by the extension. */
static void bridge_IoCreateDevice(void)
{
    uint32_t ext = STACK_ARG(1), out = STACK_ARG(5);
    uint32_t dev = xbox_HeapAlloc(0x48 + ext, 16);
    if (!dev) { g_eax = 0xC000009Au; return; }   /* STATUS_INSUFFICIENT_RESOURCES */
    memset(XBOX_TO_NATIVE(dev), 0, 0x48 + ext);
    BRIDGE_MEM16(dev + 0) = 3;                    /* IO_TYPE_DEVICE */
    BRIDGE_MEM16(dev + 2) = 0x48;
    BRIDGE_MEM32(dev + 0x08) = STACK_ARG(0);      /* DriverObject */
    BRIDGE_MEM32(dev + 0x18) = ext ? dev + 0x48 : 0;   /* DeviceExtension */
    BRIDGE_MEM8(dev + 0x1C) = (uint8_t)STACK_ARG(3);   /* DeviceType */
    if (out) BRIDGE_MEM32(out) = dev;
    g_eax = 0;
}

/* IoDeleteSymbolicLink / IoDismountVolumeByName: nothing to undo. */

/* IofCompleteRequest (fastcall Irp, PriorityBoost), IoMarkIrpMustComplete,
 * IoStartNextPacket[ByKey], IoStartPacket: no I/O manager behind them. */
static void bridge_void(void) {}

/* KeBugCheck(Code) */
static void bridge_KeBugCheck(void)
{
    fprintf(stderr, "[KERNEL] KeBugCheck(0x%08X) ignored%c", STACK_ARG(0), 10);
    fflush(stderr);
}

/* KeStallExecutionProcessor(MicroSeconds): a busy-wait on the console; give
 * the other fibers the time instead. */
static void bridge_KeStallExecutionProcessor(void)
{
    if (xbox_fiber_active()) xbox_fiber_yield();
}

/* KeWaitForMultipleObjects: satisfied after one yield, like KeWaitForSingleObject. */
static void bridge_KeWaitForMultipleObjects(void)
{
    if (xbox_fiber_active()) xbox_fiber_yield();
    g_eax = 0;                                    /* STATUS_WAIT_0 */
}

/* MmAllocateSystemMemory(NumberOfBytes, Protect) / MmFreeSystemMemory */
static void bridge_MmAllocateSystemMemory(void)
{
    uint32_t size = STACK_ARG(0);
    uint32_t va = xbox_HeapAlloc((size + 0xFFF) & ~0xFFFu, 0x1000);
    if (va) memset(XBOX_TO_NATIVE(va), 0, size);
    g_eax = va;
}
static void bridge_MmFreeSystemMemory(void)
{
    if (STACK_ARG(0)) xbox_HeapFree(STACK_ARG(0));
    g_eax = STACK_ARG(1);
}

/* MmClaimGpuInstanceMemory: carved from the top of the low heap; returns the region's
 * end in the cached RAM window. */
static void bridge_MmClaimGpuInstanceMemory(void)
{
    static uint32_t s_end = 0;
    uint32_t size = STACK_ARG(0), pad = STACK_ARG(1);
    if (pad) BRIDGE_MEM32(pad) = 0;
    if (!s_end && size != 0xFFFFFFFFu) {
        uint32_t base = xbox_HeapReserveTop((size + 0xFFF) & ~0xFFFu, 0x1000);
        if (base) s_end = 0x80000000u | (base + ((size + 0xFFF) & ~0xFFFu));
        fprintf(stderr, "[KERNEL] MmClaimGpuInstanceMemory(0x%X) -> end 0x%08X%c", size, s_end, 10);
    }
    g_eax = s_end;
}

/* MmCreateKernelStack(NumberOfBytes, DebuggerThread) -> stack top */
static void bridge_MmCreateKernelStack(void)
{
    uint32_t size = (STACK_ARG(0) + 0xFFF) & ~0xFFFu;
    uint32_t va = xbox_HeapAlloc(size, 0x1000);
    g_eax = va ? va + size : 0;
}

/* MmQueryAddressProtect(VirtualAddress) */
static void bridge_MmQueryAddressProtect(void) { g_eax = 4; }   /* PAGE_READWRITE */

/* NtDuplicateObject(SourceHandle, TargetHandle*, Options) */
static void bridge_NtDuplicateObject(void)
{
    if (STACK_ARG(1)) BRIDGE_MEM32(STACK_ARG(1)) = STACK_ARG(0);
    g_eax = 0;
}

/* NtQueryVirtualMemory(BaseAddress, MEMORY_BASIC_INFORMATION*) */
static void bridge_NtQueryVirtualMemory(void)
{
    uint32_t a = STACK_ARG(0) & ~0xFFFu, mbi = STACK_ARG(1);
    if (mbi) {
        BRIDGE_MEM32(mbi + 0x00) = a;             /* BaseAddress */
        BRIDGE_MEM32(mbi + 0x04) = a;             /* AllocationBase */
        BRIDGE_MEM32(mbi + 0x08) = 4;             /* AllocationProtect */
        BRIDGE_MEM32(mbi + 0x0C) = 0x1000;        /* RegionSize */
        BRIDGE_MEM32(mbi + 0x10) = 0x1000;        /* MEM_COMMIT */
        BRIDGE_MEM32(mbi + 0x14) = 4;             /* PAGE_READWRITE */
        BRIDGE_MEM32(mbi + 0x18) = 0x20000;       /* MEM_PRIVATE */
    }
    g_eax = 0;
}

/* NtSetEvent(EventHandle, PreviousState*) */
static void bridge_NtSetEvent(void)
{
    if (STACK_ARG(1)) BRIDGE_MEM32(STACK_ARG(1)) = 0;
    g_eax = 0;
}

/* NtWaitForSingleObjectEx(Handle, WaitMode, Alertable, Timeout*): the same
 * model as NtWaitForSingleObject(Handle, Alertable, Timeout*). */
static void bridge_NtWaitForSingleObject(void);
static void bridge_NtWaitForSingleObjectEx(void)
{
    uint32_t h = STACK_ARG(0), t = STACK_ARG(3);
    uint32_t s0 = STACK_ARG(0), s2 = STACK_ARG(2);
    /* present the 3-argument layout to the shared implementation */
    BRIDGE_MEM32(g_esp + 0) = h;
    BRIDGE_MEM32(g_esp + 8) = t;
    bridge_NtWaitForSingleObject();
    BRIDGE_MEM32(g_esp + 0) = s0;
    BRIDGE_MEM32(g_esp + 8) = s2;
}

/* ObReferenceObjectByName -> not found */
static void bridge_ObReferenceObjectByName(void) { g_eax = 0xC0000034u; }

/* RTL string helpers (guest ANSI_STRING / UNICODE_STRING: Length,
 * MaximumLength, Buffer). */
static void bridge_RtlAnsiStringToUnicodeString(void)
{
    uint32_t dst = STACK_ARG(0), src = STACK_ARG(1), alloc = STACK_ARG(2);
    uint16_t n = BRIDGE_MEM16(src);
    uint32_t sbuf = BRIDGE_MEM32(src + 4), dbuf;
    uint16_t i;
    if (alloc) {
        dbuf = xbox_HeapAlloc((uint32_t)n * 2 + 2, 4);
        if (!dbuf) { g_eax = 0xC0000017u; return; }
        BRIDGE_MEM32(dst + 4) = dbuf;
        BRIDGE_MEM16(dst + 2) = (uint16_t)(n * 2 + 2);
    } else {
        dbuf = BRIDGE_MEM32(dst + 4);
        if (BRIDGE_MEM16(dst + 2) < n * 2) { g_eax = 0x80000005u; return; }
    }
    for (i = 0; i < n; i++) BRIDGE_MEM16(dbuf + i * 2) = BRIDGE_MEM8(sbuf + i);
    if (BRIDGE_MEM16(dst + 2) >= n * 2 + 2) BRIDGE_MEM16(dbuf + n * 2) = 0;
    BRIDGE_MEM16(dst) = (uint16_t)(n * 2);
    g_eax = 0;
}
static void bridge_RtlUnicodeStringToAnsiString(void)
{
    uint32_t dst = STACK_ARG(0), src = STACK_ARG(1), alloc = STACK_ARG(2);
    uint16_t n = BRIDGE_MEM16(src) / 2;
    uint32_t sbuf = BRIDGE_MEM32(src + 4), dbuf;
    uint16_t i;
    if (alloc) {
        dbuf = xbox_HeapAlloc(n + 1u, 4);
        if (!dbuf) { g_eax = 0xC0000017u; return; }
        BRIDGE_MEM32(dst + 4) = dbuf;
        BRIDGE_MEM16(dst + 2) = (uint16_t)(n + 1);
    } else {
        dbuf = BRIDGE_MEM32(dst + 4);
        if (BRIDGE_MEM16(dst + 2) < n) { g_eax = 0x80000005u; return; }
    }
    for (i = 0; i < n; i++) BRIDGE_MEM8(dbuf + i) = (uint8_t)BRIDGE_MEM16(sbuf + i * 2);
    if (BRIDGE_MEM16(dst + 2) > n) BRIDGE_MEM8(dbuf + n) = 0;
    BRIDGE_MEM16(dst) = n;
    g_eax = 0;
}
/* RtlEqualString(String1, String2, CaseInSensitive) */
static void bridge_RtlEqualString(void)
{
    uint32_t a = STACK_ARG(0), b = STACK_ARG(1), ci = STACK_ARG(2) & 0xFF;
    uint16_t n = BRIDGE_MEM16(a), i;
    g_eax = 0;
    if (n != BRIDGE_MEM16(b)) return;
    for (i = 0; i < n; i++) {
        int x = BRIDGE_MEM8(BRIDGE_MEM32(a + 4) + i), y = BRIDGE_MEM8(BRIDGE_MEM32(b + 4) + i);
        if (ci) { if (x >= 'a' && x <= 'z') x -= 32; if (y >= 'a' && y <= 'z') y -= 32; }
        if (x != y) return;
    }
    g_eax = 1;
}
/* RtlCompareMemoryUlong(Source, Length, Pattern) -> bytes matching */
static void bridge_RtlCompareMemoryUlong(void)
{
    uint32_t src = STACK_ARG(0), len = STACK_ARG(1) & ~3u, pat = STACK_ARG(2), i;
    for (i = 0; i < len; i += 4) if (BRIDGE_MEM32(src + i) != pat) break;
    g_eax = i;
}
/* RtlTimeFieldsToTime / RtlTimeToTimeFields via the host SYSTEMTIME conversions. */
static void bridge_RtlTimeFieldsToTime(void)
{
    uint32_t tf = STACK_ARG(0), out = STACK_ARG(1);
    SYSTEMTIME st; FILETIME ft;
    st.wYear = BRIDGE_MEM16(tf); st.wMonth = BRIDGE_MEM16(tf + 2);
    st.wDay = BRIDGE_MEM16(tf + 4); st.wHour = BRIDGE_MEM16(tf + 6);
    st.wMinute = BRIDGE_MEM16(tf + 8); st.wSecond = BRIDGE_MEM16(tf + 10);
    st.wMilliseconds = BRIDGE_MEM16(tf + 12); st.wDayOfWeek = 0;
    if (!SystemTimeToFileTime(&st, &ft)) { g_eax = 0; return; }
    BRIDGE_MEM32(out) = ft.dwLowDateTime;
    BRIDGE_MEM32(out + 4) = ft.dwHighDateTime;
    g_eax = 1;
}
static void bridge_RtlTimeToTimeFields(void)
{
    uint32_t t = STACK_ARG(0), tf = STACK_ARG(1);
    FILETIME ft; SYSTEMTIME st;
    ft.dwLowDateTime = BRIDGE_MEM32(t); ft.dwHighDateTime = BRIDGE_MEM32(t + 4);
    if (!FileTimeToSystemTime(&ft, &st)) memset(&st, 0, sizeof st);
    BRIDGE_MEM16(tf) = st.wYear; BRIDGE_MEM16(tf + 2) = st.wMonth;
    BRIDGE_MEM16(tf + 4) = st.wDay; BRIDGE_MEM16(tf + 6) = st.wHour;
    BRIDGE_MEM16(tf + 8) = st.wMinute; BRIDGE_MEM16(tf + 10) = st.wSecond;
    BRIDGE_MEM16(tf + 12) = st.wMilliseconds; BRIDGE_MEM16(tf + 14) = st.wDayOfWeek;
}

/* Xc* crypto: the host implementations in kernel_crypto.c on guest buffers. */
static void bridge_XcSHAInit(void)   { xbox_XcSHAInit(XBOX_TO_NATIVE(STACK_ARG(0))); }
static void bridge_XcSHAUpdate(void)
{
    xbox_XcSHAUpdate(XBOX_TO_NATIVE(STACK_ARG(0)), XBOX_TO_NATIVE(STACK_ARG(1)), STACK_ARG(2));
}
static void bridge_XcSHAFinal(void)
{
    xbox_XcSHAFinal(XBOX_TO_NATIVE(STACK_ARG(0)), XBOX_TO_NATIVE(STACK_ARG(1)));
}
static void bridge_XcRC4Key(void)
{
    xbox_XcRC4Key(XBOX_TO_NATIVE(STACK_ARG(0)), STACK_ARG(1), XBOX_TO_NATIVE(STACK_ARG(2)));
}
static void bridge_XcRC4Crypt(void)
{
    xbox_XcRC4Crypt(XBOX_TO_NATIVE(STACK_ARG(0)), STACK_ARG(1), XBOX_TO_NATIVE(STACK_ARG(2)));
}
static void bridge_XcHMAC(void)
{
    xbox_XcHMAC(XBOX_TO_NATIVE(STACK_ARG(0)), STACK_ARG(1),
                XBOX_TO_NATIVE(STACK_ARG(2)), STACK_ARG(3),
                XBOX_TO_NATIVE(STACK_ARG(4)), STACK_ARG(5),
                XBOX_TO_NATIVE(STACK_ARG(6)));
}

/* ── Ordinal tables ─────────────────────────────────────────────────── */

static const xbox_kernel_export *kernel_export(ULONG ordinal)
{
    size_t i;
    for (i = 0; i < XBOX_KERNEL_EXPORT_COUNT; i++)
        if (g_xbox_kernel_exports[i].ordinal == ordinal) return &g_xbox_kernel_exports[i];
    return NULL;
}

/* Stack bytes the callee pops (stdcall N, fastcall N-8, cdecl 0). */
static int stdcall_args_for_ordinal(ULONG ordinal)
{
    const xbox_kernel_export *e = kernel_export(ordinal);
    return e ? e->stack_bytes : 0;
}

/* Data exports: guest address of the variable the thunk entry points at. */
static uint32_t kernel_data_va_for_ordinal(ULONG ordinal)
{
    switch (ordinal) {
    case  16: return XBOX_KERNEL_DATA_BASE + KDATA_EVENT_OBJ_TYPE;       /* ExEventObjectType */
    case  40: return XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_PARTCOUNT;   /* HalDiskCachePartitionCount */
    case  41: return XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_MODEL;       /* HalDiskModelNumber */
    case  42: return XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_SERIAL;      /* HalDiskSerialNumber */
    case  64: return XBOX_KERNEL_DATA_BASE + KDATA_IO_COMPLETION_TYPE;   /* IoCompletionObjectType */
    case  70: return XBOX_KERNEL_DATA_BASE + KDATA_IO_DEVICE_TYPE;       /* IoDeviceObjectType */
    case 156: return XBOX_KERNEL_DATA_BASE + KDATA_TICK_COUNT;           /* KeTickCount */
    case 164: return XBOX_KERNEL_DATA_BASE + KDATA_LAUNCH_DATA_PAGE;     /* LaunchDataPage */
    case 259: return XBOX_KERNEL_DATA_BASE + KDATA_THREAD_OBJ_TYPE;      /* PsThreadObjectType */
    case 322: return XBOX_KERNEL_DATA_BASE + KDATA_HARDWARE_INFO;        /* XboxHardwareInfo */
    case 323: return XBOX_KERNEL_DATA_BASE + KDATA_HD_KEY;               /* XboxHDKey */
    case 324: return XBOX_KERNEL_DATA_BASE + KDATA_KRNL_VERSION;         /* XboxKrnlVersion */
    case 325: return XBOX_KERNEL_DATA_BASE + KDATA_SIGNATURE_KEY;        /* XboxSignatureKey */
    case 326: return XBOX_KERNEL_DATA_BASE + KDATA_XE_IMAGE_FILENAME;    /* XeImageFileName */
    case 353: return XBOX_KERNEL_DATA_BASE + KDATA_LAN_KEY;              /* XboxLANKey */
    case 354: return XBOX_KERNEL_DATA_BASE + KDATA_ALT_SIGNATURE_KEYS;   /* XboxAlternateSignatureKeys */
    case 355: return XBOX_KERNEL_DATA_BASE + KDATA_XE_PUBLIC_KEY;        /* XePublicKeyData */
    case 356: return XBOX_KERNEL_DATA_BASE + KDATA_SMC_VIDEO_MODE;       /* HalBootSMCVideoMode */
    case 357: return XBOX_KERNEL_DATA_BASE + KDATA_IDEX_CHANNEL;         /* IdexChannelObject */
    default:  return 0;
    }
}

static bridge_func_t bridge_for_ordinal(ULONG ordinal)
{
    switch (ordinal) {
    case   1: return bridge_return_zero;              /* AvGetSavedDataAddress */
    case   2: return bridge_AvSendTVEncoderOption;
    case   3: return bridge_AvSetDisplayMode;
    case   4: return bridge_void;                     /* AvSetSavedDataAddress */
    case   5: return bridge_DbgBreakPoint;
    case   8: return bridge_DbgPrint;
    case  14: return bridge_ExAllocatePool;
    case  15: return bridge_ExAllocatePoolWithTag;
    case  17: return bridge_ExFreePool;
    case  23: return bridge_return_zero;              /* ExQueryPoolBlockSize */
    case  24: return bridge_ExQueryNonVolatileSetting;
    case  44: return bridge_HalGetInterruptVector_44;
    case  46: return bridge_HalReadWritePCISpace;
    case  47: return bridge_HalRegisterShutdownNotification;
    case  49: return bridge_HalReturnToFirmware;
    case  62: return bridge_return_zero;              /* IoBuildSynchronousFsdRequest: no IRP */
    case  65: return bridge_IoCreateDevice;
    case  66: return bridge_IoCreateFile;
    case  67: return bridge_IoCreateSymbolicLink;
    case  69: return bridge_return_zero;              /* IoDeleteSymbolicLink */
    case  74: return bridge_status_unsuccessful;      /* IoInvalidDeviceRequest */
    case  81: case 82: case 83: return bridge_void;   /* IoStartNextPacket[ByKey], IoStartPacket */
    case  84: return bridge_status_unsuccessful;      /* IoSynchronousDeviceIoControlRequest */
    case  85: return bridge_status_unsuccessful;      /* IoSynchronousFsdRequest */
    case  86: return bridge_status_unsuccessful;      /* IofCallDriver */
    case  87: return bridge_void;                     /* IofCompleteRequest */
    case  91: return bridge_return_zero;              /* IoDismountVolumeByName */
    case  95: return bridge_KeBugCheck;
    case  97: return bridge_return_zero;              /* KeCancelTimer -> was not queued */
    case  98: return bridge_KeConnectInterrupt_98;
    case  99: return bridge_KeDelayExecutionThread;
    case 100: return bridge_return_true;              /* KeDisconnectInterrupt */
    case 107: return bridge_KeInitializeDpc;
    case 109: return bridge_KeInitializeInterrupt;
    case 113: return bridge_KeInitializeTimerEx;
    case 119: return bridge_KeInsertQueueDpc;
    case 124: return bridge_return_zero;              /* KeQueryBasePriorityThread */
    case 126: return bridge_KeQueryPerformanceCounter;
    case 127: return bridge_KeQueryPerformanceFrequency;
    case 128: return bridge_KeQuerySystemTime;
    case 129: return bridge_KeRaiseIrqlToDpcLevel;
    case 137: return bridge_return_zero;              /* KeRemoveQueueDpc */
    case 139: case 142: return bridge_return_zero;    /* Ke{Restore,Save}FloatingPointState */
    case 143: case 144: return bridge_return_zero;    /* KeSetBasePriorityThread, KeSetDisableBoostThread */
    case 145: return bridge_KeSetEvent;
    case 149: return bridge_KeSetTimer;
    case 150: return bridge_KeSetTimer;               /* KeSetTimerEx */
    case 151: return bridge_KeStallExecutionProcessor;
    case 153: return bridge_KeSynchronizeExecution;
    case 158: return bridge_KeWaitForMultipleObjects;
    case 159: return bridge_KeWaitForSingleObject;
    case 160: return bridge_KfRaiseIrql;
    case 161: return bridge_KfLowerIrql;
    case 165: return bridge_MmAllocateContiguousMemory;
    case 166: return bridge_MmAllocateContiguousMemoryEx;
    case 167: return bridge_MmAllocateSystemMemory;
    case 168: return bridge_MmClaimGpuInstanceMemory;
    case 169: return bridge_MmCreateKernelStack;
    case 170: return bridge_void;                     /* MmDeleteKernelStack */
    case 171: return bridge_MmFreeContiguousMemory;
    case 172: return bridge_MmFreeSystemMemory;
    case 173: return bridge_MmGetPhysicalAddress;
    case 175: case 176: return bridge_void;           /* MmLockUnlock{BufferPages,PhysicalPage} */
    case 177: return bridge_MmMapIoSpace;
    case 178: return bridge_MmPersistContiguousMemory;
    case 179: return bridge_MmQueryAddressProtect;
    case 180: return bridge_return_zero;              /* MmQueryAllocationSize */
    case 181: return bridge_MmQueryStatistics;
    case 182: return bridge_MmSetAddressProtect;
    case 184: return bridge_NtAllocateVirtualMemory;
    case 187: return bridge_NtClose;
    case 188: return bridge_NtCreateDirectoryObject;
    case 189: return bridge_NtCreateEvent;
    case 190: return bridge_NtCreateFile;
    case 195: return bridge_NtDeleteFile;
    case 196: return bridge_NtDeviceIoControlFile;
    case 197: return bridge_NtDuplicateObject;
    case 198: return bridge_NtFlushBuffersFile;
    case 199: return bridge_NtFreeVirtualMemory;
    case 200: return bridge_NtFsControlFile;
    case 202: return bridge_NtOpenFile;
    case 203: return bridge_NtOpenSymbolicLinkObject;
    case 207: return bridge_NtQueryDirectoryFile;
    case 210: return bridge_NtQueryFullAttributesFile;
    case 211: return bridge_NtQueryInformationFile;
    case 215: return bridge_NtQuerySymbolicLinkObject;
    case 217: return bridge_NtQueryVirtualMemory;
    case 218: return bridge_NtQueryVolumeInformationFile;
    case 219: return bridge_NtReadFile;
    case 224: return bridge_NtResumeThread;
    case 225: return bridge_NtSetEvent;
    case 226: return bridge_NtSetInformationFile;
    case 228: return bridge_return_zero;              /* NtSetSystemTime */
    case 231: return bridge_NtSuspendThread;
    case 233: return bridge_NtWaitForSingleObject;
    case 234: return bridge_NtWaitForSingleObjectEx;
    case 236: return bridge_NtWriteFile;
    case 238: return bridge_NtYieldExecution;
    case 246: return bridge_ObReferenceObjectByHandle;
    case 247: return bridge_ObReferenceObjectByName;
    case 250: return bridge_ObfDereferenceObject;
    case 252: return bridge_return_zero;              /* PhyGetLinkState: no link */
    case 253: return bridge_return_zero;              /* PhyInitialize */
    case 255: return bridge_PsCreateSystemThreadEx;
    case 258: return bridge_PsTerminateSystemThread;
    case 260: return bridge_RtlAnsiStringToUnicodeString;
    case 269: return bridge_RtlCompareMemoryUlong;
    case 277: return bridge_RtlEnterCriticalSection;
    case 279: return bridge_RtlEqualString;
    case 289: return bridge_RtlInitAnsiString;
    case 291: return bridge_RtlInitializeCriticalSection;
    case 294: return bridge_RtlLeaveCriticalSection;
    case 301: return bridge_RtlNtStatusToDosError;
    case 302: return bridge_RtlRaiseException;
    case 304: return bridge_RtlTimeFieldsToTime;
    case 305: return bridge_RtlTimeToTimeFields;
    case 308: return bridge_RtlUnicodeStringToAnsiString;
    case 312: return bridge_void;                     /* RtlUnwind */
    case 335: return bridge_XcSHAInit;
    case 336: return bridge_XcSHAUpdate;
    case 337: return bridge_XcSHAFinal;
    case 338: return bridge_XcRC4Key;
    case 339: return bridge_XcRC4Crypt;
    case 340: return bridge_XcHMAC;
    case 344: return bridge_return_true;              /* XcVerifyPKCS1Signature */
    case 345: case 346: case 347: case 349: return bridge_return_zero;  /* XcModExp, XcDESKeyParity, XcKeyTable, XcBlockCryptCBC */
    case 358: return bridge_return_zero;              /* HalIsResetOrShutdownPending */
    case 359: return bridge_void;                     /* IoMarkIrpMustComplete */
    case 360: return bridge_HalReturnToFirmware;      /* HalInitiateShutdown */
    default:  return NULL;
    }
}
