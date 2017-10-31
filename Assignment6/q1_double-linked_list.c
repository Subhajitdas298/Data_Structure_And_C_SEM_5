#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} Node;

void init_list(Node** list) {
    *list = NULL;
}

Node* allocate_node(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

int empty_list(Node** list) {
    Node* head = *list;
    if(head == NULL) return 1;
    else return 0;
}

void insert(Node** list, int data) {
    Node* head = *list;
    Node* temp=allocate_node(data);
    temp->next=head;
    if(!empty_list(list))
        head->prev=temp;
    *list = temp;
}

void append(Node** list, int data) {
    Node* head = *list;
    Node* temp = head;

    if(empty_list(list)) {
        insert(list, data);
    } else {
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next=allocate_node(data);
        temp->next->prev=temp;
    }
}

void display(Node** list) {
    Node* head = *list;
    Node* temp = head;

    if(empty_list(list)) {
        printf("List is empty");
    } else {
        printf("List : ");
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void display_rev(Node** list) {
    Node* head = *list;
    Node* temp = head;

    if(empty_list(list)) {
        printf("List is empty");
    } else {
        printf("List : ");
        // getting last element
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        // traversing back
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp = temp->prev;
        }
    }
}

int search(Node** list,int data) {
    Node* head = *list;
    Node* temp = head;

    int i = 0;

    while(temp!=NULL) {
        i++;
        if(temp->data==data) {
            return i;
        } else {
            temp=temp->next;
        }
    }
    return 0;
}

void del(Node** list) {
    Node* head = *list;
    Node* temp = head;

    if(!empty_list(list)) {    // continue if not blank/null
        if(temp->next!=NULL) {    // not single element
            while(temp->next->next!=NULL) {
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
        } else {    // remove only element
            free(temp);
            *list = NULL;
        }
    }
}

void sort_list(Node** list) {
    Node* head = *list;
    Node* temp = head;
    Node* temp2;
    int flag = 1;

    while(!empty_list(list) && head->next!=NULL && flag) {    // continue if not blank/null
        flag = 0;
        temp = head;
        while(temp->next!=NULL) {
            if(temp->data > temp->next->data) {
                temp->next->prev = temp->prev;
                temp->prev=temp->next;
                if(temp->next->next!=NULL)
                    temp->next->next->prev=temp;
                temp->next=temp->next->next;
                temp->prev->next=temp;
                if(temp!=head) {
                    temp->prev->prev->next=temp->prev;
                } else {
                    head = temp->prev;
                    *list = head;
                }
                flag = 1;
            } else {
                temp=temp->next;
            }
        }
    }
}

void dupli(Node** list) {
    Node* head = *list;
    Node* temp = head;
    Node* temp2;
    Node* temp3;

    while(temp!=NULL && temp->next!=NULL) {    // continue if not blank/null
        temp3 = temp;
        temp2 = temp3->next;
        while(temp2!=NULL) {
            if(temp->data == temp2->data) {
                temp3->next=temp2->next;
                if(temp3->next!=NULL)
                    temp3->next->prev=temp3;
                free(temp2);
            } else {
                temp3=temp3->next;
            }
            temp2 = temp3->next;
        }
        temp = temp->next;
    }
}

int getValue() {
    int val;
    scanf("%d",&val);
    return val;
}

void showOption() {
    printf("\n");
    printf("1. Initialize list\n");
    printf("2. Check if list is empty\n");
    printf("3. Insert a node at beginning\n");
    printf("4. Append a node at end\n");
    printf("5. Display the list\n");
    printf("6. Display the list reverse\n");
    printf("7. Search\n");
    printf("8. Delete last node\n");
    printf("9. Sort the list\n");
    printf("10. Remove all duplicates\n");
    printf("11. Exit\n");
}

void work(Node** list, char op) {
    int val;
    switch(op) {
    case 1:
        init_list(list);
        printf("Initialization Done\n");
        break;
    case 2:
        if(empty_list(list)) printf("List is empty.\n");
        else printf("List is not empty.\n");
        break;
    case 3:
        printf("Enter value to insert : ");
        val = getValue();
        insert(list,val);
        printf("Done\n");
        break;
    case 4:
        printf("Enter value to append : ");
        val = getValue();
        append(list,val);
        printf("Done\n");
        break;
    case 5:
        display(list);
        printf("\n");
        break;
    case 6:
        display_rev(list);
        printf("\n");
        break;
    case 7:
        printf("Enter value to search : ");
        val = getValue();
        if(search(list,val)) printf("Value if found\n");
        else printf("Value is not found\n");
        break;
    case 8:
        del(list);
        printf("Done\n");
        break;
    case 9:
        sort_list(list);
        printf("Sorting Done\n");
        break;
    case 10:
        dupli(list);
        printf("Duplicate removal Done\n");
        break;
    case 11:
        printf("Enter 0 to exit : ");
        val = getValue();
        if(val==0) {
            while(!empty_list(list))
                del(list);
            exit(0);
        }
        break;
    default:
        printf("Invalid option\n");
    }
}

int main() {
    Node** list, *head;
    list = &head;

    showOption();

    while(1) {
        printf("\nEnter your option : ");
        work(list,getValue());
    }

    return 0;
}
