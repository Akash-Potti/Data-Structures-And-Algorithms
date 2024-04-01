#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cf;
    int px;
    struct node *link;
};
typedef struct node *NODE;

NODE insert_rear(int cf, int px, NODE head)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->cf = cf;
    temp->px = px;
    if (head->link == head) // empty list
    {
        head->link = temp;
        temp->link = head;
    }
    else
    {
        cur = head;
        while (cur->link != head)
        {
            cur = cur->link;
        }
        cur->link = temp;
        temp->link = head;
    }
    return head;
}

void readpoly(NODE head)
{
    int n, i, cf, px;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient and power of x: ");
        scanf("%d %d", &cf, &px);
        head = insert_rear(cf, px, head);
    }
}

int compare(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

NODE addpoly(NODE h1, NODE h2, NODE h3)
{
    NODE p1, p2;
    p1 = h1->link;
    p2 = h2->link;
    int sum;
    while (p1 != h1 && p2 != h2)
    {
        switch (compare(p1->px, p2->px))
        {
        case 1:
            h3 = insert_rear(p1->cf, p1->px, h3);
            p1 = p1->link;
            break;
        case -1:
            h3 = insert_rear(p2->cf, p2->px, h3);
            p2 = p2->link;
            break;
        case 0:
            sum = p1->cf + p2->cf;
            if (sum != 0)
                h3 = insert_rear(sum, p1->px, h3);
            p1 = p1->link;
            p2 = p2->link;
            break;
        }
    }
    while (p1 != h1)
    {
        h3 = insert_rear(p1->cf, p1->px, h3);
        p1 = p1->link;
    }
    while (p2 != h2)
    {
        h3 = insert_rear(p2->cf, p2->px, h3);
        p2 = p2->link;
    }
    return h3;
}

void display(NODE head)
{
    NODE temp;
    temp = head->link;
    while (temp != head)
    {
        if (temp->cf > 0)
            printf("+%dx^%d", temp->cf, temp->px);
        else if (temp->cf < 0)
            printf("%dx^%d", temp->cf, temp->px);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    NODE h1, h2, h3;
    h1 = (NODE)malloc(sizeof(struct node));
    h2 = (NODE)malloc(sizeof(struct node));
    h3 = (NODE)malloc(sizeof(struct node));
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    printf("Enter the first polynomial: \n");
    readpoly(h1);
    printf("Enter the second polynomial: \n");
    readpoly(h2);
    printf("The first polynomial is: \n");
    display(h1);
    printf("The second polynomial is: \n");
    display(h2);
    h3 = addpoly(h1, h2, h3);
    printf("The sum of the polynomials is: \n");
    display(h3);
    return 0;
}
