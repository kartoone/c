#include <stdio.h>

int main() {
  char num1 = 127;
  char num2 = 5;
  char result1 = num1 + num2;
  printf("%d + %d = %d\n", num1, num2, result1);

  char num3 = 127;                      // largest possible positive integer using 8 bits
  unsigned char num4 = 129;             // we have to switch to unsigned to represent 129
  unsigned char result2 = num3 + num4;   // 127 + 129 = 256 which in binary is a 1 followed by 8 zeros. Since the result is only a single byte, the extra bit is thrown away leaving 0 as the result
  printf("%d + %d = %d\n", num3, num4, result2);

  // same as earlier examples but using 4 bytes (int) instead of 1 byte (char)
  int i1 = 0x7fffffff;
  int i2 = 5;
  int resulti1 = i1 + i2;
  printf("%d + %d = %d\n", i1, i2, resulti1);

  int i3 = 0x7fffffff; // 0b0111111111111111
  unsigned int i4 = 0x7fffffffu + 2u; //2147483649
  int resulti2 = i3 + i4;
  printf("%d + %d = %d\n", i3, i4, resulti2);
  return 0;
}
