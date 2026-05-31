#include <stdio.h>
int main(){

    int size = 5;
    int arr[5] = {1,3,2,4,0};
    
    for(int j=0; j<size-1; j++){
        int minIndex = j;
        for(int k=j+1; k<size; k++){
            if(arr[k]<arr[minIndex]){
               minIndex = k;
            }
        }
        int temp = arr[j];
        arr[j] = arr[minIndex];
        arr[minIndex] = temp;

        
    }
    for(int i=0; i<size; i++){
            printf("%d\t", arr[i]);
        }
   
}

