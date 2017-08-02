#include<stdio.h>

/*
The program checks whether a num is prime or not
*/

// all prototypes of user defined function
int isPrime(int num);   // return 1 if prime, else 0

int main() {
    int num;

    // take a no
    printf("Enter a no : ");
    scanf("%d",&num);

    // check and print prime
    if(isPrime(num)) {
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }

    return 0;
}

int isPrime(int num) {
    int i;
    /*
    try to divide the num from 2 to num/2(approximate to nearest int)
    if found divisible return 0 (representing 'not prime')
    else at the end return 1 (representing 'prime')
    */
    for(i=2; i<=num/2; i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}
