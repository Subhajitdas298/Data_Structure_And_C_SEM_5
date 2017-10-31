#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};
typedef struct node n;

n* create_node(int);
void add_node();
void insert_at_first();
void insert_at_end();
void insert_at_position();
void delete_node_position();
void sort_list();
void update();
void search();
void display_from_beg();
void display_in_rev();

n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;

void main() {
    int ch;

    printf("1.Insert at beginning \n"
           "2.Insert at end\n"
           "3.Insert at position\n"
           "4.Sort linked list\n"
           "5.Delete node at position\n"
           "6.Update node value\n"
           "7.Search element \n"
           "8.Display list from beginning\n"
           "9.Display list from end\n"
           "10.Exit\n");

    while (1) {

        printf("\n\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1 :
            insert_at_first();
            break;
        case 2 :
            insert_at_end();
            break;
        case 3 :
            insert_at_position();
            break;
        case 4 :
            sort_list();
            break;
        case 5 :
            delete_node_position();
            break;
        case 6 :
            update();
            break;
        case 7 :
            search();
            break;
        case 8 :
            display_from_beg();
            break;
        case 9 :
            display_in_rev();
            break;
        case 10 :
            exit(0);
        case 11 :
            add_node();
            break;
        default:
            printf("Invalid choice");
        }
    }
}
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
n* create_node(int info) {
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
/*
 *ADDS NEW NODE
 */
void add_node() {

    int info;

    printf("Enter value : ");
    scanf("%d", &info);
    new = create_node(info);

    if (first == last && first == NULL) {

        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}
/*
 *INSERTS ELEMENT AT FIRST
 */
void insert_at_first() {

    int info;

    printf("Enter value : ");
    scanf("%d",&info);
    new = create_node(info);

    if (first == last && first == NULL) {
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
    }
    printf("Done");
}
/*
 *INSERTS ELEMNET AT END
 */
void insert_at_end() {

    int info;

    printf("Enter value : ");
    scanf("%d", &info);
    new = create_node(info);

    if (first == last && first == NULL) {
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
    printf("Done");
}
/*
 *INSERTS THE ELEMENT AT GIVEN POSITION
 */
void insert_at_position() {
    int info, pos, len = 0, i;
    n *prevnode;

    printf("Enter value : ");
    scanf("%d", &info);
    printf("Enter position : ");
    scanf("%d", &pos);
    new = create_node(info);

    if (first == last && first == NULL) {
        if (pos == 1) {
            first = last = new;
            first->next = last->next = NULL;
            first->prev = last->prev = NULL;
        } else
            printf("Empty linked list");
    } else {
        if (number < pos)
            printf("Invalid, Exceeding length");
        else {
            for (ptr = first, i = 1; i <= number;
                    i++) {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1) {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    printf("Done");
                    break;
                }
            }
        }
    }
}
/*
 *SORTING IS DONE OF ONLY NUMBERS NOT LINKS
 */
void sort_list() {
    n *temp;
    int tempval, i, flag = 1;

    if (first == last && first == NULL)
        printf("List is empty");
    else {
        while(flag) {
            flag = 0;
            for (ptr = first,i = 0; i < number-1;
                    ptr = ptr->next,i++) {
                temp = ptr->next;
                if (ptr->val > temp->val) {
                    tempval = ptr->val;
                    ptr->val = temp->val;
                    temp->val = tempval;
                    flag = 1;
                }
            }
        }
    }
}
/*
 *DELETION IS DONE
 */
void delete_node_position() {
    int pos, count = 0, i;
    n *temp, *prevnode;

    printf("Enter position :");
    scanf("%d", &pos);

    if (first == last && first == NULL)
        printf("Invalid, Empty linked list");

    else {
        if (number < pos)
            printf("Invalid, Exceeding length");

        else {
            for (ptr = first,i = 1; i <= number;
                    i++) {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1) {
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("%d is deleted",
                           prevnode->val);
                    free(prevnode);
                    break;
                } else if (i == pos - 1) {
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("%d is deleted",
                           ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
    }
}
/*
 *UPDATION IS DONE FRO GIVEN OLD VAL
 */
void update() {
    int oldval, newval, i, f = 0;
    printf("Enter old value:");
    scanf("%d", &oldval);
    printf("Enter new value:");
    scanf("%d", &newval);
    if (first == last && first == NULL)
        printf("List is empty");
    else {
        for (ptr = first, i = 0; i < number;
                ptr = ptr->next,i++) {
            if (ptr->val == oldval) {
                ptr->val = newval;
                printf("Done");
                f = 1;
            }
        }
        if (f == 0)
            printf("Invalid, no such value");
    }
}
/*
 *SEARCHING USING SINGLE KEY
 */
void search() {
    int count = 0, key, i, f = 0;

    printf("Enter value to search :");
    scanf("%d", &key);

    if (first == last && first == NULL)
        printf("Invalid, list is empty");
    else {
        for (ptr = first,i = 0; i < number;
                i++,ptr = ptr->next) {
            count++;
            if (ptr->val == key) {
                printf("Found at position %d",
                       count);
                f = 1;
            }
        }
        if (f == 0)
            printf("The value is not found");
    }
}
/*
 *DISPLAYING IN BEGINNING
 */
void display_from_beg() {
    int i;
    if (first == last && first == NULL)
        printf("List is empty");
    else {
        for (ptr = first, i = 0; i < number;
                i++,ptr = ptr->next)
            printf("%d ", ptr->val);
    }
}
/*
 * DISPLAYING IN REVERSE
 */
void display_in_rev() {
    int i;
    if (first == last && first == NULL)
        printf("List is empty");
    else {
        for (ptr = last, i = 0; i < number;
                i++,ptr = ptr->prev) {
            printf("%d ", ptr->val);
        }
    }
}
