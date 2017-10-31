#include<stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* This function takes last element as pivot,
   places the pivot element at its correct position
   in sorted array, and places all smaller
  (smaller than pivot) to left of pivot and all
   greater elements to right of pivot */
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            // increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index,arr[p]
          is now at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int arr2[6];

    int n = sizeof(data)/sizeof(data[0]);

    // quick

    copyArray(data, arr2, n);

    printf("Before quick sort : ");
    printArray(arr2,n);

    quickSort(arr2, 0, n-1);

    printf("After quick sort : ");
    printArray(arr2,n);

    return 0;
}

