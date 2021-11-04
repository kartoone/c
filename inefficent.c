#include <stdio.h>

int main() {
  int usernum;
  int scalefactor;
  printf("enter the number: ");
  scanf("%d", &usernum);
  int total = 0;
  int instrcount = 0;
  for (int i=0; i<1000000; i++) {
    scalefactor = 2;
    total = total + usernum*scalefactor;
    instrcount = instrcount + 3;
  }
  printf("the scaled total is: %d\n", total);
  printf("total instr count: %d\n", instrcount);
  return 0;
}
