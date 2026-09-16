/*
 * sorting_algorithms.c
 *
 * Pseudocode + C implementations for common sorting algorithms:
 *   1. Bubble Sort
 *   2. Selection Sort
 *   3. Insertion Sort
 *   4. Merge Sort
 *   5. Quick Sort
 *   6. Heap Sort
 *   7. Counting Sort
 *   8. Radix Sort (LSD, base 10, non-negative ints)
 *   9. Shell Sort
 *
 * Compile: gcc -O2 -o sorting_algorithms sorting_algorithms.c
 * Run:     ./sorting_algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 10

/* ---------- Utility functions ---------- */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void copyArray(int dest[], int src[], int n) {
    memcpy(dest, src, n * sizeof(int));
}

/* =====================================================
 * 1. BUBBLE SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   for i from 0 to n-1:
 *     for j from 0 to n-i-2:
 *       if arr[j] > arr[j+1]:
 *         swap(arr[j], arr[j+1])
 * ===================================================== */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break; /* already sorted */
    }
}

/* =====================================================
 * 2. SELECTION SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   for i from 0 to n-1:
 *     minIdx = i
 *     for j from i+1 to n-1:
 *       if arr[j] < arr[minIdx]:
 *         minIdx = j
 *     swap(arr[i], arr[minIdx])
 * ===================================================== */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(&arr[i], &arr[minIdx]);
    }
}

/* =====================================================
 * 3. INSERTION SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   for i from 1 to n-1:
 *     key = arr[i]
 *     j = i - 1
 *     while j >= 0 and arr[j] > key:
 *       arr[j+1] = arr[j]
 *       j = j - 1
 *     arr[j+1] = key
 * ===================================================== */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* =====================================================
 * 4. MERGE SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   mergeSort(arr, l, r):
 *     if l < r:
 *       m = (l + r) / 2
 *       mergeSort(arr, l, m)
 *       mergeSort(arr, m+1, r)
 *       merge(arr, l, m, r)
 *
 *   merge(arr, l, m, r):
 *     create left[] and right[] subarrays
 *     merge them back into arr in sorted order
 * ===================================================== */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* =====================================================
 * 5. QUICK SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   quickSort(arr, low, high):
 *     if low < high:
 *       pivotIdx = partition(arr, low, high)
 *       quickSort(arr, low, pivotIdx - 1)
 *       quickSort(arr, pivotIdx + 1, high)
 *
 *   partition(arr, low, high):
 *     pivot = arr[high]
 *     i = low - 1
 *     for j from low to high-1:
 *       if arr[j] < pivot:
 *         i++
 *         swap(arr[i], arr[j])
 *     swap(arr[i+1], arr[high])
 *     return i + 1
 * ===================================================== */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* =====================================================
 * 6. HEAP SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   heapSort(arr, n):
 *     build max heap from arr
 *     for i from n-1 down to 1:
 *       swap(arr[0], arr[i])
 *       heapify(arr, i, 0)
 *
 *   heapify(arr, n, i):
 *     largest = i
 *     left = 2*i + 1, right = 2*i + 2
 *     if left < n and arr[left] > arr[largest]: largest = left
 *     if right < n and arr[right] > arr[largest]: largest = right
 *     if largest != i:
 *       swap(arr[i], arr[largest])
 *       heapify(arr, n, largest)
 * ===================================================== */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* =====================================================
 * 7. COUNTING SORT (non-negative integers)
 * -----------------------------------------------------
 * Pseudocode:
 *   countingSort(arr, n):
 *     max = max value in arr
 *     count[0..max] = 0
 *     for each x in arr: count[x]++
 *     for i from 1 to max: count[i] += count[i-1]
 *     build output using count[] (stable, traverse arr backwards)
 *     copy output back into arr
 * ===================================================== */
void countingSort(int arr[], int n) {
    if (n == 0) return;
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    int *count = calloc(max + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    copyArray(arr, output, n);

    free(count);
    free(output);
}

/* =====================================================
 * 8. RADIX SORT (LSD, base 10, non-negative integers)
 * -----------------------------------------------------
 * Pseudocode:
 *   radixSort(arr, n):
 *     max = max value in arr
 *     for exp = 1; max/exp > 0; exp *= 10:
 *       countingSortByDigit(arr, n, exp)
 *
 *   countingSortByDigit(arr, n, exp):
 *     stable counting sort using digit (arr[i]/exp) % 10
 * ===================================================== */
void countingSortByDigit(int arr[], int n, int exp) {
    int *output = malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    copyArray(arr, output, n);
    free(output);
}

void radixSort(int arr[], int n) {
    if (n == 0) return;
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(arr, n, exp);
}

/* =====================================================
 * 9. SHELL SORT
 * -----------------------------------------------------
 * Pseudocode:
 *   shellSort(arr, n):
 *     gap = n / 2
 *     while gap > 0:
 *       for i from gap to n-1:
 *         temp = arr[i]
 *         j = i
 *         while j >= gap and arr[j-gap] > temp:
 *           arr[j] = arr[j-gap]
 *           j -= gap
 *         arr[j] = temp
 *       gap /= 2
 * ===================================================== */
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

/* ---------- Driver ---------- */
int main(void) {
    int original[ARR_SIZE] = {64, 25, 12, 22, 11, 90, 5, 77, 30, 45};
    int arr[ARR_SIZE];

    printf("Original array: ");
    printArray(original, ARR_SIZE);
    printf("\n");

    copyArray(arr, original, ARR_SIZE);
    bubbleSort(arr, ARR_SIZE);
    printf("Bubble Sort:    ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    selectionSort(arr, ARR_SIZE);
    printf("Selection Sort: ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    insertionSort(arr, ARR_SIZE);
    printf("Insertion Sort: ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    mergeSort(arr, 0, ARR_SIZE - 1);
    printf("Merge Sort:     ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    quickSort(arr, 0, ARR_SIZE - 1);
    printf("Quick Sort:     ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    heapSort(arr, ARR_SIZE);
    printf("Heap Sort:      ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    countingSort(arr, ARR_SIZE);
    printf("Counting Sort:  ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    radixSort(arr, ARR_SIZE);
    printf("Radix Sort:     ");
    printArray(arr, ARR_SIZE);

    copyArray(arr, original, ARR_SIZE);
    shellSort(arr, ARR_SIZE);
    printf("Shell Sort:     ");
    printArray(arr, ARR_SIZE);

    return 0;
}