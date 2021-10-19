#include <stdio.h>
#include <stdlib.h>

int adder() {
    int a;
    return a + 2;
}

int assign() {
    int y = 40;
    return y;
}

int main(int argc, char* argv[]) {
    int x;
    int* y;
    y = malloc(sizeof(y));
    *y = 6;
    assign();
    x = adder();
    printf("x stored at %p has a value of : %d\n", &x, x);
    printf("y stored at %p has a value of : %d\n", y, *y);
    return 0;
}
