#include <stdio.h>
#include <stdlib.h>

int main() {
	// f1 is the normal way a floating point number is initialized ... and C takes care of converting it into the IEEE754 representation
	float f1 = 3.75f;
	
	// f2 is being set to an integer that represents the bits of the IEEE754 encoded floating point number 3.75
	int f2 = 0b01000000011100000000000000000000;  // Step 1: 11.11 
	                     							// Step 2: 1.111 x 2^1
	                     							// Step 3: explonent = 1 + 127 = 128
	
	// this is just the HEX representation of the bit pattern used for f2
	int f3 = 0x40700000; // NOTE that f2 and f3 are BOTH going to be stored in little endian order (0x00004070) so we don't need to manually reverse the bytes
	
	// you will see that these printf calls below all print out the same thing
	// we have to do the pointer trickery to keep C from converting the integer automatically to the corresponding floating point number
	printf("%f\n", f1);
	printf("%f\n", *((float*) &f2));
	printf("%f\n", *((float*) &f3));
	return 0;
}
