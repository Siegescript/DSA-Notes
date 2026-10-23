#include <stdio.h>
#include <stdlib.h>

// Time Complexity: Best: O(d * (n + b)), Average: O(d * (n + b)), Worst: O(d * (n + b))
// (where d = number of digits, n = number of elements, b = base/radix = 10)
// Space Complexity: O(n + b)
// Stability: Stable
typedef int ElementType;

// Core API
void radixSort(ElementType arr[], int size);

// Internal Helpers
static void countSortByDigit(ElementType arr[], int size, int exp);
static ElementType getMax(const ElementType arr[], int size);

// Utility
void printArray(const ElementType arr[], int size);

int main(void) {
    ElementType small_array[] = {170, 45, 75, 90, 802, 24, 2, 66};
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
    
    radixSort(small_array, size_small);
    
    printf("\n--- Small Array (Sorted via Radix Sort) ---\n");
    printArray(small_array, size_small);

    printf("\n--- Large Array (Sorted via Radix Sort) ---\n");
    radixSort(large_array, size_large);
    printArray(large_array, size_large);

    return 0;
}

void radixSort(ElementType arr[], int size) {
    if (size <= 1) return;

    ElementType max = getMax(arr, size);

    // Apply counting sort to pass key digits (exp = 1, 10, 100...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortByDigit(arr, size, exp);
    }
}

static ElementType getMax(const ElementType arr[], int size) {
    ElementType max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

static void countSortByDigit(ElementType arr[], int size, int exp) {
    int count[10] = {0};
    ElementType *output = malloc(sizeof(ElementType) * size);

    if (output == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Store occurrence counts based on current digit
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Accumulate counts to find absolute output indices
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array backwards to guarantee STABILITY
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

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