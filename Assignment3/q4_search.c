#include<stdio.h>
#include<stdlib.h>

int main() {
    int N, no, i, *arr, flag = 0;

    printf("Enter size of array (N) : ");
    scanf("%d",&N);

    arr = (int*)malloc(sizeof(int)*N);

    printf("Enter the array : ");

    for(i = 0; i < N; i++)
        scanf("%d",arr+i);

    printf("Enter no to be searched : ");
    scanf("%d",&no);

    for(i = 0; i < N; i++) {
        if(arr[i] == no) {
            printf("Position = %d\n",i);
            flag = 1;
            break;
        }
    }

    if(!flag)
        printf("Not in list\n");

    // free memory
    free(arr);

    return 0;
}
