#include <stdio.h>
#include <stdlib.h>

int main() {
  float f1 = 128.75f;

  int f2 = 0x00c00043;  // note we have to use little endian format here

  // or we can manipulate the bytes directly as shown below
  char* f3 = malloc(sizeof(float));
  *f3 = 0x00;
  *(f3+1) = 0xc0;
  *(f3+2) = 0x00;
  *(f3+3) = 0x43;

  printf("%f\n", f1);
  printf("%f\n", f2);
  printf("%f\n", f3);
  return 0;
}
