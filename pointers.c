/*********************************************************************************************
 * pointers.c - demonstrates difference between "regular" variables and "pointer" variables  *
 *   Note the extra include to stdlib ... this gives you access to "malloc" and "free".      *
 *   The program uses two different variables to hold the number 12. One is a regular        *
 *     variable, and the other is a pointer. Note the usage of "&" with regular variables    *
 *     and the usage of "*" with pointer variables. These operators are essentialy opposites *
 *     of each other. & gives you the address of a regular variable. * gives you the data    *
 *     value stored at the memory address pointed to by the pointer variable.                *
 *   Finally, note how we can use a pointer in a function to alter the value stored by a     *
 *     variable in the "caller" (i.e., the part of your program that calls the function)     *
 *     even though all variables are pass-by-value.                                          *
 *********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// note that n is a pointer
void change(int *n) {
  *n=3;  // update the value stored at the mem address pointed to by n
}

int main() {
  int i;      // regular variable declaration
  int *ptr;   // pointer variable declaration
  i = 12;     // regular variable initialization

  // two steps to initialize a pointer
  ptr = malloc(sizeof(int));  // step 1: allocate memory for it
  *ptr = 12;                  // step 2: assign a value to be stored at the location the pointer was given by malloc

  // before the calls to change: note the memory locations and variable values
  printf("%p %p %d %d\n", &i, ptr, i, *ptr);

  // note the difference in how the change function is called based on whether
  // you are working with a regular variable (i) or a pointer (ptr)
  change(&i);
  change(ptr);

  // after the calls to change: note the memory locations haven't changed, but the variable values have changed!
  printf("%p %p %d %d\n", &i, ptr, i, *ptr);

  // let's be good stewards of memory and free up any memory that we manually allocated during our program
  free(ptr);

  // no errors were detected so return 0 to indicate success
  return 0;
}
