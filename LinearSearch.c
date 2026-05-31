#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
int linearSearch(int* arr, int count, int key);

int main(){

    int* arr, size, key, pos;

    printf("Enter array size: ");
    scanf("%d", &size);

    arr = createArray(size);
    scanArray(arr, size);

    printf("\nArray elements are:\n");
    printArray(arr, size);

    printf("Enter element to search:");
    scanf("%d", &key);

    pos = linearSearch(arr, size, key);

    if(pos != -1)
        printf("Element found at position %d\n", pos+1);
    else
        printf("Element not found\n");
    

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

int linearSearch(int* arr, int count, int key){
    
    for(int i=0; i<count; i++){
        if(arr[i] == key)
            return i;
    }

    return -1;

}

