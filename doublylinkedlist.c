// Design, develop, and execute a program in C to implement a doubly linked list where each node consists of integers. The program should support the following operations:
// Create a doubly linked list by adding each node at the front.
// Insert a new node to the left of the node whose key value is read as an input.
// Delete the node of a given data if it is found, otherwise display appropriate message.
// Display the contents of the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

void insert_front(int item, NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (first == NULL)
    {
        first = temp;
        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
    return first;
}

void insert_left(int item, int key, NODE first)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (first->data == key)
    {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
        return;
    }
    prev = NULL;
    cur = first;
    while (cur != NULL)
    {
        if (cur->data == key)
            break;
        prev = cur;
        cur = cur->rlink;
    }
    if (cur == NULL)
    {
        printf("Key not found\n");
        return;
    }
    prev->rlink = temp;
    temp->llink = prev;
    temp->rlink = cur;
    cur->llink = temp;
    return first;
}

NODE delete(int item, NODE first)
{
    NODE temp, prev, cur;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    if (first->data == item)
    {
        temp = first;
        first = first->rlink;
        printf("Deleted item is %d\n", temp->data);
        free(temp);
        return first;
    }
    prev = NULL;
    cur = first;
    while (cur != NULL)
    {
        if (cur->data == item)
            break;
        prev = cur;
        cur = cur->rlink;
    }
    if (cur == NULL)
    {
        printf("Item not found\n");
        return first;
    }
    prev->rlink = cur->rlink;
    if (cur->rlink != NULL)
        cur->rlink->llink = prev;
    free(cur);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}
void main()
{
    NODE first = NULL;
    int choice, item, key;
    for (;;)
    {
        printf("1:Insert front\n2:Insert left\n3:Delete\n4:Display\n5:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            first = insert_front(item, first);
            break;
        case 2:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            printf("Enter the key\n");
            scanf("%d", &key);
            first = insert_left(item, key, first);
            break;
        case 3:
            printf("Enter the item to be deleted\n");
            scanf("%d", &item);
            first = delete (item, first);
            break;
        case 4:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}