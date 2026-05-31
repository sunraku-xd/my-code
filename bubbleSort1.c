#include <stdio.h>
#include <stdbool.h>
void bubbleShort(int arr[], int size);
void printArray(int arr[], int size);
int main(){

    int size = 6;
    int arr[6] = {10,9,8,7,6,5,};

    printf("Array before shorting:\n");
    printArray(arr, size);

    bubbleShort(arr, size);
    printf("\nArray after shorting:\n");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){

        printf("%d\t", arr[i]);

    }
}

void bubbleShort(int arr[], int size){

    bool vFlag = 1;
    int comparison = 0;

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                comparison++;
            }
        }
        
        if(vFlag){
            printf("\nafter pass %d:", i+1);
        }
        if(vFlag){
            printf("\nswaps = %d\n", comparison);
        }
    

    }
    
}