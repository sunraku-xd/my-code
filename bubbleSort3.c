#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void assignValue(int* arr, int size);
void printArray(int* arr, int size);
void bubbleSort(int* arr, int size);
void swap(int* x, int* y );

int main(){

    int size = 5;
    
    // int arr[5] = {31,23,7,19,11};

    int* arr = createArray(size);

    srand(time(0));
    assignValue(arr, size);

    printf("Array before sorting:\n");
    printArray(arr, size);

    printf("\nArray after sorting:\n");
    bubbleSort(arr, size);
    printArray(arr, size);

    free(arr);
    return 0;

}

int* createArray(int size){
    return (int*)malloc(size*sizeof(int));
}

void assignValue(int* arr, int size){
    for(int i=0; i<size; i++){
        arr[i] = rand() % 100;
    }
}

void printArray(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void bubbleSort(int* arr, int size){
    int minIndex;
    // int i = minIndex;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                minIndex = arr[j];
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}