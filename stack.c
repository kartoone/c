#include <stdio.h>

void swap(int* param1, int* param2);

// note that argc and argv just complicated this tremendously and since
// we have the ability to omit them in C programs, let's do that!
int main() {
	int i;				// just a plain old integer (4 bytes)
	int num1;			// another integer (4 bytes)
	int num2;			// another integer (4 bytes)
    int *p1;			// a POINTER to an integer (8 bytes -- all pointers are 8 bytes on 64-bit systems because the memory addresses are 8 bytes)
	int *p2;			// another 8 byte pointer
	int numarray[10];   // this is technically still just an 8 byte pointer ... but it also has side effect of allocating TEN 4-byte ints on the stack

	// let's initialize all our stack variables
	// NOTE that even though there are pointers here, everything is still on the stack!
	// those pointers simply point to other memory addresses on the stack as shown in the attached diagram
	num1 = 3;  
	num2 = 4; 
	p2 = &num2;
	p1 = &num1;
	for (i=0; i<10; i++) {
		numarray[i] = i;  // initialize the value of each array position to be its array position to make it easy to identify what value each position should have
						  // in other words, the value stored at memory location numarray[4] should be the number 4
	}

	// now let's do some printf functions to display some of the interesting memory addresses and values
	// first let's display all the memory addresses
	printf("The memory address ON THE STACK for i is:          %p\n", &i);
	printf("The memory address ON THE STACK for num1 is:       %p\n", &num1);
	printf("The memory address ON THE STACK for num2 is:       %p\n", &num2);
	printf("The memory address ON THE STACK for p1 is:         %p\n", &p1);
	printf("The memory address ON THE STACK for p2 is:         %p\n", &p2);
	printf("The memory address ON THE STACK for numarray is:   %p\n", &numarray);
	for (i=0; i<10; i++) {
		printf("The memory address ON THE STACK for numarray[%d] is %p\n", i, &numarray[i]);
	}

	// now let's look at all the values
	printf("\n");
	printf("The value stored at i's memory location is:            %d\n", i);
	printf("The value stored at num1's memory location is:         %d\n", num1);
	printf("The value stored at num2's memory location is:         %d\n", num2);               	
	printf("The value stored at p1's memory location is:           %p\n", p1);                 
	printf("The value stored at p2's memory location is:           %p\n", p2);
	printf("The value stored at numarray's memory location is:     %p\n", numarray);
	for (i=0; i<10; i++) {
		printf("The value stored at numarray[%d]'s memory location is: %d\n", i, numarray[i]);
	}

	printf("\nPutting it all together into one table\n\n");
	printf("%5s %12s %17s %17s\n", "Type", "Variable", "Address", "Value");
	printf("%5s %12s %17p %17d\n", "int", "i", &i, i);
	printf("%5s %12s %17p %17d\n", "int", "num1", &num1, num1);
	printf("%5s %12s %17p %17d\n", "int", "num2", &num2, num2);
	printf("%5s %12s %17p %17p\n", "int*", "p1", &p1, p1);
	printf("%5s %12s %17p %17p\n", "int*", "p2", &p2, p2);
	printf("%5s %12s %17p %17p\n", "int[]", "numarray", &numarray, numarray);
	for (i=0; i<10; i++) {
		printf("%5s %10s%1d%1s %17p %17d\n", "int", "numarray[", i, "]", &numarray[i], numarray[i]);
	}

	printf("\ncalling swap...");
	swap(&num1, &num2);
	
	// re-display the rest of the stack
	printf("%5s %12s %17p %17d\n", "int", "i", &i, i);
	printf("%5s %12s %17p %17d\n", "int", "num1", &num1, num1);
	printf("%5s %12s %17p %17d\n", "int", "num2", &num2, num2);
	printf("%5s %12s %17p %17p\n", "int*", "p1", &p1, p1);
	printf("%5s %12s %17p %17p\n", "int*", "p2", &p2, p2);
	printf("%5s %12s %17p %17p\n", "int[]", "numarray", &numarray, numarray);
	for (i=0; i<10; i++) {
		printf("%5s %10s%1d%1s %17p %17d\n", "int", "numarray[", i, "]", &numarray[i], numarray[i]);
	}

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
