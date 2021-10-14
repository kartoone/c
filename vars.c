#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1;
  int num2;
  int* num3;
  int* num4;
  num3 = malloc(sizeof(int));
  num4 = malloc(sizeof(int));
  printf("Enter num1: ");
  scanf("%d",&num1);
  printf("Enter num2: ");
  scanf("%d",&num2);
  printf("Sum: %d\n", num1+num2);
  printf("Enter num3: ");
  scanf("%d",num3);
  printf("Enter num4: ");
  scanf("%d",num4);
  printf("Sum: %d\n",*num3+*num4);
  return 0;
}
