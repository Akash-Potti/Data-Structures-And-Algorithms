#include <stdio.h>

int binary_search(int a[], int key, int low, int high)
{
    int mid;
    mid = (low + high) / 2;
    if (low > high)
    {
        return -1;
    }
    if (key == a[mid])
    {
        return mid;
    }
    if (key > a[mid])
    {
        return binary_search(a, key, mid + 1, high);
    }
    return binary_search(a, key, low, mid - 1);
}

void main()
{
    int n, i, a[20], key, pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    pos = binary_search(a, key, 0, n - 1);
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