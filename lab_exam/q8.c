/* Q8. Write a C program to read and store 2 integers. Now, swap the values of these 2 variables using pointers. */

#include <stdio.h>

int main() {
    int a, b, *p1, *p2, temp;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    p1 = &a;
    p2 = &b;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}