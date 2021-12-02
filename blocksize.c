#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int *genRandomMatrix(int n, int max) {
    int i;
    int *mat;

 	posix_memalign((void**)&mat, 64, (n * sizeof(int *)));

    for (i = 0; i < n; i++) {
		mat[i] = 1 + rand() % max;
    }

    return mat;
}

// spacing - the matrix offset to read a given number of bytes away
void consecutiveReads(int* matrix, int spacing) {
	printf("Part 1: block size determinination\n");
	printf("%d %d %d %p %p\n", (int)sizeof(int), matrix[0], matrix[spacing], &matrix[0], &matrix[spacing]);
}

// spacing - the matrix offset to read a given number of bytes away
// sa - the known set associativity
void associativityTest(int * matrix, int spacing, int sa) {
	printf("Part 2: associativity verification\n");
	printf("These should generate %d misses b/c they are ALL misses.\n", sa);
	for (int i=0; i<sa; i++) {
		printf("matrix[%d]: %d\n",i, matrix[i*spacing]);
	}
	printf("These should generate %d hits b/c they are ALL hits.\n", sa);
	for (int i=0; i<sa; i++) {
		printf("matrix[%d+1]: %d\n",i+1, matrix[i*spacing+1]);
	}
	printf("These should generate %d misses b/c they are for the sets immediately after the ones currently loaded.\n", sa);
	for (int i=sa; i<2*sa; i++) {
		printf("matrix[%d]: %d\n",i, matrix[i*spacing]);
	}
	printf("Total misses should be %d + %d = %d\n", sa, sa, sa+sa);
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

	consecutiveReads(matrix, bs/4); // divide by 4 b/c the matrix entries are each taking up 4 bytes 
//	associativityTest(matrix, bs/4, sa); // divide by 4 b/c the matrix entries are each taking up 4 bytes 

    free(matrix);
    return 0;
}
