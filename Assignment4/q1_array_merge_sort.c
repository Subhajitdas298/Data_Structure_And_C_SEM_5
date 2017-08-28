#include<stdio.h>
#include<stdlib.h>

int compfunc(const void *a, const void *b) {
    return (*(int*)a-*(int*)b);
}

int main() {
    int arr1[] = {2,14,36,48,56}, arr2[] = {5,10,26,31,39,45};
    int *arr, i,j,n1,n2;

    n1 = sizeof(arr1)/sizeof(arr1[0]);
    n2 = sizeof(arr2)/sizeof(arr2[0]);

    arr = (int*)malloc(sizeof(arr1)+sizeof(arr2));

    for(i=0; i<sizeof(arr1)/sizeof(int); i++)
        arr[i]=arr1[i];

    for(j=i; j<i+sizeof(arr2)/sizeof(int); j++)
        arr[j]=arr2[j-i];

    qsort(arr,(n1+n2),sizeof(int),compfunc);

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
