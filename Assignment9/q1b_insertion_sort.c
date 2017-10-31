#include<stdio.h>

/* Function to sort an array using
 insertion sort*/
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        /* Move elements of arr[0..i-1],
           that are greater than key,
          to one position ahead of
          their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
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

    // insertion

    copyArray(data, arr2, n);

    printf("Before insertion sort : ");
    printArray(arr2,n);

    insertionSort(arr2, n);

    printf("After insertion sort : ");
    printArray(arr2,n);

    return 0;
}

