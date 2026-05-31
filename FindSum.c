#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
int findSum(int* arr, int count);

int main(){

    int* arr, size;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = createArray(size);
    scanArray(arr, size);

    printf("\nArray elements are:\n");
    printArray(arr, size);

    printf("\nSum of elements is:%d\n", findSum(arr, size));

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

int findSum(int* arr, int count){
    
    int sum = 0;
    for(int i=0; i<count; i++){
        sum = sum + arr[i];
    }

    return sum;

}

