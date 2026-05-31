#include <stdio.h>

void printArray(int *arr, int size);
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main(){

    int size = 5;
    int arr[5] = {7,1,13,11,6};
    int start = 0;
    int end = size - 1;

    printf("Array before sorting:\n");
    printArray(arr, size);
    
    mergeSort(arr, start, end);
   
    printf("\nArray after sorting:\n");
    printArray(arr, size);


    return 0;

}

void printArray(int *arr, int size){

    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void mergeSort(int *arr, int start, int end){

    if(start < end){

        int mid = start + ((end - start)/2);

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end){

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int  L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[start + i];
    }

    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i=0, j=0, k=start;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1){
        arr[k++] = L[i++]; 
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
    
}