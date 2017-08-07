#include<stdio.h>

/*
The program checks whether a num is prime or not
*/

// all prototypes of user defined function
int max(int num1, int num2);   // return 1 if prime, else 0

int main() {
    int num1,num2,numMax,i;

    // take a no
    printf("Enter 10 nos : ");

    // first scanf two first and store
    scanf("%d %d",&num1,&num2);
    numMax = max(num1,num2);

    // loop to take other 8 nos, and compare on the fly
    for(i=3;i<=10;i++){
        scanf("%d",&num1);
        numMax = max(numMax,num1);
    }

    // o/p max
    printf("Max of given : %d\n",numMax);

    return 0;
}

int max(int num1, int num2) {
    /*
    find and return max of two nums
    *using ternary operator*
    */
    return (num1>num2)?num1:num2;
}
