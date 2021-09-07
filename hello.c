#include <stdio.h>  // this gives us access to the "printf" function

int main() {
  int a, b;       // note the separation of type declaration and value initialization
  a = 3;
  b = 4;
  printf("%d + %d = %d\n", a, b, a+b);  // %d is the placeholder parameter for integers ... all of our variables are integers so we want to use %d
  printf("hello, world\n");
  return 0;       // all C program must return an "error" code ... 0 means "no error"
}
