#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main() {
    int s,*arr,i;
    int lgst1=INT_MIN,lgst2=INT_MIN,lgst3=INT_MIN;

    printf("How many nos? : ");
    scanf("%d",&s);

    // dynamically allocating array
    arr = (int*)malloc(s*sizeof(int));

    printf("Enter %d nos : ",s);

    for(i=0; i<s; i++) {
        scanf("%d",arr+i);

        if(arr[i]>lgst1) {
            lgst3 = lgst2;
            lgst2 = lgst1;
            lgst1 = arr[i];
        } else if(arr[i]<lgst1 && arr[i]>lgst2) {
            lgst3 = lgst2;
            lgst2 = arr[i];
        } else if(arr[i]<lgst2 && arr[i]>lgst3) {
            lgst3 = arr[i];
        }
    }

    printf("Largest 3 nos : %d %d %d",lgst1,lgst2,lgst3);

    return 0;
}
