#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

// Function Declaration
void insertFirst(node **head, int data);
void insertLast(node **head, int data);
void deleteFirst(node **head);
void deleteLast(node **head);
void printList(node *head);

//Main Function
int main()
{
    node *head = NULL;

    int choice = 0;
    int data;

    do
    {
        printf("\n<MENU>\n");
        printf("1.Insert First\n");
        printf("2.Insert Last\n");
        printf("3.Delete First\n");
        printf("4.Delete Last\n");
        printf("5.Display List\n");
        printf("6.Exit\n");

        printf("\n##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter data: ");
            scanf("%d", &data);
            insertFirst(&head, data);

            break;

        case 2:

            printf("Enter data: ");
            scanf("%d", &data);
            insertLast(&head, data);

            break;

        case 3:

            deleteFirst(&head);

            break;

        case 4:

            deleteLast(&head);

            break;

        case 5:

            printList(head);

            break;

        case 6:

            printf("End Program...\n");

        break;

        default:

            printf("Invalid Choice...\n");
        }

    } while (choice != 6);

    return 0;
}

// Function Defination
void insertFirst(node **head, int data)
{
    node *temp = (node *)calloc(sizeof(node), 1);
    temp->data = data;
    temp->link = *head;
    *head = temp;
}

void insertLast(node **head, int data)
{
    if (*head == NULL)
    {
        insertFirst(head, data);
    }
    else
    {
        node *temp = (node *)calloc(sizeof(node), 1);
        temp->data = data;
        temp->link = NULL;
        node *temp1 = *head;
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
}

void deleteFirst(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    node *temp = *head;
    *head = (*head)->link;
    free(temp);
}

void deleteLast(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}