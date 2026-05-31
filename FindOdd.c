#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
void printOdd(int* arr, int count);

int main(){

    int* arr, size;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = createArray(size);
    scanArray(arr, size);

    printf("\nArray elements are:\n");
    printArray(arr, size);

    printf("Odd elements in the array:\n");
    printOdd(arr, size);

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

void printOdd(int* arr, int count){
        
    for(int i=0; i<count; i++){
        if(arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    //printf("\n");
    
}

