#include<stdio.h>

typedef int ElementType;

// Core API
void selectionSort(ElementType arr[], int size);

// Internal Helper
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
    
    selectionSort(small_array, size_small);
    
    printf("\n--- Small Array (Sorted) ---\n");
    printArray(small_array, size_small);

    printf("\n--- Large Array (Sorted) ---\n");
    selectionSort(large_array, size_large);
    printArray(large_array, size_large);

    return 0;
}

void selectionSort(ElementType arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int ndx = i + 1; ndx < size; ndx++) {
            if (arr[ndx] < arr[min]) {
                min = ndx;
            }
        }
        if (min != i) {
            swap(&arr[min], &arr[i]);
        }
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