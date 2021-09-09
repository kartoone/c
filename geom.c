/**************************************************************************
 * geom.c - geometry problem that works with dynamically allocated arrays *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void area(int *width, int *height, int count, int *area);
void perimeter(int *width, int *height, int count, int *perimeter);

int main() {
	int *width, *height, *area, *perimeter; // declaration for our four dynamically allocated arrays
	int count;								// and the count of how many rectangles to be entered

	// TO DO: prompt the user to find out how many rectangles they are going to enter
	// HINT: use scanf

	// TO DO: now that we know how many rectangles we are going to receive, go ahead and 
	// allocate the four arrays with enough room to store all the rectangles
	// HINT: use malloc and sizeof

	// TO DO: use a for loop to retrieve and store all the widths and heights for "count" rectangles

	// TO DO: call the area function ... note the prototype I gave you ... 
	// 		the function doesn't return anything, instead 
	//		it receives a pointer to the array where it should store the areas as they are being calculated

	// TO DO: call the perimeter function in the same way you called the area function

	// TO DO: nicely display all the areas and perimeters you calculated

	// TO DO: free up all the allocated memory

	return 0;
}

// TO DO: implement the function below
//   note that it doesn't return anything
//   instead, it should loop through the width&height data "count" times and 
//	 calculate the area each time and put it into the area array
void area(int *width, int *height, int count, int *area) {

}

// TO DO: implement the function below
//   note that it doesn't return anything
//   instead, it should loop through the width&height data "count" times and 
//	 calculate the perimeter each time and put it into the perimeter array
void perimeter(int *width, int *height, int count, int *perimeter) {

}

	
