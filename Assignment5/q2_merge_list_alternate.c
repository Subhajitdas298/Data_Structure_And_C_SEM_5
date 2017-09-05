#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void init_list(Node** list) {
    *list = NULL;
}

Node* allocate_node(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
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

int getValue() {
    int val;
    scanf("%d",&val);
    return val;
}

void getList(Node** list, int size) {
    int i;
    for(i=0; i<size; i++) {
        append(list, getValue());
    }
}

void mergeListAlt(Node** list1, Node** list2) {
    Node *temp1,*temp2;
    temp1 = *list1;
    temp2 = *list2;
    while(temp1!=NULL && temp2!=NULL) {
        *list2=temp2->next;
        temp2->next=temp1->next;
        temp1->next=temp2;

        temp1=temp1->next->next;
        temp2 = *list2;
    }
}

int insert_pos(Node** list, int data, int pos) {
    Node* head = *list;
    Node* temp=head;
    Node* temp2;

    if(pos <= 0) {
        insert(list,data);
    } else {
        pos--;
        while(pos--) {
            if(temp->next==NULL) return 0;
            temp=temp->next;
        }
        temp2 = allocate_node(data);
        temp2->next = temp->next;
        temp->next = temp2;
    }
    return 1;
}

int main() {
    Node **list1, **list2, *head1, *head2;
    list1 = &head1;
    list2 = &head2;

    int size, i;

    init_list(list1);
    init_list(list2);

    printf("Enter size of lists : ");
    size = getValue();

    printf("Enter all elements of List1 : ");
    getList(list1,size);
    display(list1);
    printf("\n");

    printf("Enter all elements of List2 : ");
    getList(list2,size);
    display(list2);
    printf("\n");

    mergeListAlt(list1,list2);

    printf("After merging list :-\n");
    display(list1);
    printf("\n");

    while(1) {
        printf("Enter a new value (0/1) ? : ");
        if(getValue() == 1) {
            printf("Data and Position (0 indexed) : ");
            if(insert_pos(list1,getValue(),getValue())) {
                printf("Done\n");
            }else{
                printf("Out of range\n");
            }
            display(list1);
            printf("\n");
        } else {
            printf("Exiting\n");
            exit(0);
        }
    }

    // free memory
    while(!empty_list(list1))
        del(list1);

    return 0;
}

