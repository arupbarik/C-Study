#include <stdio.h>

int main() {
    int arr[100], n, i, pos, value;
    int choice;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nMenu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // ---- INSERTION ----
        printf("Enter the position to insert (1 to %d): ", n + 1);
        scanf("%d", &pos);

        printf("Enter the value to insert: ");
        scanf("%d", &value);

        if (pos < 1 || pos > n + 1) {
            printf("Invalid position!\n");
        } else {
            // Shift elements to the right to make space
            for (i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = value;
            n++;  // Increase array size count

            printf("\nArray after insertion:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    else if (choice == 2) {
        // ---- DELETION ----
        printf("Enter the position to delete (1 to %d): ", n);
        scanf("%d", &pos);

        if (pos < 1 || pos > n) {
            printf("Invalid position!\n");
        } else {
            printf("Deleted element: %d\n", arr[pos - 1]);

            // Shift elements to the left to fill the gap
            for (i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;  // Decrease array size count

            printf("\nArray after deletion:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}