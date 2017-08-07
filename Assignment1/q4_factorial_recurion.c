#include<stdio.h>

int factorial(int num);

int main() {
    int n,fact;

    printf("Enter no : ");
    scanf("%d",&n);

    fact = factorial(n);

    printf("Factorial(%d) = %d\n",n,fact);

    return 0;
}

/*
Factorial is generated as,
number * (number-1)
stop when number equals 1
*/
int factorial(int num) {
    if(num<=1) return 1;
    return num * factorial(num-1);
}
