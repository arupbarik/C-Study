/* Q6. Write a program to calculate the length of a string using a function having a pointer as a parameter.
   Q10. Write a C program to calculate the length of a string using a function having a pointer as a parameter. (Same as Q6) */

#include <stdio.h>

int stringLength(char *str) {
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}

int main() {
    char str[200];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove trailing newline
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') { str[i] = '\0'; break; }
        i++;
    }

    printf("Length of the string = %d\n", stringLength(str));
    return 0;
}