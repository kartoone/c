#include <stdio.h>
#include <stdlib.h>

void swap(int* param1, int* param2);

// note that argc and argv just complicated this tremendously and since
// we have the ability to omit them in C programs, let's do that!
int main() {
	// all of these variables below will have memory allocated on the stack to hold either the value (i) or the pointer address (8 bytes)
	// but one of them will point to a memory address on the stack (num1) and some of them will point to memory addresses on the heap (num2 and numarray)
	int i;				// just a plain old integer (4 bytes)
	int *num1;			// a pointer to an integer (we will have this one point to i)
	int *num2;			// we will dynamically allocate this integer on the heap
	int *numarray;   	// we will dynamically allocate this array of ints (we will go with 10 ints again like the stack.c example)

	// let's initialize all our variables
	num1 = &i;  
	num2 = malloc(sizeof(int));				// Note that we don't multiply here because we just need space for a single int.
	*num2 = 5;
	numarray = malloc(sizeof(int)*10);		// Multiply by 10 here so we have room for 10 ints on our dynamically allocated heap array

	// note that the for loop below is IDENTICAL to the stack.c example using a stack array
	for (i=0; i<10; i++) {
		numarray[i] = i;  // initialize the value of each array position to be its array position to make it easy to identify what value each position should have
						  // in other words, the value stored at memory location numarray[4] should be the number 4
	}

	// now let's do some printf functions to display some of the interesting memory addresses and values
	// first let's display all the memory addresses
	printf("The memory address ON THE STACK for i is:          %p\n", &i);
	printf("The memory address ON THE STACK for num1 is:       %p\n", &num1);
	printf("The memory address ON THE STACK for num2 is:       %p\n", &num2);
	printf("The memory address ON THE HEAP for num2 is:        %p\n", num2);
	printf("The memory address ON THE STACK for numarray is:   %p\n", &numarray);
	printf("The HEAP memory address (i.e., the value stored on the stack) for numarray is:    %p\n", numarray);
	for (i=0; i<10; i++) {
		printf("The HEAP memory address for numarray[%d] is: %p\n", i, &numarray[i]);
	}

	// now let's look at all the values
	printf("\n");
	printf("The value stored at i's memory location is:                 %d\n", i);
	printf("The value stored at num1's memory STACK location is:        %p\n", num1);
	printf("The value stored at num2's memory STACK location is:        %p\n", num2);               	
	printf("The value stored at num2's memory HEAP location is:         %d\n", *num2);               	
	printf("The value stored at numarray's STACK memory location is:    %p\n", &numarray);
	for (i=0; i<10; i++) {
		printf("The value stored at numarray[%d]'s HEAP memory location is: %d\n", i, numarray[i]);
	}

	printf("\nPutting it all together into one table\n\n");
	printf("%5s %12s %17s %17s\n", "Type", "Variable", "Address", "Value");
	printf("%5s %12s %17p %17d\n", "int", "i", &i, i);
	printf("%5s %12s %17p %17p\n", "int*", "num1", &num1, num1);
	printf("%5s %12s %17p %17p\n", "int*", "num2", &num2, num2);
	printf("%5s %12s %17p %17p\n", "int*", "numarray", &numarray, numarray);
	for (i=0; i<10; i++) {
		printf("%5s %10s%1d%1s %17p %17d\n", "int", "numarray[", i, "]", &numarray[i], numarray[i]);
	}

	printf("\ncalling swap...");
	swap(num1, num2);
	
	// re-display the rest of the stack
	printf("%5s %12s %17p %17d\n", "int", "i", &i, i);
	printf("%5s %12s %17p %17p\n", "int", "num1", &num1, num1);
	printf("%5s %12s %17p %17p\n", "int", "num2", &num2, num2);
	printf("%5s %12s %17p %17p\n", "int[]", "numarray", &numarray, numarray);
	for (i=0; i<10; i++) {
		printf("%5s %10s%1d%1s %17p %17d\n", "int", "numarray[", i, "]", &numarray[i], numarray[i]);
	}

	free(num2);
	free(numarray);

	return 0;
}

void swap(int* param1, int* param2) {
	int temp = *param2;
	*param2 = *param1;
	*param1 = temp;

	printf("inside swap right before swap returns (i.e., after the values have been swapped)!\n\n");
	printf("%5s %12s %17s %17s\n", "Type", "Variable", "Address", "Value");
	printf("%5s %12s %17p %17d\n", "int", "temp", &temp, temp);
	printf("%5s %12s %17p %17p\n", "int*", "param1", &param1, param1);
	printf("%5s %12s %17p %17p\n", "int*", "param2", &param2, param2);
}
