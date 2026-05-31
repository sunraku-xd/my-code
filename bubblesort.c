#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
void bubbleSort(int* arr, int count);

int main(){

    int* arr, size;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = createArray(size);
    scanArray(arr, size);

    printf("\nArray elements are:\n");
    printArray(arr, size);

    bubbleSort(arr, size);
    printf("\nArrays after sorting:\n");
    printArray(arr, size);

    free(arr);

    return 0;

}

int* createArray(int size){

    return (int*)calloc(size,sizeof(int));

}

void scanArray(int* arr, int count){

    for(int i=0; i<count; i++){
        printf("Enter Arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }

}

void printArray(int* arr, int count){

    for(int i=0; i<count; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

}

void bubbleSort(int* arr, int count){
    
    int temp;
    for(int i=0; i<count-1; i++){
       for(int j=0; j<count-i-1; j++){
        if(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
       }
    }

}

