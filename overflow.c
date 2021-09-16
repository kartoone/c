#include <stdio.h>

int main() {
  char num1 = 127;
  unsigned char num2 = 129;
  unsigned char result = num1 + num2;
  printf("%d + %d = %d\n", num1, num2, result);

  int i1 = 0x7fffffff; // 0b0111111111111111
  unsigned int i2 = 0x7fffffffu + 2u; //2147483649
  int resulti = i1 + i2;
  printf("%d + %d = %d\n", i1, i2, resulti);
  return 0;
}
