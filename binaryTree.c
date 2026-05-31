#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void insert(node **root, int data);
void inOrder(node *root);
void preOrder(node *root);
void postOrder(node *root);

int main()
{
    node *root = NULL;

    int size, data;

    printf("\nEnter tree size: ");
    scanf("%d", &size);

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("\nIn-Order Traversal:\n");
    inOrder(root);

    printf("\nPre-Order Traversal:\n");
    preOrder(root);

    printf("\nPost-Order Traversal:\n");
    postOrder(root);

    return 0;
}

void insert(node **root, int data)
{
    if (*root == NULL)
    {
        *root = (node *)calloc(1, sizeof(node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if ((*root)->data > data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
