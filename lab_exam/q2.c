/* Q2. Write a C program to print all the Armstrong numbers lesser than 5000. */

#include <stdio.h>
#include <math.h>

int main() {
    int i, temp, rem, digits, sum;

    printf("Armstrong numbers less than 5000:\n");
    for (i = 1; i < 5000; i++) {
        temp = i;
        digits = 0;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        temp = i;
        sum = 0;
        while (temp != 0) {
            rem = temp % 10;
            sum += (int)pow(rem, digits);
            temp /= 10;
        }
        if (sum == i)
            printf("%d\n", i);
    }
    return 0;
}