#include <stdio.h>
#include <stdlib.h>

int main() {
  char num1 = 0x4b;       // represents 75 using 1 byte
  char num2 = 0xb5;       // represents -75 using 1 byte
  printf("%d %d\n", num1, num2);
  int num3 = 0x4b;        // represents 75 using 4 bytes
  int num4 = 0xffffffb5;  // -75 using 4 bytes ... note that we need to sign extends the "1s" all the way out to take up all 4 bytes required of an integer
  printf("%d %d\n", num3, num4);
}
