#include <stdio.h>

int main(){

    int size = 5;
    int arr[5] = {4,3,2,1,0};


    for(int j=0; j<size-1; j++){
        for( int k=0; k<size-j-1; k++){
            if(arr[k]>arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }

        printf("\nAfter pass %d:\t", j+1);
            for(int i = 0; i<size; i++){
            printf("%d\t", arr[i]);
        }

    }

    return 0;

}