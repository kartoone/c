#include <stdio.h>

int main() {
  int numbers[10][100];
  for (int i=0; i<10; i++) {
    for (int j=0; j<100; j++) {
      numbers[i][j] = i;
    }
  }
  printf("go braves!!!\n");
  return 0;
}


float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
            printf("%p\n", &mat[i][j]);
        }
    }

    return (float) total / (n * n);
}

float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
            printf("%p\n", &mat[i][j]);
        }
    }

    return (float) total / (n * n);
}
