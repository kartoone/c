#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

long *array; //allocated in main
long length; //set in main (1 billion)
long nthreads; //number of threads

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

void *matrix_sum(void *id) {
    long *myid = (long *) id;
    int i;
	long *mysum = malloc(sizeof(long));

	// init sum for this thread to 0
	*mysum = 0;

    //assign each thread its own chunk of elements to process
    long chunk = length / nthreads;
    long start = *myid * chunk;
    long end  = start + chunk;
    if (*myid == nthreads - 1) {
        end = length;
    }

    //perform scalar multiplication on assigned chunk
    for (i = start; i < end; i++) {
        *mysum += array[i];
    }

    return mysum;
}

int main(int argc, char **argv) {
    int i;
    pthread_t *thread_array; //pointer to future thread array
    long *thread_ids;
    int ret; //useful for error detection

    /* Read the number of threads to create from the command line. */
    if (argc != 3) {
        fprintf(stderr, "usage: %s int int <n>\n", argv[0]);
        return 1;
    }
    nthreads = strtol(argv[1], NULL, 10); //get number of threads
    length = strtol(argv[2], NULL, 10); //get length of array
	printf("ALLOCATING ARRAY...\n");
    array = malloc(length*sizeof(long));
    for (i=0; i<length; i++) {
      array[i] = (long)i;
    }
    printf("STARTING ADDITION: \n");

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
        ret = pthread_create(&thread_array[i], NULL, matrix_sum, &thread_ids[i]);
        if (ret) print_error("ERROR: pthread create failed");
    }

    /* Join all the threads. Main will pause in this loop until all threads
     * have returned from the thread function. */
	long grand_total = 0;
    for (i = 0; i < nthreads; i++) {
		void *retval;
        ret = pthread_join(thread_array[i], &retval);
		grand_total += *(long*)retval;
        if (ret) print_error("ERROR: pthread join failed");
		free(retval);
    }
  	clock_gettime(CLOCK_REALTIME, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Summation result: %ld, %ld threads took %f s total\n", grand_total, nthreads, elapsed);

    free(thread_array);
    free(thread_ids);

    return 0;
}

