#include<stdio.h>

int main() {
    int num,pow;

    printf("Enter a no : ");
    scanf("%d",&num);

    printf("Enter power : ");
    scanf("%d",&pow);

    printf("%d^%d = %d",num,pow,intpow(num,pow));

    return 0;
}

/*
generates n^m as:
n^m = n*n^(m-1) = n*n*n^(m-2) ...
upto power becomes 0
*/
int intpow(int n, int m) {
    if(m == 0) return 1;
    else return (n*intpow(n,m-1));
}
