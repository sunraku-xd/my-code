#include <stdio.h>
#include <stdlib.h>

//function declarations

int* createArray(int size);
void scanArray(int* arr, int count);
void printArray(int* arr, int count);
int findMax(int* arr, int count); //find max
int findMin(int* arr, int count); //find min
int findSum(int* arr, int count); //find sum
int linearSearch(int* arr,int count, int key); //linear search
void printOdd(int* arr, int count); //print odd elements
void bubbleSort(int* arr, int count); //bubble sort
int secondHighest(int* arr, int count); //find 2nd highest number

int main(){
    int* arr;
    int size, key, pos;

    printf("Enter the array size: ");
    scanf("%d", &size);

    arr = createArray(size);

    scanArray(arr, size);

    printf("\nArray elements are:\n");
    printArray(arr, size);

    printf("\nMaximum element = %d\n", findMax(arr, size));
    printf("Minimum element = %d\n", findMin(arr, size));
    printf("Sum of elements = %d\n", findSum(arr, size));

    printf("Enter element to search: ");
    scanf("%d", &key);
    pos = linearSearch(arr, size, key);

    if(pos != -1)
        printf("Element found at position %d\n", pos + 1);
    else
        printf("Element not found\n");

    printf("\nOdd elements in the array:\n");
    printOdd(arr, size);

    bubbleSort(arr, size);
    printf("\nArray after sorting:\n");
    printArray(arr, size);

    if(size>= 2)
        printf("\nSecond highest element = %d\n", secondHighest(arr, size));
    else
        printf("\nSecond highest element not possible\n");

    free(arr); //free allocated memory
    
    return 0;
}

//Function defination

int* createArray(int size){
    return (int*)calloc(size, sizeof(int));
}

void scanArray(int* arr, int count){
    int i;
    for(i=0; i<count; i++){
        printf("Enter Arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, int count){
    int i;
    for(i=0; i<count; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int findMax(int* arr, int count){
    int max = arr[0], i;
    for(i=1; i<count; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int findMin(int* arr, int count){
    int min = arr[0], i;
    for(i=1; i<count; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findSum(int* arr, int count){
    int sum = 0, i;
    for(i=0; i<count; i++){
        sum += arr[i];
    }
    return sum;
}

int linearSearch(int* arr, int count, int key){
    int i;
    for(i=0; i<count; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void printOdd(int* arr, int count){
    int i;
    for(i=0; i<count; i++){
        if(arr[i]%2 != 0)
            printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int count){
    int i, j, temp;
    for(i=0; i<count-1; i++){
        for(j=0; j<count-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int secondHighest(int* arr, int count){
    int highest = arr[count-1];
    int i;
    
    for(i =count-2; i>=0; i--){
        if(arr[i] != highest)
            return arr[i];
    }
    return highest;
}