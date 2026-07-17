/* Q16. Write a C program to read any +ve number and check if the number is the same when the digits are placed in
   reverse order.
   Example: Input: 12321 Output: Yes, Input: 12345 Output: No, Input: 4334 Output: Yes, Input: 657 Output: No */

#include <stdio.h>

int main() {
    long num, original, reversed = 0, rem;

    printf("Enter a positive number: ");
    scanf("%ld", &num);

    original = num;

    while (num > 0) {
        rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }

    if (original == reversed)
        printf("Output: Yes\n");
    else
        printf("Output: No\n");

    return 0;
}