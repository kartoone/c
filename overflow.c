#include <stdio.h>

int main() {
  //unsigned char num1 = 0b11111111; // maximum positive char
  unsigned char num1 = 255;
  printf("%d\n",num1); // no overflow 
  
  char num1_overflow = 255;
  printf("%d\n",num1_overflow); // we can't represent postive 255 using a single signed byte. C interprets as a two's complement byte, so it displays -1 

  unsigned char num2 = 0b1;
  unsigned char result1_overflow = num1 + num2; // when we add 1 to 255, we get 256, which is 0b100000000 (NINE bits, the extra 1 is thrown away yielding 0 for the result)
  printf("%d + %d = %d\n", num1, num2, result1_overflow);

  char num3 = 127;                      // largest possible POSITIVE integer using 8 bits 0b01111111
  char num4 = 1;                        // doesn't take much to overflow since it was already the largest positive integer!!!
  char result2_overflow = num3 + num4;  // 127 + 1 = 128 which in binary is a 0b10000000, which is a NEGATIVE number in two's complement ... so overflow has happened!
  printf("%d + %d = %d\n", num3, num4, result2);

  // same as earlier examples but using 4 bytes (int) instead of 1 byte (char)
  unsigned int i1 = 0xffffffff;
  printf("%d\n", i1);
  
  int i1_overflow = 0xffffffff;
  prtinf("%d\n", i1_overflow);
  
  unsigned int i2 = 1;
  unsigned int resulti1_overflow = i1 + i2;
  printf("%d + %d = %d\n", i1, i2, resulti1_overflow);

  int i3 = 0x7fffffff; // 0b01111111111111111111111111111111
  int i4 = 1;
  int resulti2_overflow = i3 + i4;  // 2147483648 which is equal to 0b10000000000000000000000000000000 (which is NEGATIVE 2147483648)
  printf("%d + %d = %d\n", i3, i4, resulti2_overflow); // overflow has happened b/c we added two positive numbers and got a negative
  return 0;
}
