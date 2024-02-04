#include <stdio.h>
#include <process.h>

#define queue_size 5

void insert_rear(int a[], int *r, int item)
{
    if (*r == queue_size - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    *r = *r + 1;
    a[*r] = item;
}

void delete_front(int a[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("Queue underflow\n");
        return;
    }
    int item = a[*f];
    printf("The deleted element is %d\n", item);
    *f = *f + 1;
    if (*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int a[], int f, int r)
{
    if (f > r)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements of the queue are: ");
    for (int i = f; i <= r; i++)
    {
        printf("%d ", a[i]);
    }
}

void main()
{
    int a[queue_size], f = 0, r = -1, item, choice;
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
            insert_rear(a, &r, item);
            break;
        case 2:
            delete_front(a, &f, &r);
            break;
        case 3:
            display(a, f, r);
            break;
        default:
            exit(0);
        }
    }
}