/* Q23. Find all the prime numbers in a given range. */

#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int low, high, i;

    printf("Enter the range (low and high): ");
    scanf("%d %d", &low, &high);

    printf("Prime numbers between %d and %d are:\n", low, high);
    for (i = low; i <= high; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}