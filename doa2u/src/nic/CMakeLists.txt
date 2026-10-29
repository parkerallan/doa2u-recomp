# nForce NIC emulation: the MMIO registers, descriptor rings and IRQ 4 XNET's driver uses,
# and libslirp (MSYS2 MinGW build, third_party/libslirp) as the host network.

set(SLIRP_DIR ${CMAKE_SOURCE_DIR}/third_party/libslirp)

add_library(nic_emu STATIC
    nic.c
    nic_net.c
)

target_include_directories(nic_emu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nic_emu PRIVATE ${SLIRP_DIR}/include)
target_link_libraries(nic_emu PRIVATE xbox_kernel)

# libslirp and its glib runtime load on the first transmitted frame: DLLs linked at
# startup shift the address space the guest memory needs (see input/CMakeLists.txt).
target_link_libraries(nic_emu PUBLIC ${SLIRP_DIR}/lib/libslirp-0.lib ws2_32 iphlpapi winhttp delayimp)
target_link_options(nic_emu INTERFACE /DELAYLOAD:libslirp-0.dll)

if(MSVC)
    target_compile_options(nic_emu PRIVATE /W3)
endif()

# The DLLs ship next to DOA2U.exe.
set(NIC_RUNTIME_DLLS
    ${SLIRP_DIR}/bin/libslirp-0.dll
    ${SLIRP_DIR}/bin/libglib-2.0-0.dll
    ${SLIRP_DIR}/bin/libintl-8.dll
    ${SLIRP_DIR}/bin/libiconv-2.dll
    ${SLIRP_DIR}/bin/libpcre2-8-0.dll
    PARENT_SCOPE)
