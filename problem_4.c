#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

//Function Declaration
void insert(node **root, int data);
void inOrder(node *root);
void preOrder(node *root);
void postOrder(node *root);
int isEmpty(node *root);

//Main Function
int main()
{
    node *root = NULL;
    int choice, size, data;

    do
    {
        printf("\n<MENU>\n");
        printf("1.Input Data\n");
        printf("2.In-Order\n");
        printf("3.pre-Order\n");
        printf("4.Post-Order\n");
        printf("5.Exit\n");

        printf("##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter tree size: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&root, data);
            }

            break;

        case 2:

            if (isEmpty(root))
            {
                printf("Tree is Empty\n");
            }
            else
            {
                printf("In-Order Traversal:\n");
                inOrder(root);
                printf("\n");
            }

            break;

        case 3:

            if (isEmpty(root))
            {
                printf("Tree is Empty\n");
            }
            else
            {
                printf("Pre-Order Traversal:\n");
                preOrder(root);
                printf("\n");
            }

            break;

        case 4:

            if (isEmpty(root))
            {
                printf("Tree is Empty\n");
            }
            else
            {
                printf("Post-Order Traversal:\n");
                postOrder(root);
                printf("\n");
            }

            break;

        case 5:

            exit(0);

        default:

            printf("Invalid Choice....\n");
        }

    } while (choice != 5);
}

//Function Defintion
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
        insert((&(*root)->left), data);
    }
    else
    {
        insert((&(*root)->right), data);
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

int isEmpty(node *root)
{
    return (root == NULL);
}
