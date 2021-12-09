#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

long *array; //allocated in main
long length; //set in main (1 billion)
long nthreads; //number of threads
long s; //scalar

void printArray() {
	printf("columns represent different threads ...\n");
    printf("displaying first 10 values of the matrix for each \"chunk\"\n");
    for (int i = 0; i < 10; i++) {
		 for (int t=0; t<nthreads; t++) {
	   		int index = (length/nthreads)*t+i;
	   		printf("%ld ", array[index]);
       	 } 
       	 printf("\n");
    }
}

/*error handling function: prints out error message*/
int print_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(2);
}

void *scalar_multiply(void *id) {
    long *myid = (long *) id;
    int i;

    //assign each thread its own chunk of elements to process
    long chunk = length / nthreads;
    long start = *myid * chunk;
    long end  = start + chunk;
    if (*myid == nthreads - 1) {
        end = length;
    }

    //perform scalar multiplication on assigned chunk
    for (i = start; i < end; i++) {
        array[i] *= s;
    }

    return NULL;
}

int main(int argc, char **argv) {
    int i;
    pthread_t *thread_array; //pointer to future thread array
    long *thread_ids;
    int ret; //useful for error detection

    /* Read the number of threads to create from the command line. */
    if (argc != 4) {
        fprintf(stderr, "usage: %s int int int<n>\n", argv[0]);
        return 1;
    }
    nthreads = strtol(argv[1], NULL, 10); //get number of threads
    length = strtol(argv[2], NULL, 10); //get length of array
    s = strtol( argv[3], NULL, 10 ); //get scaling factor
	printf("ALLOCATING ARRAY...\n");
    array = malloc(length*sizeof(long));
    for (i=0; i<length; i++) {
      array[i] = (long)i;
    }
    printf("BEFORE MULTIPLY: \n");
    printArray(array);

    /* Allocate space for thread structs and identifiers. */
	struct timespec start, finish;
	double elapsed;
  	clock_gettime(CLOCK_REALTIME, &start);
    thread_array = malloc(nthreads * sizeof(pthread_t));
    thread_ids = malloc(nthreads * sizeof(long));
    if (!thread_array || !thread_ids) print_error("ERROR: malloc failed");

    /* Assign each thread an ID and create all the threads. */
    for (i = 0; i < nthreads; i++) {
        thread_ids[i] = i;
        ret = pthread_create(&thread_array[i], NULL, scalar_multiply, &thread_ids[i]);
        if (ret) print_error("ERROR: pthread create failed");
    }

    /* Join all the threads. Main will pause in this loop until all threads
     * have returned from the thread function. */
    for (i = 0; i < nthreads; i++) {
        ret = pthread_join(thread_array[i], NULL);
        if (ret) print_error("ERROR: pthread join failed");
    }
  	clock_gettime(CLOCK_REALTIME, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("AFTER MULTIPLY: %ld threads took %f s\n", nthreads, elapsed);
    printArray(array);

    free(thread_array);
    free(thread_ids);

    return 0;
}

