# BaseEncoding-ARM-64-bit-assembly
ARM-64 assembly implementation of encoding/decoding  64-bit integers (unsigned long long int) from/to zero-terminated ASCII strings for a given base (base 2 ... base 85)

Uses the Base 85 alphabet (RFC 1924) which includes the base32hex (base 32 extended hexadecimal) alphabet (RFC 2938):   

**0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~**

Base 16: Hexadecimal characters above 9 are always expected in upper case.


Programmed on a RaspberryPi 4 (Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.5GHz) with  Ubuntu Mate linux.
