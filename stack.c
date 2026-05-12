#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int *arr;
    int size;
    int top;
}stack;

stack *init(int size);
void push(stack *s, int data);
int pop(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);

int main(){

    int size, data;
    printf("Enter stack size: ");
    scanf("%d", &size);

    stack *s = init(size);
    
    for(int i=0; i<size; i++){
        printf("Enter data: ");
        scanf("%d", &data);
        push(s, data);
    }
    

    // push(s, 10);
    // push(s, 20);
    // push(s, 30);
    // push(s, 40);
    // push(s, 50);

    for(int i=0; i<=s->top; i++){
        printf("%d\n", s->arr[i]);
    }

    printf("%d\n", isFull(s));

}

stack *init(int size){

    stack *s = (stack*)calloc(1,sizeof(stack));
    s->arr = (int*)calloc(size,sizeof(int));
    s->size = size;
    s->top = -1;
    return s;

}

void push(stack* s, int data){

    s->arr[++(s->top)] = data;

}

int pop(stack *s){

    return s->arr[(s->top)--];

}

int isFull(stack *s){

    return (s->top == (s->size-1)?1:0);

}

int isEmpty(stack *s){

    return ((s->top == -1)?1:0);

}