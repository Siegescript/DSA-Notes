#include <stdio.h>
#include <stdlib.h>

// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
// Space Complexity: O(n)
// Stability: Stable
typedef int ElementType;

// Core API
void mergeSort(ElementType arr[], int left, int right);

// Internal Helper
static void merge(ElementType arr[], int left, int mid, int right);

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
    
    mergeSort(small_array, 0, size_small - 1);
    
    printf("\n--- Small Array (Sorted) ---\n");
    printArray(small_array, size_small);

    printf("\n--- Large Array (Sorted) ---\n");
    mergeSort(large_array, 0, size_large - 1);
    printArray(large_array, size_large);

    return 0;
}

void mergeSort(ElementType arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

static void merge(ElementType arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    ElementType *L = malloc(sizeof(ElementType) * n1);
    ElementType *R = malloc(sizeof(ElementType) * n2);

    if (L == NULL || R == NULL) {
        printf("CRITICAL ERROR: Memory allocation failed during merge.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void printArray(const ElementType arr[], int size) {
    printf("{");
    for (int n = 0; n < size; n++) {
        printf("%d", arr[n]);
        if (n < size-1) {
            printf(", ");
        }
    }
    printf("}\n");
}