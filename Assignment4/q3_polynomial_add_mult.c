#include<stdio.h>
#include<stdlib.h>

int getPolynomial(int** polyPtr) {
    int *poly = (*polyPtr);
    int max, i;

    printf("Highest degree : ");
    scanf("%d",&max);

    poly = (int*)malloc(sizeof(int)*(max+1));

    for(i=0; i<=max; i++) {
        printf("Enter x^%d : ",i);
        scanf("%d",&poly[i]);
    }

    (*polyPtr) = poly;

    return max;
}

void showPolynomial(int *poly, int max) {
    int i;
    printf("Polynomial : ");
    for(i=max; i>=0; i--) {
        if(poly[i]!=0) {
            if(i!=max) printf(" + ");
            if(i==0)printf("%d",poly[i]);
            else if(i==1)printf("%dx",poly[i]);
            else printf("%dx^%d",poly[i],i);
        }
    }
    printf("\n");
}

int* getSum(int* poly1, int max1, int* poly2, int max2) {
    int max, i;
    int* sum;
    max = (max1>max2)?max1:max2;
    sum = (int*)calloc((max+1),sizeof(int));
    for(i=0; i<=max; i++) {
        if(i>max1) sum[i]=poly2[i];
        else if(i>max2) sum[i]=poly1[i];
        else sum[i]=poly1[i]+poly2[i];
    }
    return sum;
}

int* getMulti(int* poly1, int max1, int* poly2, int max2) {
    int max, i, j;
    int* mul;
    max = max1+max2;
    mul = (int*)calloc((max+1),sizeof(int));
    for(i=0; i<=max1; i++) {
        for(j=0; j<=max2; j++) {
            mul[i+j]+=poly1[i]*poly2[j];
        }
    }
    return mul;
}

int main() {
    int *poly1, *poly2;
    int *sum, *mul, i, j, max1, max2,max;

    printf("Enter polynomial 1 :-\n");
    max1 = getPolynomial(&poly1);
    showPolynomial(poly1, max1);

    printf("Enter polynomial 2 :-\n");
    max2 = getPolynomial(&poly2);
    showPolynomial(poly2, max2);

    // sum
    printf("Sum :-\n");
    max = (max1>max2)?max1:max2;
    sum = getSum(poly1,max1,poly2,max2);
    showPolynomial(sum,max);
    free(sum);

    // mul
    printf("Multiplication :-\n");
    max = max1+max2;
    mul = getMulti(poly1,max1,poly2,max2);
    showPolynomial(mul,max);
    free(mul);

    //free
    free(poly1);
    free(poly2);

    return 0;
}


