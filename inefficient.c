#include <stdio.h>

// demonstrates an INEFFICIENT algorithm as indicated below
int main() {
  int usernum;
  int scalefactor;
  printf("enter the number: ");
  scanf("%d", &usernum);
  int total = 0;
//int instrcount = 0; // I commented instrcount out b/c perf works on my office linux system
  for (int i=0; i<1000000; i++) {
    scalefactor = 2;	// this should be OUTSIDE the loop
    total = total + usernum*scalefactor; // the multiplication should happen OUTSIDE the loop
//  instrcount = instrcount + 3;
  }
  printf("the scaled total is: %d\n", total);
//printf("inst count: %d\n", instrcount);
  return 0;
}
