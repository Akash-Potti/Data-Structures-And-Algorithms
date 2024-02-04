#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = first;
    first = temp;
    return first;
}

NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    NODE temp;
    temp = first;
    first = first->link;
    printf("The deleted element is %d\n", temp->info);
    free(temp);
    return first;
}

void display(NODE first)
{
    NODE cur;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    cur = first;
    while (cur != NULL)
    {
        printf("%d ", cur->info);
        cur = cur->link;
    }
}

void main()
{
    NODE first = NULL;
    int item, choice;
    while (1)
    {
        printf("1) Insert 2) Delete 3) Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            first = insert_front(first, item);
            break;
        case 2:
            first = delete_front(first);
            break;
        case 3:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}