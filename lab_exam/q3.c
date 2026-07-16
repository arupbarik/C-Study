/* Q3. Write a program to merge two strings using a function having a pointer as a parameter.
   Q11. Write a C program to merge two strings using a function having a pointer as a parameter. (Same as Q3) */

#include <stdio.h>
#include <string.h>

// Merges (concatenates) str2 onto the end of str1 using pointers
void mergeStrings(char *str1, char *str2) {
    while (*str1 != '\0')
        str1++;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[200], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    mergeStrings(str1, str2);

    printf("Merged string: %s\n", str1);
    return 0;
}