#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL;
    node *newNode, *temp;

    int size;
    printf("enter number of nodes: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        newNode = (node *)calloc(1, sizeof(node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
