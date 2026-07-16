/* Q1. Write a C program to find all possible roots of any given equation of the form of : ax^2 + bx + c = 0. */

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d, r1, r2;
    printf("Enter a, b, c for ax^2+bx+c=0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            printf("Not an equation (a=0,b=0)\n");
        } else {
            printf("Linear equation, root = %.4f\n", -c / b);
        }
        return 0;
    }

    d = b * b - 4 * a * c;

    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are real and distinct: %.4f and %.4f\n", r1, r2);
    } else if (d == 0) {
        r1 = -b / (2 * a);
        printf("Roots are real and equal: %.4f\n", r1);
    } else {
        double real = -b / (2 * a);
        double imag = sqrt(-d) / (2 * a);
        printf("Roots are complex: %.4f + %.4fi and %.4f - %.4fi\n", real, imag, real, imag);
    }
    return 0;
}