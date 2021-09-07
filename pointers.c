#include <stdio.h>
#include <stdlib.h>

void change(int *n) {
  *n=3;
}

int main() {
  int i;
  int *ptr;
  i = 12;
  ptr = malloc(sizeof(int));
  *ptr = 12;
  printf("%p %p %d %d\n", &i, ptr, i, *ptr);
  change(&i);
  change(ptr);
  printf("%p %p %d %d\n", &i, ptr, i, *ptr);
  free(ptr);
  return 0;
}
