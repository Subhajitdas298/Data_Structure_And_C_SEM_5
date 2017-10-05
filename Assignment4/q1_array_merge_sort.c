#include<stdio.h>
#include<stdlib.h>

int main() {
    int arr1[] = {2,14,36,48,56}, arr2[] = {5,10,26,31,39,45};
    int *arr, i,j,n1,n2;

    n1 = sizeof(arr1)/sizeof(arr1[0]);
    n2 = sizeof(arr2)/sizeof(arr2[0]);

    arr = (int*)malloc(sizeof(arr1)+sizeof(arr2));

    for(i=0; i<n1; i++)
        arr[i]=arr1[i];

    for(j=i; j<i+n2; j++)
        arr[j]=arr2[j-i];

    // sort
    for(i = 0; i < (n1+n2-1); i++){
        for(j = 0; j < (n1+n2-1-i); j++){
            if(arr[j] > arr[j+1]){
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }

    //Displaying elements of array 'arr1'
    printf("Array 1 is :");
    for (i = 0; i < n1; i++)
        printf("%d ", arr1[i]);

    //Displaying elements of array 'arr2'
    printf("\nArray 2 is :");
    for (i = 0; i < n2; i++)
        printf("%d ", arr2[i]);

    //Displaying elements of array 'res'
    printf("\nMerged array is :");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
