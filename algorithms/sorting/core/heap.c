#include<stdio.h>

// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
// Space Complexity: O(1) auxiliary space
// Stability: Unstable
typedef int ElementType;

// Core API
void heapSort(ElementType arr[], int size);

// Internal Helpers (Refer to max_heap.c)
static void heapify(ElementType arr[], int size, int index);
static void swap(ElementType *a, ElementType *b);

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
    
    heapSort(small_array, size_small);
    
    printf("\n--- Small Array (Sorted via HeapSort) ---\n");
    printArray(small_array, size_small);

    printf("\n--- Large Array (Sorted via HeapSort) ---\n");
    heapSort(large_array, size_large);
    printArray(large_array, size_large);

    return 0;
}

void heapSort(ElementType arr[], int size) {
    // 1. Build Max-Heap (bottom-up heapify starting at last parent node)
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // 2. Extract max element repeatedly and place at the end of the array
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move root (current max) to end
        heapify(arr, i, 0);     // Restore heap property on reduced heap size
    }
}

static void heapify(ElementType arr[], int size, int i) {
    int maxIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[maxIndex]) {
        maxIndex = left;
    }

    if (right < size && arr[right] > arr[maxIndex]) {
        maxIndex = right;
    }    

    if(maxIndex != i) {
        swap(&arr[i], &arr[maxIndex]);
        heapify(arr, size, maxIndex);
    }
}

static void swap(ElementType *a, ElementType *b) {
    ElementType tmp = *a;
    *a = *b;
    *b = tmp;
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