/* An example C program with local and global variables */
#include <stdio.h>

int max(int n1, int n2); /* function prototypes */
int change(int amt);

int g_x;  /* global variable: declared outside function bodies */

int main() {
    int x, result;   /* local variables: declared inside function bodies */

    printf("Enter a value: ");
    scanf("%d", &x);
    g_x = 10;       /* global variables can be accessed in any function */

    result = max(g_x, x);
    printf("%d is the largest of %d and %d\n", result, g_x, x);

    result = change(10);
    printf("g_x's value was %d and now is %d\n", result, g_x);

    return 0;
}

int max(int n1, int n2) {  /* function with two parameters */
    int val;    /* local variable */

    val = n1;
    if ( n2 > n1 ) {
        val = n2;
    }
    return val;
}

int change(int amt) {
    int val;

    val = g_x;  /* global variables can be accessed in any function */
    g_x += amt;
    return val;
}
