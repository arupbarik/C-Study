/* Q14. Write a C program to read and store n numbers. Now, read another number (we call it "key"). Check if the
   key is present in the array or not. */

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // index found
    }
    return -1; // not found
}

int main() {
    int n, i, key, pos;

    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    pos = linearSearch(arr, n, key);

    if (pos != -1)
        printf("Key %d is present in the array at index %d.\n", key, pos);
    else
        printf("Key %d is not present in the array.\n", key);

    return 0;
}