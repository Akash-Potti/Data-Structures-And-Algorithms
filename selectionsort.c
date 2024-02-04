#include <stdio.h>

void selectionsort(int a[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void main()
{
    int a[100], n, i;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a, n);
    printf("The sorted array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}