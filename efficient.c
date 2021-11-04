#include <stdio.h>

// demonstrates more efficient version of inefficient.c
int main() {
  int usernum;
  int scalefactor;
  printf("enter the number: ");
  scanf("%d", &usernum);
  int total = 0;
//int instrcount = 0; 				// I commented instrcount out b/c perf works on my office linux system
  scalefactor = 2; 					// Properly moved outside the loop
  usernum = usernum*scalefactor;	// Properly moved outside the loop
  for (int i=0; i<1000000; i++) {
    total = total + usernum;
//  instrcount = instrcount + 1;
  }
  printf("the scaled total is: %d\n", total);
//printf("instr count: %d\n", instrcount);
  return 0;
}
