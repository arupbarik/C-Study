/* Q21. Write a program to read and print the transpose of any given square matrix. Also print the diagonal
   elements of the matrix. */

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    int matrix[n][n], transpose[n][n];

    printf("Enter %d elements of the matrix:\n", n * n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    // Compute transpose
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            transpose[j][i] = matrix[i][j];

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }

    printf("\nDiagonal elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", matrix[i][i]);
    printf("\n");

    return 0;
}