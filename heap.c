#include <stdio.h>
#include <stdlib.h>
#define maxsize 20

int insert(int item, int a[], int n)
{
    int i, c, p;
    if (n == maxsize)
    {
        printf("Heap is full\n");
        return n;
    }
    c = ++n;
    p = c / 2;
    while (p >= 1 && item > a[p])
    {
        a[c] = a[p];
        c = p;
        p = c / 2;
    }
    a[c] = item;
    return n;
}

int delete(int a[], int n)
{
    int item, p, c;
    if (n == 0)
    {
        printf("Heap is empty\n");
        return n;
    }
    item = a[1];
    printf("Deleted item is %d\n", item);
    item = a[n--];
    p = 1;
    c = 2;
    while (c <= n)
    {
        if (c < n && a[c] < a[c + 1])
            c++;
        if (item >= a[c])
            break;
        a[p] = a[c];
        p = c;
        c = 2 * p;
    }
    a[p] = item;
    return n;
}

void display(int a[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[maxsize], n = 0, item, ch;
    for (;;)
    {
        printf("1:Insert 2:Delete 3:Display 4:Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            n = insert(item, a, n);
            break;
        case 2:
            n = delete (a, n);
            break;
        case 3:
            display(a, n);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
