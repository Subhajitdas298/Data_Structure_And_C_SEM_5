#include<stdio.h>

void print_fibonacci(int n);

int main() {
    int n;

    // printing first two fibonacci nos (0, 1)
    printf("How many terms (n)? : ");
    scanf("%d",&n);

    print_fibonacci(n);

    return 0;
}

void print_fibonacci(int n) {
    static int x=0,y=1,z;
    // end when no term to print

    if(n == 0) {
        x=0;
        y=1;
        printf("\n");
        return;
    }

    // for start of function, print x and y initial values
    if(x==0) {
        printf("%d %d ",x,y);
        n-=2;
    }

    z=x+y;
    printf("%d ",z);
    x=y;
    y=z;

    // call fibonacci again with deceased n
    n--;
    print_fibonacci(n);
}
