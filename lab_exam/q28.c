/* Q28. Write a C program to create an array of n characters. Now, print the array n+1 times. Each time, the
   characters should rotate.
   Example, Input: Kalam
   Output: Kalam, mKala, amKal, lamKa, alamK, Kalam */

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int n, i, j;

    printf("Enter a word: ");
    scanf("%s", str);
    n = strlen(str);

    // Print n+1 times, rotating characters each time
    char temp[100];
    strcpy(temp, str);

    for (i = 0; i <= n; i++) {
        if (i == 0) {
            printf("%s", temp);
        } else {
            // rotate temp left by 1
            char first = temp[0];
            for (j = 0; j < n - 1; j++)
                temp[j] = temp[j + 1];
            temp[n - 1] = first;

            printf(", %s", temp);
        }
    }
    printf("\n");

    return 0;
}