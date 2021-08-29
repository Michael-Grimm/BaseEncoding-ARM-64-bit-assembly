#include "../base_encoding.h"
#include "test.h"


void test_asciiz_length_1(){
       char arr[] = "abcde\0";
       int len = asciiz_length(arr);
       int exp_len = 5;
       TEST_INT_EQUALS(exp_len,len)
}

void test_asciiz_length_2(){
       char arr[20] = {0};
       int len = asciiz_length(arr);
       int exp_len = 0;
       TEST_INT_EQUALS(exp_len,len)
}
  
void test_asciiz_length_3(){
       char arr[20] = {97, 98, 99, 0};
       int len = asciiz_length(arr);
       int exp_len = 3;
       TEST_INT_EQUALS(exp_len,len)
}

void test_asciiz_length_4(){
       char arr[] = {97, 98, 99, 100, 101, 102, 103, 104, 0};
       int len = asciiz_length(arr);
       int exp_len = 8;
       TEST_INT_EQUALS(exp_len,len)
}


void test_asciiz_length_5(){
       char arr[] = "abcdefghijk\0lmnopqrstuvw\0";
       int len = asciiz_length(arr);
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len,len)
}

void test_asciiz_length_6(){
       char arr[] = "a\0bcdefghijk\0lmnopqrstuvw\0";
       int len = asciiz_length(arr);
       int exp_len = 1;
       TEST_INT_EQUALS(exp_len,len)
}

void test_asciiz_length_7(){
       char arr[] = "abcdefghijk\0lmnopqrstuvw";
       arr[0] = 0;
       int len = asciiz_length(arr);
       int exp_len = 0;
       TEST_INT_EQUALS(exp_len,len)
}

void test_asciiz_length_8(){
       char arr[] = "abcdefghijk\0";
       arr[5] = 0;
       int len = asciiz_length(arr);
       int exp_len = 5;
       TEST_INT_EQUALS(exp_len,len)

}

void test_asciiz_length_9(){
       char arr[] = "abcdefghijk";
       int len = asciiz_length(arr);
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len,len)

}

void test_asciiz_length_10(){
       int len = asciiz_length("abcdefghijk");
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len,len)
}

void test_count_decimals_1(){
	   long long val = 0xabbafefedeadcafe; // = dec 12374483296764939006 => 20 chars.
       int len = count_decimals(val);
       int exp_len = 20;
       TEST_INT_EQUALS(exp_len,len)
}

void test_count_decimals_2(){
	   long long val = 1237448390 ;
       int exp_len = 10;
       int len = count_decimals(val);
       TEST_INT_EQUALS(exp_len,len)
}

void test_count_decimals_3(){
	   long long val = 0xffffffffffffffff; //= dec 18446744073709551615 => 20 chars.
       int len = count_decimals(val);
       int exp_len = 20;
       TEST_INT_EQUALS(exp_len,len)

}

void test_count_decimals_4(){
	   long long val = 8446744073709551615; //=> 19 chars.
       int len = count_decimals(val);
       int exp_len = 19;
       TEST_INT_EQUALS(exp_len,len)

}

void test_count_decimals_5(){
	   long long val = 2000; //=> 4 chars.
       int len = count_decimals(val);
       int exp_len = 4;
       TEST_INT_EQUALS(exp_len,len)

}

void test_count_decimals_6(){
	   long long val = 123456789; //=> 9 chars.
       int len = count_decimals(val);
       int exp_len = 9;
       TEST_INT_EQUALS(exp_len,len)


}

void test_count_decimals_7(){
	   long long val = 0; //=> 1 chars.
       int len = count_decimals(val);
       int exp_len = 1;
       TEST_INT_EQUALS(exp_len,len)

}

void test_count_decimals_8(){
	   long long val = 123456789012345; //=> 15 chars.
       int len = count_decimals(val);
       int exp_len = 15;
       TEST_INT_EQUALS(exp_len,len)


}

void test_encode_dec_1(){
	   long long val = 123456789012345; //=> 15 chars.
	   char exp_str[] = "123456789012345";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =15;
     TEST_STRING_EQUALS(exp_str, buf)
     TEST_INT_EQUALS(exp_len,len)

}


void test_encode_dec_2(){
	   long long val = 0xabbafefedeadcafe;  
	   char exp_str[] = "12374483296764939006";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =20;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)


}

void test_encode_dec_3(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "18446744073709551615";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =20;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)


}

void test_encode_dec_4(){
	   long long val = 0x64;   
	   char exp_str[] = "100";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =3;
     TEST_STRING_EQUALS(exp_str, buf)
     TEST_INT_EQUALS(exp_len,len)

}

void test_encode_dec_5(){
	   long long val = 0;   
	   char exp_str[] = "0";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =1;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_dec_6(){
	   long long val = 1;   
	   char exp_str[] = "1";
       char buf[21] = {0};
       int len = encode_dec(val, buf);
       int exp_len =1;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base16_1(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "FFFFFFFFFFFFFFFF";
       char buf[17] = {0};
       int base = 16;
       int len = encode(val, base, buf);
       int exp_len =16;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base16_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "ABBADEADBABECAFE";
       char buf[17] = {0};
       int base = 16;
       int len = encode(val, base, buf);
       int exp_len =16;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base16_3(){
	   long long val = 0xCAFE;   
	   char exp_str[] = "CAFE";
       char buf[5] = {0};
       int base = 16;
       int len = encode(val, base, buf);
       int exp_len =4;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}



void test_encode_hex_1(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "FFFFFFFFFFFFFFFF";
       char buf[17] = {0};
       int len = encode_hex(val, buf);
       int exp_len =16;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_hex_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "ABBADEADBABECAFE";
       char buf[17] = {0};
       int len = encode_hex(val, buf);
       int exp_len =16;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_hex_3(){
	   long long val = 0xCAFE;   
	   char exp_str[] = "CAFE";
       char buf[5] = {0};
       int len = encode_hex(val, buf);
       int exp_len =4;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}
void test_encode_base10(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "18446744073709551615";
       char buf[21] = {0};
       int base = 10;
       int len = encode(val, base, buf);
       int exp_len =20;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}


void test_encode_base8(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "1777777777777777777777";
       char buf[23] = {0};
       int base = 8;
       int len = encode(val, base, buf);
       int exp_len =22;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base4(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "33333333333333333333333333333333";
       char buf[33] = {0};
       int base = 4;
       int len = encode(val, base, buf);
       int exp_len =32;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base3(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "11112220022122120101211020120210210211220";
       char buf[42] = {0};
       int base = 3;
       int len = encode(val, base, buf);
       int exp_len =41;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base2(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "1111111111111111111111111111111111111111111111111111111111111111";
       char buf[65] = {0};
       int base = 2;
       int len = encode(val, base, buf);
       int exp_len =64;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}


void test_encode_base32_ext_hex_alphabet(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "FVVVVVVVVVVVV";
       char buf[14] = {0};
       int base = 32;
       int len = encode(val, base, buf);
       int exp_len =13;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}


void test_encode_base32_ext_hex_alphabet_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "ANEMULMTBTINU";
       char buf[14] = {0};
       int base = 32;
       int len = encode(val, base, buf);
       int exp_len = 13;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)

}

void test_encode_base85_1(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "_sw2=@*|O0";
       char buf[11] = {0};
       int base = 85;
       int len = encode(val, base, buf);
       int exp_len = 10;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)
}

void test_encode_base85_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "raKVdv(}ws";
       char buf[11] = {0};
       int base = 85;
       int len = encode(val, base, buf);
       int exp_len = 10;
       TEST_STRING_EQUALS(exp_str, buf)
       TEST_INT_EQUALS(exp_len,len)
}


int test_all(){
	test_asciiz_length_1();
	test_asciiz_length_2();
	test_asciiz_length_3();
	test_asciiz_length_4();
	test_asciiz_length_5();
	test_asciiz_length_6();
	test_asciiz_length_7();
	test_asciiz_length_8();
	test_asciiz_length_9();
	test_asciiz_length_10();
	test_count_decimals_1();
	test_count_decimals_2();
	test_count_decimals_3();
	test_count_decimals_4();
	test_count_decimals_5();
	test_count_decimals_6();
	test_count_decimals_7();
	test_count_decimals_8();
	test_encode_dec_1();
	test_encode_dec_2();
	test_encode_dec_3();
	test_encode_dec_4();
	test_encode_dec_5();
	test_encode_dec_6();
	test_encode_hex_1();
	test_encode_hex_2();
	test_encode_hex_3();	
	test_encode_base16_1();
	test_encode_base16_2();
	test_encode_base16_3();
	test_encode_base10();
	test_encode_base8();
	test_encode_base4();
	test_encode_base3();
	test_encode_base2();
	test_encode_base32_ext_hex_alphabet();
	test_encode_base32_ext_hex_alphabet_2();
	test_encode_base85_1();
	test_encode_base85_2();
}

int main(){
      printf("\nTesting file %s:\n", __FILE__);
      PRINT_TEST_FUNCTIONS
      test_all();    
      PRINT_TEST_RESULTS
}










