#include<stdio.h>

void swap_val(int num1, int num2);
void swap_ref(int* num1, int* num2);

int main() {
    int a,b;

    printf("Enter two nos : ");
    scanf("%d %d",&a,&b);

    printf("Given nos : %d, %d\n",a,b);

    swap_val(a,b);
    printf("After swap by values attempt : %d, %d\n",a,b);

    swap_ref(&a,&b);
    printf("After swap by reference attempt : %d, %d\n",a,b);

    return 0;
}

// normal 3rd variable swap
// Note : swap by value dosen't work
void swap_val(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// By reference swap
// Note : works
void swap_ref(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
