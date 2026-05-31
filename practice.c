// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node{
//     int data;
//     struct node *next;
//     struct node *head;
//     struct node *newNode;
//     struct node *temp;
// }node;

// int main(){

//     // , *newNode, *temp;
//     head = NULL;

//     newNode = (node*)calloc(sizeof(node),1);
//     printf("Enter data: ");
//     scanf("%d", newNode->data);

//     newNode->head = NULL;
//     if(head == NULL){
//          head = temp = newNode;
//     }
//     else{
//         temp->next = newNode;
//         temp = newNode;
//     }
//     temp = head;
//     while(temp != NULL){
//         printf("%d", temp->data);
//         temp = temp->next;
//     }

// }



// #include <stdio.h>
// int main(){
    
//     int a = 10;
//     int *p = &a;
//     int **q = &p;

//     printf("%d\n", p); //address of a
//     printf("%d\n", &p); //address of pointer p
//     printf("%d\n", *p); //value of a
//     printf("%d", **q); //value of a

// }

/*#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int main(){

    node *head = NULL;
    node *newNode, *temp;

    int size;
    printf("enter number of nodes: ");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        newNode = (node*)calloc(1,sizeof(node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next=NULL;
        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}*/

//a pointer always store the adress of another variable.

#include <stdio.h>

int main(){

    int arr[3][3] = {6,2,5,0,1,3,4,9,8};
    int *P;


}



