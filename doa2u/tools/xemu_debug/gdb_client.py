"""
Minimal GDB Remote Serial Protocol client for xemu.

Connects to xemu's GDB stub (started with -s flag, default port 1234)
and provides memory read/write, register access, and breakpoint control.

Usage:
    client = GDBClient('localhost', 1234)
    client.connect()
    data = client.read_memory(0x557880, 0x200)
    regs = client.read_registers()
    client.set_breakpoint(0x000636D0)
    client.continue_execution()
"""

import socket
import struct
import time
from typing import Optional


class GDBClient:
    """GDB Remote Serial Protocol client for xemu."""

    def __init__(self, host: str = 'localhost', port: int = 1234):
        self.host = host
        self.port = port
        self.sock: Optional[socket.socket] = None

    def connect(self):
        """Connect to the GDB stub."""
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.settimeout(10.0)
        self.sock.connect((self.host, self.port))
        # Read initial '+' ack if any
        try:
            self.sock.settimeout(0.5)
            self.sock.recv(1)
        except socket.timeout:
            pass
        self.sock.settimeout(10.0)
        print(f"Connected to GDB stub at {self.host}:{self.port}")

    def disconnect(self):
        """Disconnect from the GDB stub."""
        if self.sock:
            self.sock.close()
            self.sock = None

    def _checksum(self, data: str) -> str:
        """Compute GDB RSP checksum."""
        return f"{sum(ord(c) for c in data) & 0xFF:02x}"

    def _send_packet(self, data: str) -> str:
        """Send a GDB RSP packet and return the response."""
        packet = f"${data}#{self._checksum(data)}"
        self.sock.sendall(packet.encode('ascii'))

        # Read response
        response = b''
        while True:
            chunk = self.sock.recv(4096)
            if not chunk:
                break
            response += chunk
            # Check if we have a complete packet
            if b'#' in response:
                # Find the end: $data#xx
                try:
                    resp_str = response.decode('ascii')
                    # Skip any '+' acks
                    while resp_str.startswith('+'):
                        resp_str = resp_str[1:]
                    if resp_str.startswith('$') and '#' in resp_str:
                        end = resp_str.index('#')
                        payload = resp_str[1:end]
                        # Send ack
                        self.sock.sendall(b'+')
                        return payload
                except (ValueError, UnicodeDecodeError):
                    pass

        return ''

    def _send_packet_raw(self, data: str):
        """Send packet without waiting for full response (for async commands)."""
        packet = f"${data}#{self._checksum(data)}"
        self.sock.sendall(packet.encode('ascii'))

    def read_memory(self, addr: int, length: int) -> bytes:
        """Read memory from the guest. Returns raw bytes."""
        result = b''
        # GDB has a packet size limit, read in chunks
        chunk_size = 512
        offset = 0
        while offset < length:
            n = min(chunk_size, length - offset)
            resp = self._send_packet(f"m{addr + offset:x},{n:x}")
            if resp.startswith('E') or not resp:
                # Error or empty - fill with zeros
                result += b'\x00' * n
            else:
                # Decode hex pairs
                try:
                    result += bytes.fromhex(resp)
                except ValueError:
                    result += b'\x00' * n
            offset += n
        return result

    def read_u32(self, addr: int) -> int:
        """Read a 32-bit unsigned integer from guest memory."""
        data = self.read_memory(addr, 4)
        return struct.unpack('<I', data)[0]

    def read_f32(self, addr: int) -> float:
        """Read a 32-bit float from guest memory."""
        data = self.read_memory(addr, 4)
        return struct.unpack('<f', data)[0]

    def read_registers(self) -> dict:
        """Read all x86 registers. Returns dict of name->value."""
        resp = self._send_packet('g')
        if not resp or resp.startswith('E'):
            return {}

        # QEMU i386 register order (32-bit values as 8 hex chars, little-endian):
        # eax, ecx, edx, ebx, esp, ebp, esi, edi, eip, eflags, cs, ss, ds, es, fs, gs
        reg_names = ['eax', 'ecx', 'edx', 'ebx', 'esp', 'ebp', 'esi', 'edi',
                     'eip', 'eflags', 'cs', 'ss', 'ds', 'es', 'fs', 'gs']
        regs = {}
        for i, name in enumerate(reg_names):
            start = i * 8
            end = start + 8
            if end <= len(resp):
                # GDB sends registers in target byte order (little-endian for x86)
                hex_val = resp[start:end]
                # Swap byte pairs for little-endian
                val = int.from_bytes(bytes.fromhex(hex_val), 'little')
                regs[name] = val
        return regs

    def write_memory(self, addr: int, data: bytes):
        """Write bytes to guest memory."""
        hex_data = data.hex()
        resp = self._send_packet(f"M{addr:x},{len(data):x}:{hex_data}")
        return resp == 'OK'

    def set_breakpoint(self, addr: int) -> bool:
        """Set a software breakpoint at addr."""
        resp = self._send_packet(f"Z0,{addr:x},1")
        return resp == 'OK'

    def remove_breakpoint(self, addr: int) -> bool:
        """Remove a software breakpoint at addr."""
        resp = self._send_packet(f"z0,{addr:x},1")
        return resp == 'OK'

    def set_watchpoint(self, addr: int, length: int = 4, write_only: bool = True) -> bool:
        """Set a hardware watchpoint (write or read/write)."""
        wp_type = 2 if write_only else 3  # 2=write, 3=read/write, 4=read
        resp = self._send_packet(f"Z{wp_type},{addr:x},{length:x}")
        return resp == 'OK'

    def continue_execution(self):
        """Continue guest execution (non-blocking)."""
        self._send_packet_raw('c')

    def single_step(self) -> dict:
        """Execute one instruction and return registers."""
        resp = self._send_packet('s')
        return self.read_registers()

    def halt(self):
        """Send break/interrupt to halt the guest."""
        self.sock.sendall(b'\x03')
        # Read the stop reply
        time.sleep(0.1)
        try:
            self.sock.recv(4096)
        except socket.timeout:
            pass

    def wait_for_stop(self, timeout: float = 30.0) -> str:
        """Wait for guest to stop (breakpoint hit, etc). Returns stop reason."""
        self.sock.settimeout(timeout)
        try:
            response = b''
            while True:
                chunk = self.sock.recv(4096)
                response += chunk
                resp_str = response.decode('ascii', errors='replace')
                if '$' in resp_str and '#' in resp_str:
                    start = resp_str.index('$') + 1
                    end = resp_str.index('#')
                    payload = resp_str[start:end]
                    self.sock.sendall(b'+')
                    return payload
        except socket.timeout:
            return 'timeout'
        finally:
            self.sock.settimeout(10.0)
