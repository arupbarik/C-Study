/* Q18. Write a program to print given number in reverse. */

#include <stdio.h>

int main() {
    long num, rem, reversed = 0;

    printf("Enter a number: ");
    scanf("%ld", &num);

    while (num > 0) {
        rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }

    printf("Reversed number: %ld\n", reversed);
    return 0;
}