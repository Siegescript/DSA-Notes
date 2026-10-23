#include <stdio.h>
#include <stdlib.h>

// Time Complexity: Best: O(n + k), Average: O(n + k), Worst: O(n + k) (where k = range of values)
// Space Complexity: O(n + k)
// Stability: Stable
typedef int ElementType;

// Core API
void countingSort(ElementType arr[], int size);

// Utility
void printArray(const ElementType arr[], int size);

int main(void) {
    ElementType small_array[] = {9, 1, 10, 3, 2, 8, 4, 6, 5, 7};
    ElementType large_array[] = {
        77, 20, 31, 74, 49, 98, 16, 94,  8, 48,
        51,  5, 23, 88, 52, 34, 68, 37, 90, 100,
        41, 44,  2, 46, 61, 53, 14, 32, 36, 22,
        54, 59, 72,  4, 43, 10, 40,  7, 89,  6,
        99, 29, 56,  3, 30, 39, 21,  1, 75, 83,
        95, 63, 35, 38, 45, 50, 85, 81, 26, 60,
        80, 78, 76, 55, 19, 11, 69,  9, 71, 96,
        28, 24, 15, 73, 64, 97, 67, 79, 84, 62,
        57, 91, 27, 58, 65, 70, 13, 18, 93, 12,
        66, 17, 25, 92, 33, 47, 82, 42, 87, 86
    };

    int size_small = sizeof(small_array) / sizeof(small_array[0]);
    int size_large = sizeof(large_array) / sizeof(large_array[0]);

    printf("--- Small Array (Unsorted) ---\n");
    printArray(small_array, size_small);
    
    countingSort(small_array, size_small);
    
    printf("\n--- Small Array (Sorted via Counting Sort) ---\n");
    printArray(small_array, size_small);

    printf("\n--- Large Array (Sorted via Counting Sort) ---\n");
    countingSort(large_array, size_large);
    printArray(large_array, size_large);

    return 0;
}

void countingSort(ElementType arr[], int size) {
    if (size <= 1) return;

    // 1. Find min and max values to handle ranges efficiently
    ElementType max = arr[0];
    ElementType min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min +1;

    // 2. Allocate heap memory for frequency count and output arrays
    int *count = calloc(range, sizeof(int));
    ElementType *output = malloc(sizeof(ElementType) * size);

    if (count == NULL || output == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed.\n");
        free(count);
        free(output);
        exit(EXIT_FAILURE);
    }

    // 3. Store frequency of each element
    for (int i = 0; i < size; i++) {
        count[arr[i] - min]++;
    }

    // 4. Change count[i] so that count[i] contains actual position in output[]
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 5. Build output array in reverse order to preserve stability
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // 6. Copy output array back to arr[]
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    // Free allocated memory
    free(count);
    free(output);
}

void printArray(const ElementType arr[], int size) {
    printf("{");
    for (int n = 0; n < size; n++) {
        printf("%d", arr[n]);
        if (n < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}