/**************************************************************************
 * geom.c - geometry problem that works with dynamically allocated arrays *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void area(int *width, int *height, int count, int *areas);
void perimeter(int *width, int *height, int count, int *perimeters);

int main() {
	int *width, *height, *areas, *perimeters; // declaration for our four dynamically allocated arrays
	int count;								// and the count of how many rectangles to be entered
	int i;									// index variable for your "for loop" for retrieving the data

	// TO DO: prompt the user to find out how many rectangles they are going to enter
	// HINT: use scanf
	scanf("%d", &count);

	// TO DO: now that we know how many rectangles we are going to receive, go ahead and
	// allocate the four arrays with enough room to store all the rectangles
	// HINT: use malloc and sizeof
	width = malloc(sizeof(int)*count);
	height = malloc(sizeof(int)*count);
	areas = malloc(sizeof(int)*count);
	perimeters = malloc(sizeof(int)*count);

	// TO DO: use a for loop to retrieve and store all the widths and heights for "count" rectangles
  for (i=0; i<count; i++) {
		printf("width: ");
		scanf("%d", &width[i]);
		printf("height: ");
		scanf("%d", &height[i]);
	}


	// TO DO: call the area function ... note the prototype I gave you ...
	// 		the function doesn't return anything, instead
	//		it receives a pointer to the array where it should store the areas as they are being calculated
  area(width, height, count, areas);

	// TO DO: call the perimeter function in the same way you called the area function
	perimeter(width, height, count, perimeters);

	// TO DO: nicely display all the areas and perimeters you calculated

	// TO DO: free up all the allocated memory
	free(areas);
	free(perimeters);
	free(width);
	free(height);

	return 0;
}

// TO DO: implement the function below
//   note that it doesn't return anything
//   instead, it should loop through the width&height data "count" times and
//	 calculate the area each time and put it into the area array
void area(int *width, int *height, int count, int *areas) {
	int i;
	for (i=0; i<count; i++) {
		areas[i] = width[i]*height[i];
	}
}

// TO DO: implement the function below
//   note that it doesn't return anything
//   instead, it should loop through the width&height data "count" times and
//	 calculate the perimeter each time and put it into the perimeter array
void perimeter(int *width, int *height, int count, int *perimeters) {
	int i;
	for (i=0; i<count; i++) {
		perimeters[i] = width[i]*2 + height[i]*2;
	}
}
