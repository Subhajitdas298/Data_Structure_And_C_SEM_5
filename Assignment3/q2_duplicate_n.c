#include<stdio.h>
#include<stdlib.h>

int isNotChecked(int no, int* checkList, int listSize) {
    int i;
    for(i = 0; i < listSize; i++)
        if(no == checkList[i])
            return 0;
    return 1;
}

int main() {
    int N, i, j, *arr, *checkList, listSize=0, flag = 1;

    printf("Enter size of array (N) : ");
    scanf("%d",&N);

    arr = (int*)malloc(sizeof(int)*N);

    for(i = 0; i < N; i++) {
        printf("Enter arr[%d] : ",i);
        scanf("%d",arr+i);
        while(arr[i] < 1 || arr[i] > N) {
            printf("Invalid no.\nEnter arr[%d] : ",i);
            scanf("%d",arr+i);
        }

    }

    printf("\n");

    // print array
    printf("Given array :\n");
    for(i = 0; i < N; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("\n");

    // checks for duplicates
    checkList = (int*)malloc(sizeof(int)*N);

    for(i = 0; i < N; i++) {
        if(isNotChecked(arr[i], checkList, listSize)) {
            for(j = 0; j < N; j++) {
                if(i == j) continue;
                if(arr[i] == arr[j]) {
                    flag = 0;
                    printf("Duplicate of arr[%d](=%d) at [%d]\n",i,arr[i],j);
                }
            }
            checkList[listSize] = arr[i];
            listSize++;
        }
    }

    if(flag) {
        printf("No duplicate found in array.\n");
    }

    // free memory
    free(arr);
    free(checkList);

    return 0;
}
