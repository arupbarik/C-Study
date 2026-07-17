/* Q19. Calculate the sum of the digits of a given number. E.g.: Say the input is 12345. Therefore, the answer will
   be 1+2+3+4+5 = 15. */

#include <stdio.h>

int main() {
    long num, rem;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%ld", &num);

    while (num > 0) {
        rem = num % 10;
        sum += rem;
        num /= 10;
    }

    printf("Sum of digits = %d\n", sum);
    return 0;
}