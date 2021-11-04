#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n=10001; // this is about the maximum a system can handle, DON'T increase this unless you want to crash your computer

double averageMat_v1(int** mat); 
double averageMat_v2(int** mat); 

int main() {
  // had to switch to heap allocation b/c the stack size for our executable isn't enough to hold our ginormous array
  int** numbers = malloc(sizeof(int*)*n);
  for (int i=0; i<n; i++) {
	numbers[i] = malloc(sizeof(int)*n);
    for (int j=0; j<n; j++) {
      numbers[i][j] = i;
    }
  }
  printf("first 10 memory accesses in version1:\n");
  clock_t start = clock();
  double ans1 = averageMat_v1(numbers); 
  double elapsed1 = (clock() - start) / (double)CLOCKS_PER_SEC;

  printf("\n");
  printf("first 10 memory accesses in version2:\n");
  start = clock();
  double ans2 = averageMat_v2(numbers); 
  double elapsed2 = (clock() - start) / (double)CLOCKS_PER_SEC;

  printf("\n");
  printf("note that the answers below are the same for both versions ... but look at how much slower the second version is!\n");
  printf("v1 average: %f elapsed time: %f\n", ans1, elapsed1);
  printf("v2 average: %f elapsed time: %f\n", ans2, elapsed2);
  return 0;
}


double averageMat_v1(int** mat) { 
    int i, j = 0;
	long total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
			if (i==0 && j<10)
            	printf("%p\n", &mat[i][j]);
        }
    }

    return (double) total / (n * n);
}

double averageMat_v2(int** mat) { 
    int i, j = 0;
	long total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
			if (i==0 && j<10)
            	printf("%p\n", &mat[j][i]);
        }
    }

    return (double) total / (n * n);
}
