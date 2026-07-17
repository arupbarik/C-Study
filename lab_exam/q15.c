/* Q15. Write a C program having a function to reverse any given string. */

#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    int start = 0, end = len - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);
    return 0;
}