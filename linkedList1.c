#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct linkedlist{
    node *head;
    node* tail;
    node *prev;
    node *curr;
    node *next;
    int length;
}linkedlist;

linkedlist *init();
void insertFirst(linkedlist *list, int data);
void reverseList(linkedlist *list);
void printList(linkedlist *list);

int main(){

    linkedlist *list = init();

    // insertFirst(list,30);
    insertFirst(list,20);
    insertFirst(list,10);

    printList(list);

    reverseList(list);
    printList(list);
    
}

linkedlist *init(){
    
    return (linkedlist*)calloc(sizeof(linkedlist),1);

}

void insertFirst(linkedlist *list, int data){

    node* temp = (node*)calloc(sizeof(node),1);

    temp->data = data;
    temp->link = list->head;
    list->head = temp;
    (list->length)++;

    if(list->length == 1){
        list->tail = list->head;
    }

}

void reverseList(linkedlist *list){

    if(list->head  == NULL){
        return;
    }
    else{
        node *prev = NULL;
        node *curr = list->head;
        node *next = curr->link;
        while(next != NULL){
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

void printList(linkedlist *list){

    node* temp = list->head;
    while(temp){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
