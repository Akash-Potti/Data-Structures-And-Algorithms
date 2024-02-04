#include <stdio.h>
#include <stdlib.h>

#define stacksize 10
void push(int a[], int *top, int item)
{
    if (*top == stacksize - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    a[*top] = item;
}

void pop(int a[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    int item = a[*top];
    printf("The popped element is %d\n", item);
    *top = *top - 1;
}

void display(int a[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The elements of the stack are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main()
{
    int i, choice, a[stacksize], top = -1, item;
    while (1)
    {
        printf("1. Push 2) Pop 3) Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &item);
            push(a, &top, item);
            break;
        case 2:
            pop(a, &top);
            break;
        case 3:
            display(a, top);
            break;

        default:
            exit(0);
        }
    }
}