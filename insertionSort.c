#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int size);
void printArray(int* arr, int size);
void insertionSort(int* arr, int size);

int main(){

    int *arr, size;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = createArray(size);

    scanArray(arr, size);

    printf("Array elements are:\n");
    printArray(arr, size);

    insertionSort(arr, size);
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

void insertionSort(int* arr, int size){
    for(int i=1; i<size; i++){
        int key = arr[i]; //key = current
        int j = i-1; //j = previous
        while(j>=0 && arr[j]>key){ //(previous>=0 && arr[previous]>current)
            arr[j+1] = arr[j]; //arr[previous+1] = arr[previous]
            j--; //previous--
        }
        arr[j+1] = key; //arr[previous+1] = current
    }
}
