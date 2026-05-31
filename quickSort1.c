#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void assignArray(int* arr, int size);
void printArray(int* arr, int size);
void quickSort(int* arr, int start, int end);
int lomutoPartition(int* arr, int start, int end);
void swap(int* x, int* y);

int main(){

    int* arr, size;

    printf("Enter the array size: ");
    scanf("%d", &size);

    int start = 0;
    int end = size - 1;

    arr = createArray(size);

    srand(time(0));
    assignArray(arr, size);

    printf("Array before sorting:\n");
    printArray(arr, size);

    quickSort(arr, start, end);
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

void quickSort(int* arr, int start, int end){

    int pivot = arr[end];
    if(start<end){
        int loc = lomutoPartition(arr, start, end);
        quickSort(arr, start, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

int lomutoPartition(int* arr, int start, int end){
    
    int pivot = arr[end];
    int i = start-1;
    for(int j=start; j<=end-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    } 
    swap(&arr[i+1], &arr[end]);

    return i+1;
}

void swap(int* x, int* y){
    int temp =*x;
    *x = *y;
    *y = temp;
}