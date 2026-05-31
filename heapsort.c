#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void assignArray(int* arr, int size);
void printArray(int* arr, int size);
void heapSort(int* arr, int size);
void buildHeap(int* arr, int size);
void heapify(int* arr, int I, int size);
void swap(int* x, int* y){ 
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    int* arr, size;

    printf("Enter the array size: ");
    scanf("%d", &size);
     
    arr = createArray(size);

    srand(time(0));
    assignArray(arr, size);

    printf("Array before sorting:\n");
    printArray(arr, size);

    heapSort(arr, size);
    printf("\nArray after sorting:\n");
    printArray(arr, size);

    printf("\n");

    free(arr);

    return 0;
}

int* createArray(int size){

    return (int*)malloc(size*sizeof(int));
}

void assignArray(int* arr, int size){

    for(int i=0; i<size; i++){
        arr[i] = rand()%100+1;
    }
}

void printArray(int* arr, int size){

    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void heapSort(int* arr, int size){

    buildHeap(arr, size);
    for(int i=size-1; i>0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
    }
}

void buildHeap(int* arr, int size){

    for(int i=(size/2)-1; i>=0; i--){
        heapify(arr, i, size);
    }
    
}

void heapify(int* arr, int I, int size){
    
    int left = I*2 + 1;
    int right = I*2 + 2;

    int maxIdx = I;

    if(left < size && arr[left] > arr[maxIdx]){
        maxIdx = left;
    }
    if(right < size && arr[right] > arr[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != I){
        swap(&arr[I], &arr[maxIdx]);
        heapify(arr, maxIdx, size);
    }

}
