#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

void insertFirst(Node **head, int userData);
void insertLast(Node **head, int data);
void printNode(Node *head);

int main(){

    Node *head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    printNode(head);
    insertLast(&head, 40);
    printNode(head);

    return 0;

}

void insertFirst(Node **head, int userData){

    Node *temp = (Node *)calloc(sizeof(Node), 1);
    temp->data = userData;
    temp->link = *head;
    *head = temp;
}

void insertLast(Node **head, int data){

    if(*head == NULL){
        insertFirst(head, data);
    }
    else{
        Node *temp = (Node*)calloc(sizeof(Node), 1);
        temp->data = data;
        temp->link = NULL;
        Node *temp1 = *head;
        while(temp1->link != NULL){
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }

}

void printNode(Node *head){

    Node *temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}