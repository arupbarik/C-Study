/* Q12. Write a C program to calculate sum = 1! - 2! + 3! - 4! + 5! - 6! + ... n! (n is user input). */

#include <stdio.h>

long long factorial(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++)
        fact *= i;
    return fact;
}

int main() {
    int n, i;
    long long sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        long long fact = factorial(i);
        if (i % 2 == 1)
            sum += fact;
        else
            sum -= fact;
    }

    printf("Sum = %lld\n", sum);
    return 0;
}