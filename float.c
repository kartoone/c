#include <stdio.h>
#include <stdlib.h>

int main() {
  float f1 = 3.75f;
  float f2 = 0b01000000011100000000000000000000;  // 11.11
  float f3 = 0x40700000;
  float f4 = 0x00007040;
                       // 1.111 x 2^1
                       // 128
  printf("%f\n", f1);
  printf("%f\n", f2);
  printf("%f\n", f3);
  printf("%f\n", f4);
  return 0;
}
