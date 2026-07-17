/* Q26. Implement Binary Search on 5, 6, 11, 16, 23, 32, 45, 81. Search for 20 and 45 in this list. */

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 6, 11, 16, 23, 32, 45, 81};
    int n = sizeof(arr) / sizeof(arr[0]);
    int keys[] = {20, 45};
    int i, pos;

    for (i = 0; i < 2; i++) {
        pos = binarySearch(arr, n, keys[i]);
        if (pos != -1)
            printf("Key %d found at index %d.\n", keys[i], pos);
        else
            printf("Key %d not found in the list.\n", keys[i]);
    }

    return 0;
}