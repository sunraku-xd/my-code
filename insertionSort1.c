#include <stdio.h>

int main(){

    int size = 5;
    int arr[5] = {5,4,3,2,1};

    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}