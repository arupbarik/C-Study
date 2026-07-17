/* Q30. Write a program to read and print the transpose of any given square matrix using an 1D array. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;

    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    int *matrix = (int *)malloc(n * n * sizeof(int));
    int *transpose = (int *)malloc(n * n * sizeof(int));

    printf("Enter %d elements of the matrix:\n", n * n);
    for (i = 0; i < n * n; i++)
        scanf("%d", &matrix[i]);

    // matrix[i][j] is stored at matrix[i*n + j]
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            transpose[j * n + i] = matrix[i * n + j];

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", matrix[i * n + j]);
        printf("\n");
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", transpose[i * n + j]);
        printf("\n");
    }

    free(matrix);
    free(transpose);
    return 0;
}