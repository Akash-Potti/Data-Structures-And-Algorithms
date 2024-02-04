#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int row;
    int col;
    int value;
};
typedef struct matrix MATRIX;

void main()
{
    int m, n, i, j, item, key;

    MATRIX a[100];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    a[0].row = m;
    a[0].col = n;
    int count = 0;
    int k = 1;
    printf("Enter the elements of the matrix: ");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &item);
            if (item != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = item;
                k++;
                count++;
            }
        }
    }
    a[0].value = count;

    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    for (i = 1; i < a[0].value; i++)
    {
        if (a[i].value == key)
        {
            printf("The element is found at position %d %d\n", a[i].row, a[i].col);
            exit(0);
        }
    }
    printf("unsuccessful search\n");
}