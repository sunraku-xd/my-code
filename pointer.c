#include <stdio.h>
// int countOdd(int arr[], int n);
// int main(){
//     int arr[6] = {1, 2, 3, 4, 5, 6};
//     printf("%d", countOdd(arr, 6));
//     return 0;
//     }
    
//     int countOdd(int arr[], int n){
//         int count = 0;
//         for(int i=0; i<n; i++){
//             if(arr[i] %2 != 0){
//                 count++;
//             }
//         }

//        printf("odd number count: ");
//        return count;
//     }

int main(){

    int x = 99;
    int *p1, *p2;
    p1 = &x;
    p2 = p1;

    printf("%d, %d %d %d\n", p1, p2, *p1, *p2);
}

