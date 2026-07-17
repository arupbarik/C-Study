/* Q20. Check whether a given number is a Palindrome number or not. */

#include <stdio.h>

int main() {
    long num, original, reversed = 0, rem;

    printf("Enter a number: ");
    scanf("%ld", &num);

    original = num;

    while (num > 0) {
        rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }

    if (original == reversed)
        printf("%ld is a Palindrome number.\n", original);
    else
        printf("%ld is NOT a Palindrome number.\n", original);

    return 0;
}