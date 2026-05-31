#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
void selectionSort(int* arr, int count, int* comparison);


int main(){

    int *arr, size;
    int comparison=0;

    printf("Enter the array size: ");
    scanf("%d", &size);

    arr = createArray(size);

    scanArray(arr, size);

    printf("Array elements are:\n");
    printArray(arr, size);

    selectionSort(arr, size, &comparison);
    printf("\nArray after sorting:\n");
    printArray(arr, size);

    printf("\nTime complexity shown.\n");

    for(int n=2; n<=1024; n=n*2){
        int arr[n];
        int comparison=0;

        selectionSort(arr, n, &comparison);

        printf("The Array of size %4d with %6d many comparison in selection sort.\n", n, comparison);

    }

    free(arr);

    return 0;
}

int* createArray(int size){

    return (int*)calloc(size, sizeof(int));
}

void scanArray(int* arr, int count){

    for(int i=0; i<count; i++){
        printf("Enter Arr[%d]:", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, int count){

    for(int i=0; i<count; i++){
        printf("%d\t", arr[i]);
    }
}

void selectionSort(int* arr, int count, int* comparison){

    for(int i=0; i<count-1; i++){
        int minIndex = i;
        for(int j=i+1; j<count; j++){
            (*comparison)++;
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

