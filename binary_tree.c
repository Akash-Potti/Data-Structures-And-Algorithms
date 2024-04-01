// program to create a binary tree and insert traverse the tree in inorder, preorder and postorder and display the elements in the tree using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}
void display(NODE root, int height)
{
    int i;
    if (root == NULL)
        return;
    display(root->llink, height + 1);
    for (i = 0; i < height; i++)
        printf("--");
    printf("%d\n", root->info);
    display(root->rlink, height + 1);
}

int main()
{
    NODE root = NULL;
    int choice, item;
    for (;;)
    {
        printf("\n1:Insert\n2:Inorder\n3:Preorder\n4:Postorder\n5:Display\n6:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            display(root, 1);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}