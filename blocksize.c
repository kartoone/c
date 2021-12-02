#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int *genRandomMatrix(int n, int max) {
    int i;
    int *mat = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
		mat[i] = 1 + rand() % max;
    }

    return mat;
}

// spacing - the matrix offset to read a given number of bytes away
void consecutiveReads(int* matrix, int spacing, int sa) {
	printf("Part 1: block size\n");
	printf("%d %d\n", matrix[0], matrix[spacing]);

	printf("Part 2: associativity\n");
	for (int i=0; i<sa; i++) {
		printf("matrix[%d]: %d\n",i, matrix[i*spacing]);
	}
}


int main(int argc, char **argv) {
    int i, n, bs, sa;
    int *matrix;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <n> <bs> <sa>\n", argv[0]);
        fprintf(stderr, "where <n> is the size of our matrix <bs> is our guess at the block size and <sa> is the known associativity\n");
        return 1;
    }

    n = strtol(argv[1], NULL, 10);
    bs = strtol(argv[2], NULL, 10);
    sa = strtol(argv[3], NULL, 10);

	// display our params for this run
	printf("n: %d, blocksize?: %d, set associativity: %d\n", n, bs, sa);
    srand(time(NULL));
    matrix = genRandomMatrix(n, 100);

	consecutiveReads(matrix, bs/4, sa); // divide by 4 b/c the matrix entries are each taking up 4 bytes 

    free(matrix);
    return 0;
}
