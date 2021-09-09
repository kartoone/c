/******************************************************************
 * arrays.c - demonstrates wokring with dynamically sized arrays  *
 *   note the extra include to stdlib ... this gives you access   *
 *   to the "malloc" and "free" functions.                        *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *nums;  // note the "*" in front of nums. that's what turns nums into a pointer, which we use for our dynamically allocated array
  int cnt;
  int i;
  int total;

  printf("how many numbers?\n");
  scanf("%d", &cnt);   // note the "&" ... we must give scanf the memory ADDRESS of a variable ... that's what the & operator does

  // allocate space on the heap for all of our integers ... we use the sizeof operator to know how big a single integer is, and then
  // we multiply that by the "count" of the number of numbers we want to store
  nums = malloc(sizeof(int)*cnt);

  printf("enter %d numbers below:\n", cnt);
  for (i=0; i<cnt; i++) {
    scanf("%d",&nums[i]); // note the square brackets which lets us "offset" to the exact location in memory of the specific num we are storing
  }
  total = 0;
  for (i=0; i<cnt; i++) {
    total = total + nums[i];
  }
  printf("the sum of your nums is: %d", total);

  /* all good C programs should have an equal number of "malloc" and "free" function calls */
  free(nums);  // frees the memory that was allocated for our nums array

  return 0;
}
