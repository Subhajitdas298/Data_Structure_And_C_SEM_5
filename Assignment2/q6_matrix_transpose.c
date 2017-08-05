#include<stdio.h>
#include<stdlib.h>

int main() {
    int m,n,**matrix,**transpose,i,j;

    printf("Enter size of matrix (M x N) : ");
    scanf("%d %d",&m,&n);

    // dynamically allocating array for pointers to all rows
    matrix = (int*)malloc(m*sizeof(int));

    for(i=0; i<m; i++) {
        // dynamically allocating a row
        matrix[i] = (int*)malloc(n*sizeof(int));

        printf("Enter row %d : ",i+1);
        for(j=0; j<n; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Given matrix :\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    // generating transpose matrix
    // dynamically allocating array for pointers to all rows
    transpose = (int*)malloc(n*sizeof(int));

    printf("Transpose matrix :\n");
    for(i=0; i<n; i++) {
        // dynamically allocating a row
        transpose[i] = (int*)malloc(m*sizeof(int));

        for(j=0; j<m; j++) {
            transpose[i][j] = matrix[j][i];
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }

    // free up memory
    for(i=0; i<m; i++)
        free(matrix[i]);
    free(matrix);
    for(i=0; i<n; i++)
        free(transpose[i]);
    free(transpose);

    return 0;
}
