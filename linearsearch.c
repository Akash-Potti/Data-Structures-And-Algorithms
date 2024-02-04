#include <stdio.h>

int linear_search(int n, int arr[], int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[n - 1] == x)
    {
        return n;
    }
    linear_search(n - 1, arr, x);
}

void main()
{
    int n, i, arr[20], key, pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    pos = linear_search(n, arr, key);
    if (pos == -1)
    {
        printf("unsuccessful search\n");
    }
    else
    {
        printf("successful search\n");
        printf("The element is found at position %d\n", pos);
    }
}