#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int size);
void printArray(int* arr, int size);
void selectionSort(int* arr, int size);

int main(){

    int *arr, size;

    printf("Enter Array Size: ");
    scanf("%d", &size);

    arr = createArray(size);

    // printf("Enter Arr[%d]:");
    // scanf("%d", &arr[i]);
    scanArray(arr, size);

    printf("Array elements are:\n");
    printArray(arr, size);

    selectionSort(arr, size);
    printf("\nArray after sorting:\n");
    printArray(arr, size);


    free(arr);

    return 0;

}

int* createArray(int size){
    return (int*)calloc(size,sizeof(int));
}

void scanArray(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("Enter Arr[%d]:", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void selectionSort(int* arr, int size){
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            
            if(arr[j]>arr[minIndex]){
                minIndex=j;
            }

            int temp = arr[j];
            arr[j] = arr[minIndex];
            arr[minIndex] = temp;
        }

    }
}