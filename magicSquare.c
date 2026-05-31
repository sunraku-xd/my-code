#include <stdio.h>
#include <stdlib.h>
#define maxSize 15

int main(){

    int square[maxSize][maxSize];
    int i, j, row, column;
    int count, size;

    printf("Enter the size of the square: ");
    scanf("%d", &size);

    if(size<1 || size>maxSize+1){
        printf("ERROR! Size is out of range.\n");
        exit(1);
    }

    if(size % 2 == 0){
        printf("ERROR! Size is even.\n");
        exit(1);
    }

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++){
            square[i][j] = 0;
        }
    square[0][(size-1)/2]  = 1;
    i = 0;
    j = (size-1)/2;   
    
    for(count = 2; count<=size*size; count++){
        row = (i-1 < 0)?(size-1):(i-1);
        column = (j-1 < 0)?(size-1):(j-1);
        if(square[row][column]){
            i = (i+1)%size;
        }
        else{
            i =row;
            j = (j-1 + size)%size;
        }
        square[i][j] = count;
    }
    
    printf("Magic square of size %d:\n", size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%5d", square[i][j]);
        // printf("\n");
        }
    printf("\n");
    }

}