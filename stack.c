#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int size;
    int top;
} stack;

stack *init();
void push(stack *s, int data);
int pop(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void displayStack(stack *s);

int main()
{
    int size, choice, data;

    do
    {
        printf("\n<STACK MENU>\n");
        printf("1.Init/Reset size\n2.Push Data\n3.Pop Data\n4.Check Full\n5.Check Empty\n6.Display Stack\n7.Exit\n");

        printf("\n##Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter Stack Size: ");
            scanf("%d", &size);

            stack *s = init(size);

            break;

        case 2:

            printf("Enter Data: ");
            scanf("%d", &data);

            push(s, data);

            break;

        case 3:

            data = pop(s);

            if (data != -1)
            {
                printf("Poped Element = %d\n", data);
            }

            break;

        case 4:

            if (isFull(s))
            {
                printf("stack is full.\n");
            }
            else
            {
                printf("Stack is not full.\n");
            }

            break;

        case 5:

            if (isEmpty(s))
            {
                printf("stack is empty.\n");
            }
            else
            {
                printf("stack is not empty.\n");
            }

            break;

        case 6:

            displayStack(s);

            break;

        case 7:

            printf("Program Ended Successsfuly.\n");

            break;

        default:

            printf("Invalid Choice...\n");
        }

    } while (choice != 7);

    return 0;
}

stack *init(int size)
{
    stack *s = (stack *)calloc(1, sizeof(stack));
    s->arr = (int *)calloc(size, sizeof(int));
    s->size = size;
    s->top = -1;
    return s;
}

void push(stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }

    s->arr[++(s->top)] = data;

    printf("%d Inserted Successfully.\n", data);
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");

        return -1;
    }

    return s->arr[(s->top)--];
}

int isFull(stack *s)
{
    return (s->top == (s->size - 1));
}

int isEmpty(stack *s)
{
    return ((s->top == -1));
}

void displayStack(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty.\n");
        return;
    }

    printf("\nStack Representation:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("| %d |\n", s->arr[i]);
    }
}
