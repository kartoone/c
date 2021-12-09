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

void flushcache(int size) {
	char *c = (char*)malloc(size);
	for (int i=0; i<size; i++)
		c[i] = i%256;
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
	printf("Total cache amount: 32768 bytes\n");
	printf("Each cache line is 64 bytes\n");
	printf("But each cache line is 8-way set associative, which means there there are 64*8=%d bytes in each set\n", 64*8);
	printf("Total number of cache lines then is: 32768/512 = %d\n", 32768/512);
	printf("The same colored cache lines (i.e., the same cache line) are  = %d bytes offset from each other\n", 64*64);
	printf("In terms of our matrix where each entry takes up 4 bytes, %d bytes is equivalent to %d/4=%d indices apart from each other\n", 64*64, 64*64, 64*64/4);
	printf("This should be a miss: matrix[%d]: %d\n", 0, matrix[0]);
	printf("Total misses SO FAR should be %d\n", 1);
	printf("These should ALL be hits\n");
	for (int i=0; i<16; i++) {
		printf("matrix[%d]: %d\n", i, matrix[i]);
	}
	printf("Total misses should STIL be %d\n", 1);

	// let's fill up the next SA block ... we've already filled 1
	printf("This should be a miss: matrix[%d]: %d\n", 1024, matrix[1024]);
	for (int i=0; i<16; i++) {
		printf("This should be a hit: matrix[1024+%d]: %d\n", 1024+i, matrix[1024+i]);
	}
	printf("Total misses SO FAR should be %d\n", 2);
	
	// now let's fill up all SA blocks ... we've already filled 2
	for (int si=2; si<8; si++) {
		printf("This should be a miss: matrix[1024*%d]: %d\n", si, matrix[1024*si]);
	}
	printf("Total misses SO FAR should be %d\n", 8);
	for (int si=1; si<8; si++) {
		printf("This should be a hit: matrix[1024*%d]: %d\n", si, matrix[1024*si]);
	}
	printf("Total misses SO FAR should be %d\n", 8);

	// now let's verify that we can read from ANY of those salmon colored blocks (cache block line 0)
//	printf("These should ALL be hits still, but the 8 sets are all completely full for cache line 0\n");
//	for (int i=0; i<8; i++) {
//		printf("This should be a hit: matrix[%d*1024]: %d\n", i, matrix[i]);
//	}
//	printf("Total misses SO FAR should STILL be %d\n", 8);

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

//	consecutiveReads(matrix, bs/4); // divide by 4 b/c the matrix entries are each taking up 4 bytes 
	flushcache(32*1024);
	associativityTest(matrix, bs/4, sa); // divide by 4 b/c the matrix entries are each taking up 4 bytes 

    free(matrix);
    return 0;
}
