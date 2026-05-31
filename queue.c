/*#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *arr;
    int size;
    int count;
    int front; 
    int rear;
}queue;

queue *init(int size);
void enqueue(queue *q, int data);
int dequeue(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void display(queue *q);

int main(){

    queue *q = init(3);

    // enqueue(q, 10);
    // enqueue(q, 20);
    // enqueue(q, 30);

    display(q);

    printf("\n");

    // dequeue(q);
    // display(q);

    printf("\n%d[1 for true. 0 for false]\n", isFull(q));
    isEmpty(q);

}

queue *init(int size){
    
    queue *q = (queue*)calloc(1,sizeof(queue));
    q->arr = (int*)calloc(size,sizeof(int));
    q->size = size;
    q->count = 0;
    q->front = 0;
    q->rear = 0;

    return q;
}

void enqueue(queue *q, int data){

    q->arr[q->rear] = data;
    q->rear = ((q->rear)+1)%q->size;
    q->count++;
}

int dequeue(queue *q){

    int temp = q->arr[q->front];
    q->front = (q->front+1)%q->size;
    q->count--;

    return temp;
}

int isFull(queue *q){

    return (q->count == (q->size-1)?1:0);
}

int isEmpty(queue *q){

    return ((q->count == -1)?1:0);
}

void display(queue *q){

    if(isEmpty(q)){
        printf("Queue is empty\n");
        // return;
    }
    for(int i=0; i<q->count; i++){
        printf("%d ", q->arr[i]);
    }
   
}*/

#include <stdio.h>
