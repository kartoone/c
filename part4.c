#include <stdio.h>

int num1;
int num2;

int main() {
  int i;
  printf("Enter a number: ");
  scanf("%d",&num1);
  printf("Enter a number: ");
  scanf("%d",&num2);
  i = num1;
  while (i <= num2) {
    printf("%d\n", i++);
  }
  return 0;
}
