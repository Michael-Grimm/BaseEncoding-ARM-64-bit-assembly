/**
 * int count_chars(unsigned long long val, int base);
 * Returns the number of necessary ascii characters for representing val in the 
 * given base (radix).
 * Examples: 0xFFFF = 65535 in decimal => 5 chars.
 *           0x177  = 567   in octal   => 3 chars
 *           0xabbafefedeadcafe = 12374483296764939006 => 20 chars.
 */
int count_chars(unsigned long long val, int base);

/**
 * int count_decimals(unsigned long long val);
 * Returns the number of decimal characters for val.
 * Example: 0xFFFF = 65535 in decimal => 5 chars.
 * 0xabbafefedeadcafe = 12374483296764939006 => 20 chars.
 */
int count_decimals(unsigned long long val); 

/**
 * int encode(long long value, int base, char *buf);
 * writes the value as ascii string in the given base (radix) into buf.
 * base can have a value between 2 and 85.
 * buf must have a proper length to accommodate the ascii-string (plus a 
 * terminating zero if needed):
 * For the maximum of long long:
 * Base 2: 64 bytes  "111111111111111111111111111111111111111111111111111111111111"
 * Base 8: 22 bytes  "1777777777777777777777"
 * Base 10: 20 bytes "18446744073709551615"
 * Base 16: 16 bytes "FFFFFFFFFFFFFFFF"
 * Base 32 ext hex: 13 bytes "FVVVVVVVVVVVV"
 * Base 85: 10 bytes "_sw2=@*|O0" 
 * See also: int count_chars(long long val, int base);
 * This function uses the Base 85 alphabet (RFC 1924) which includes the 
 * base32hex (base 32 extended hex) alphabet (RFC 2938):   
 * 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~
 * Returns the number of characters written to buf.
 */
 int encode(unsigned long long value, int base, char *buf);
 
/**
 * int encode_dec(long long value, char *buf);
 * writes the value as decimal string into buf.
 * see: int encode(long long value, int base, char *buf);
 */
int encode_dec(unsigned long long value, char *buf); 

/**
 * int encode_hex(long long value, char *buf);
 * writes the value as hexadecimal string into buf.
 * see: int encode(long long value, int base, char *buf);
 */
int encode_hex(unsigned long long value, char *buf); 

/**
 * int asciiz_length(char *array)
 * The function asciiz_length
 * determines the length of a zero terminated char-array.
 * Input: address of char-array
 * Returns the length of the string excluding the terminating zero.
 */
int asciiz_length(char *array);
 
