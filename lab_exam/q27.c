/* Q27. Write a C program to add two binary numbers stored as integers. */

#include <stdio.h>
#include <math.h>

int main() {
    long long bin1, bin2, sum = 0;
    int carry = 0, rem1, rem2, i = 0;

    printf("Enter first binary number: ");
    scanf("%lld", &bin1);
    printf("Enter second binary number: ");
    scanf("%lld", &bin2);

    while (bin1 != 0 || bin2 != 0) {
        rem1 = bin1 % 10;
        rem2 = bin2 % 10;

        int total = rem1 + rem2 + carry;
        int digit = total % 2;
        carry = total / 2;

        sum += digit * (long long)pow(10, i);
        i++;

        bin1 /= 10;
        bin2 /= 10;
    }

    if (carry != 0)
        sum += carry * (long long)pow(10, i);

    printf("Sum of binary numbers = %lld\n", sum);
    return 0;
}