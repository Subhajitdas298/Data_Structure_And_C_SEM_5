#include<stdio.h>

int main() {
    int x=0,y=1,z,count=0;

    // printing first two fibonacci nos (0, 1)
    printf("Fibonacci series : %d %d ",x,y);

    // loopintg through to get other 13 nos
    // count goes upto 15, thous total 15 nos are printed
    for(count=3; count<=15; count++) {
        z=x+y;
        printf("%d ",z);
        x=y;
        y=z;
    }

    printf("\n");

    return 0;
}
