#include <stdio.h>
#include <stdlib.h>

int main(){

    int size;
    int num, pos, pos1;

    printf("Enter the array size: ");
    scanf("%d", &size);

    int *arr = malloc((size+1)*sizeof(int));
    // int arr[size];

    for(int i=0; i<size; i++){
        printf("Enter Arr[%d]:", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }

    printf("\nEnter number and position to insert: ");
    scanf("%d %d", &num, &pos);

    if(pos<=0 || pos>size+1){
        printf("ERROR! Invalid position.\n");
    }
    else{
        for(int i=size-1; i>=pos-1; i--){
            arr[i+1] = arr[i];
        }
        arr[pos-1] = num;
        size++;
    
        printf("Array after insertion:\n");
        for(int i=0; i<size; i++){
            printf("%d\t", arr[i]);
        }
    }

    printf("\nEnter element(index) to delete: ");
    scanf("%d", pos1);
    if(pos1<=0 || pos1>size){
        printf("ERROR! Invalid position.\n");
    }
    else{
        for(int i=0; i=size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        printf("Array after deletion:\n");
        for(int i=0; i<size; i++){
            printf("%d\t", arr[i]);
        }
    }

    return 0;
}