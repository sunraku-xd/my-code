#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void assignArray(int *arr, int size);
void printArray(int *arr, int size);
int partition(int *arr, int start, int end);
int kthSmallest(int *arr, int start, int end, int key);
int kthLargest(int *arr, int size, int key);
void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    int *arr, size;

    printf("Enter the array size: ");
    scanf("%d", &size);

    int start = 0;
    int end = size-1;
    int key;

    arr = createArray(size);

    srand(time(0));
    assignArray(arr, size);
    printf("Array elements are:\n");
    printArray(arr, size);

    printf("\nEnter kth smallest/largest number to search: ");
    scanf("%d", &key);
    int result_1 = kthSmallest(arr, start, end, key);
    int result_2 = kthLargest(arr, size, key);
    if(result_1 && result_2 != -1){
        printf("%dth samllest number is %d\n", key, result_1);
        printf("%dth largset number is %d\n", key, result_2);
    }
    else{
        printf("ERROR! Invalid Input.\n");
    }

    return 0;

}

int* createArray(int size){

    return (int*)malloc(size*sizeof(int));

}

void assignArray(int *arr, int size){

    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }

}

void printArray(int *arr, int size){

    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }

}

int partition(int *arr, int start, int end){

    int pivot = arr[end];
    int i = start-1;

    for(int j=start; j<end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;

}

int kthSmallest(int *arr, int start, int end, int key){

    if(start<=end){

        int pivotIdx = partition(arr, start, end);
        if(pivotIdx == key-1){
            return arr[pivotIdx];
        }
        else if(pivotIdx > key-1){
            return kthSmallest(arr, start, pivotIdx-1, key);
        }
        else{
            return kthSmallest(arr, pivotIdx+1, end, key);
        }

    }
    return -1;

}

int kthLargest(int *arr, int size, int key){
    
    return kthSmallest(arr, 0, size-1, size-key+1);

}