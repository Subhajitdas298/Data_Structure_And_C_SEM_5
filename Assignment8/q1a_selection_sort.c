#include<stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary
    // of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element
        // in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Function to copy an array */
void copyArray(int fromArr[], int toArr[],
               int size) {
    int i;
    for (i=0; i < size; i++)
        toArr[i] = fromArr[i];
}

int main() {
    int data[] = {27,10,36,80,25,45};
    int arr1[6];

    int n = sizeof(data)/sizeof(data[0]);

    // selection

    copyArray(data, arr1, n);

    printf("Before selection sort : ");
    printArray(arr1,n);

    selectionSort(arr1, n);

    printf("After selection sort : ");
    printArray(arr1,n);

    return 0;
}
