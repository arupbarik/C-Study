/* Q4. a) Write a function to implement multiplication using addition with minimum number of iterations. */

#include <stdio.h>

// Multiply using addition, with minimum number of iterations
// by looping over the smaller of the two numbers
int multiply(int a, int b) {
    int result = 0;
    int smaller, larger;
    int neg = 0;

    if (a < 0) { a = -a; neg = !neg; }
    if (b < 0) { b = -b; neg = !neg; }

    if (a < b) { smaller = a; larger = b; }
    else       { smaller = b; larger = a; }

    for (int i = 0; i < smaller; i++)
        result += larger;

    return neg ? -result : result;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("Product = %d\n", multiply(x, y));
    return 0;
}