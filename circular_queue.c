#include <stdio.h>
#include <stdlib.h>
#define queuesize 5
void insert_rear(int *r, int *count, int a[], int item)
{
    if (*count == queuesize)
    {
        printf("Queue overflow\n");
        return;
    }
    *r = (*r + 1) % queuesize;
    a[*r] = item;
    *count = *count + 1;
}

void delete_front(int *f, int *count, int a[])
{
    if (*count == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    int item = a[*f];
    printf("The deleted element is %d\n", item);
    *f = (*f + 1) % queuesize;
    *count = *count - 1;
}

void display(int f, int a[], int count)
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements of the queue are: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", a[f]);
        f = (f + 1) % queuesize;
    }
}

void main()
{
    int a[queuesize], f = 0, r = -1, count = 0, item, choice;
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
            insert_rear(&r, &count, a, item);
            break;
        case 2:
            delete_front(&f, &count, a);
            break;
        case 3:
            display(f, a, count);
            break;
        default:
            exit(0);
        }
    }
}