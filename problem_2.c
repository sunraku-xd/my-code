#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

typedef struct linkedlist
{
    node *head;
    node *tail;
    node *prev;
    node *curr;
    node *next;
} linkedlist;

//Function Declaration
linkedlist *init();
void insertAtPos(linkedlist *list, int data, int pos);
void deleteAtPos(linkedlist *list, int pos);
void reverseList(linkedlist *list);
void printList(linkedlist *list);

//Main Function
int main()
{
    linkedlist *list = init();
    int choice = 0;
    int data, pos;

    do
    {
        printf("\n<MENU>\n");
        printf("1.Insert at position:\n");
        printf("2.Delete at position:\n");
        printf("3.Reverse List\n");
        printf("4.Display List\n");
        printf("5.Exit\n");

        printf("\n##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);

            insertAtPos(list, data, pos);

            break;

        case 2:

            printf("Enter position to delete: ");
            scanf("%d", &pos);

            deleteAtPos(list, pos);

            break;

        case 3:

            reverseList(list);
            printList(list);

            break;

        case 4:

            printList(list);

            break;

        case 5:

            exit(0);
        
        default:

            printf("Invalid Choice...\n");

        }

    } while (choice != 5);

    return 0;
}

//Function Defination
linkedlist *init()
{
    return (linkedlist *)calloc(sizeof(linkedlist), 1);
}

void insertAtPos(linkedlist *list, int data, int pos)
{
    node *newNode = (node *)calloc(sizeof(node), 1);

    newNode->data = data;
    newNode->link = NULL;

    if (pos == 1)
    {

        newNode->link = list->head;
        list->head = newNode;
        return;
    }

    node *temp = list->head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

void deleteAtPos(linkedlist *list, int pos)
{
    if (list->head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    node *temp = list->head;

    if (pos == 1)
    {

        list->head = temp->link;

        free(temp);
        return;
    }

    node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++)
    {

        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->link = temp->link;

    free(temp);
}

void reverseList(linkedlist *list)
{
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        node *prev = NULL;
        node *curr = list->head;
        node *next = curr->link;
        while (next != NULL)
        {
            curr->link = prev;
            prev = curr;
            curr = next;
            next = curr->link;
        }
        curr->link = prev;
        list->tail = list->head;
        list->head = curr;
    }
}

void printList(linkedlist *list)
{
    node *temp = list->head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
