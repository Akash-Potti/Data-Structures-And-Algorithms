#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_rear(NODE first, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
    {
        first = temp;
        return first;
    }
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("Queue is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("The deleted element is %d\n", temp->info);
    free(temp);
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
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_rear(first, item);
            break;
        case 2:
            first = delete_rear(first);
            break;
        case 3:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}