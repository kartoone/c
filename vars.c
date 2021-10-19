#include <stdio.h>
#include <stdlib.h>

int main() {
	// STACK primivite variables
	int num1; // the actual value is stored on the stack
	int num2; // the actual value is stored on the stack
	
	// STACK pointer variables
	int* num3; // the value is an 8-byte memory location pointing to the HEAP after the malloc command below executes
	int* num4; // the value is an 8-byte memory location pointing to the HEAP after the malloc command below executes;
	num3 = malloc(sizeof(int)); // allocates 4 bytes of HEAP memory to store the actual integer
	num4 = malloc(sizeof(int)); // allocates 4 bytes of HEAP memory to store the actual integer

	printf("Enter num1: ");
	scanf("%d",&num1); // note the AMPERSAND & because scanf needs a memory address
	printf("Enter num2: ");
	scanf("%d",&num2); // note the AMPERSAND & because scanf needs a memory address
	printf("Sum: %d\n", num1+num2);
	printf("Enter num3: ");
	scanf("%d",num3); // note that there is NO AMPERSAND here because num3 is already a memory address
	printf("Enter num4: ");
	scanf("%d",num4); // note that there is NO AMPERSAND here because num3 is already a memory address
	printf("Sum: %d\n",*num3+*num4); // note we need the "*" operator to dereference the pointer and retrieve the user values stored on heap memory
	return 0;
}
