#include <stdio.h>
#include <stdlib.h>

int main() {
  int *nums;
  int cnt;
  int i;
  int total;

  printf("how many numbers?\n");
  scanf("%d", &cnt);
  nums = malloc(sizeof(int)*cnt);

  printf("enter %d numbers below:\n", cnt);
  for (i=0; i<cnt; i++) {
    scanf("%d",&nums[i]);
  }
  total = 0;
  for (i=0; i<cnt; i++) {
    total = total + nums[i];
  }
  printf("the sum of your nums is: %d", total);
  return 0;
}
