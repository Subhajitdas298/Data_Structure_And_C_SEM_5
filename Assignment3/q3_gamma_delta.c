#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int isVowel(char c) {
    switch(c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        return 1;
    default:
        return 0;
    }
}

int main() {
    int w, i, count = 0;
    char *delta,*gamma;

    delta = (char*)malloc(0);

    printf("Enter size of array (w) : ");
    scanf("%d",&w);

    gamma = (char*)malloc(sizeof(char)*w);

    printf("Enter the array : ");

    for(i = 0; i < w; i++) {
        scanf("%c",&gamma[i]);
        while(isspace(gamma[i]))
            scanf("%c",&gamma[i]);

        if(!isVowel(gamma[i])) {
            count++;
            delta = (char*)realloc(delta,sizeof(char)*count);
            delta[count-1] = gamma[i];
        }
    }

    printf("gamma : ");

    for(i = 0; i < w; i++)
        printf("%c ",gamma[i]);
    printf("\n");

    printf("delta : ");

    for(i = 0; i < count; i++)
        printf("%c ",delta[i]);
    printf("\n");

    // free memory
    free(gamma);
    free(delta);

    return 0;
}
