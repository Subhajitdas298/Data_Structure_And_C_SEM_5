#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *below;
} Node;

void push(Node** stack, int data) {
    Node* top = *stack;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->below = top;
    *stack = n;
}

void pop(Node** stack) {
    Node* top = *stack;
    if(top == NULL) printf("Stack is empty");
    else {
        printf("%d", top->data);
        *stack = top->below;
        free(top);
    }
}

void peep(Node** stack) {
    Node* top = *stack;
    if(top == NULL) printf("Stack is empty");
    else printf("%d", top->data);
}

int main() {
    Node *top = NULL;
    Node **stack = &top;

    int op, val;

    printf("\n1. Push\n");
    printf("2. Pop\n");
    printf("3. Peep\n");
    printf("0. Exit\n");

    while(1) {
        printf("Enter option : ");
        scanf("%d",&op);

        switch(op) {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter value to push : ");
            scanf("%d",&val);
            push(stack,val);
            printf("Done\n");
            break;
        case 2:
            printf("Pop : ");
            pop(stack);
            printf("\n");
            break;
        case 3:
            printf("Peep : ");
            peep(stack);
            printf("\n");
            break;
        default:
            printf("Invalid option.\n");
        }

    }

    return 0;
}
