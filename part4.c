#include <stdio.h>

int num1;
int num2;

int main() {
  int i;
  int total = 0;
  printf("Enter a number: ");
  scanf("%d",&num1);
  printf("Enter a number: ");
  scanf("%d",&num2);
  i = num1;
  total = 0;
  while (i <= num2) {
    total = total + i;
    printf("%d\n", i++);
  }
  printf("The sum of the numbers between %d and %d is %d\n", num1, num2, total);
  return 0;
}
