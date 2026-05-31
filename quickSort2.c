#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void assignArray(int* arr, int size);
void printArray(int* arr, int size);
void quickSort(int* arr, int start, int end);
int hoarePartition(int* arr, int start, int end);
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    
    int* arr, size;

    printf("Enter the array size: ");
    scanf("%d", &size);

    int start = 0;
    int end = size-1;

    arr = createArray(size);

    srand(time(0));
    assignArray(arr, size);

    printf("array before sorting:\n");
    printArray(arr, size);

    quickSort(arr, start, end);
    printf("\narray after sorting:\n");
    printArray(arr, size);

    return 0;
}

int* createArray(int size){
    return (int*)malloc(size*sizeof(int));
}

void assignArray(int* arr, int size){
    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }
}

void printArray(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void quickSort(int* arr, int start, int end){
    if(start<end){
        int loc = hoarePartition(arr, start, end);
        quickSort(arr, start, loc);
        quickSort(arr, loc+1, end);
    }
}

int hoarePartition(int* arr, int start, int end){
    // int pivot = arr[start];
    int pivot = start+(end-start)/2;
    int i = start - 1;
    int j = end + 1;

    while(1){
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j){
            return j;
        }
        swap(&arr[i], &arr[j]);
    }
}

