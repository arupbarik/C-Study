/* Q24. Create an array of n elements and find the largest. Implement the code so that the largest value is placed
   at the end of the array. */

#include <stdio.h>

int main() {
    int n, i, maxIdx, temp;

    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find index of largest element
    maxIdx = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }

    // Swap largest element with last element
    temp = arr[maxIdx];
    arr[maxIdx] = arr[n - 1];
    arr[n - 1] = temp;

    printf("Array after placing the largest value at the end:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}