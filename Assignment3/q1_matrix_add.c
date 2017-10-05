#include<stdio.h>
#include<stdlib.h>

int main() {
    int m1,n1,m2,n2,**mx1,**mx2,i,j,k,temp;

    printf("Enter size of matrix 1 (M1 x N1) : ");
    scanf("%d %d",&m1,&n1);

    // dynamically allocating array for pointers to all rows
    mx1 = (int**)malloc(m1*sizeof(int*));

    for(i=0; i<m1; i++) {
        // dynamically allocating a row
        mx1[i] = (int*)malloc(n1*sizeof(int));

        printf("Enter row %d : ",i+1);
        for(j=0; j<n1; j++) {
            scanf("%d",&mx1[i][j]);
        }
    }

    printf("\n");

    printf("Enter size of matrix 2 (M2 x N2) : ");
    scanf("%d %d",&m2,&n2);

    // dynamically allocating array for pointers to all rows
    mx2 = (int**)malloc(m2*sizeof(int*));

    for(i=0; i<m2; i++) {
        // dynamically allocating a row
        mx2[i] = (int*)malloc(n2*sizeof(int));

        printf("Enter row %d : ",i+1);
        for(j=0; j<n2; j++) {
            scanf("%d",&mx2[i][j]);
        }
    }

    printf("\n");

    // addition
    if(m1 != m2 || n1 != n2) {
        printf("Addition is not possible.\n");
    } else {
        printf("Addition :\n");

        for(i=0; i<m1; i++) {
            for(j=0; j<n1; j++) {
                printf("%d ",mx1[i][j]+mx2[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n");

    // multiplication
    if(n1 != m2) {
        printf("Multiplication is not possible.\n");
    } else {
        printf("Multiplication :\n");

        for(i=0; i<m1; i++) {
            for(j=0; j<n2; j++) {
                temp = 0;
                for(k=0; k<n1; k++) {
                    temp += mx1[i][k]*mx2[k][j];
                }
                printf("%d ",temp);
            }
            printf("\n");
        }
    }

    // free memory
    for(i=0; i<m1; i++) {
        free(mx1[i]);
    }
    free(mx1);
    for(i=0; i<m2; i++) {
        free(mx2[i]);
    }
    free(mx2);

    return 0;
}
