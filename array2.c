/* Copyright (c) 2020, Dive into Systems, LLC (https://diveintosystems.org/)
 */

#include <stdio.h>

/* function prototypes: */
void printArray(int a[], int size);
int minimum(int a[], int size);

int main() {
    // this is a way to statically initialize an array
    // (something that is only occasionally useful):
    int data[10] = {5, 8, 9, 1, 10, 12, 4, 3, 7, 13};
    int opposite[10];
    int min, i;

    printArray(opposite, 10);

    for(i = 0; i < 10; i++) {
        opposite[i] = -(data[i]);
    }
    printArray(data, 10);
    min = minimum(data, 10);
    printf("Smallest value in data is: %d\n", min);

    printArray(opposite, 10);
    min = minimum(opposite, 10);
    printf("Smallest value in opposite is: %d\n", min);

    return 0;
}

/* prints out the contents of an array
 *  a: the array of int values
 *  size: the number of elements in the array
 */
void printArray(int a[], int size) {
    // An example of a function that doesn't return a value.
    int i;

    printf("Array Contents:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* finds the smallest element in the passed array
 *  a: the array of int values
 *  size: the number of elements in the array
 *  returns: the smallest value in the array
 */
int minimum(int a[], int size) {
    int low;
    low = a[0];
    for (size--; size>0; size--) {
        if (a[size] < low) {
          low = a[size];
        }
    }
    return low;
}
