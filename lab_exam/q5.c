/* Q5. Write a C program to create an array of character type. Load the array with random alphabets. Now, replace
   all vowels by * and print the array. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int n, i;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char arr[n];
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = 'a' + rand() % 26;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        char ch = tolower(arr[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            arr[i] = '*';
    }

    printf("After replacing vowels: ");
    for (i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");

    return 0;
}