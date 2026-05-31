#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

typedef struct stack
{
    node *top;
} stack;

//Function Declaration
stack *init();
void push(stack *s, int data);
int pop(stack *s);
void display(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);

//Main Function
int main()
{
    stack *s = init();

    int choice, data;

    do
    {
        printf("\n<STACK MENU>\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display Stack\n");
        printf("4.Check Empty\n");
        printf("5.Check Full\n");
        printf("6.Exit\n");

        printf("\n##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            if (isFull(s))
            {
                printf("Stack Overflow\n");
            }
            else
            {
                printf("Enter Data: ");
                scanf("%d", &data);

                push(s, data);
            }

            break;

        case 2:

            pop(s);

            printf("Popped Element = %d\n", data);

            break;

        case 3:

            display(s);

            break;

        case 4:

            if (isEmpty(s))
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is Not Empty\n");
            }

            break;

        case 5:

            if (isFull(s))
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("Stack is Not Full\n");
            }

            break;

        case 6:

            exit(0);

            break;

        default:

            printf("Invalid Choice...\n");
        }

    } while (choice != 6);

    return 0;
}

//Function Defination
stack *init()
{
    stack *s = (stack *)calloc(1, sizeof(stack));
    s->top = NULL;
    return s;
}

void push(stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }

    node *newNode = (node *)calloc(sizeof(node), 1);
    newNode->data = data;
    newNode->link = s->top;
    s->top = newNode;

    printf("%d Inserted Successfully\n", data);
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
    }

    node *temp = s->top;
    s->top = temp->link;
    free(temp);   
}

void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack  is empty\n");
    }
    node *temp = s->top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int isFull(stack *s)
{
    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        return 1;
    }
    free(temp);

    return 0;
}

int isEmpty(stack *s)
{
    return (s->top == NULL);
}
