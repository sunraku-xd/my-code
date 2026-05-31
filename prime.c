#include <stdio.h>
int main(){

    int n, i=2;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(i<=n-1){
        if(n%i==0){
            printf("non prime");
            return 0;
        }
        else{
            i=i+1;
        }
    }
    printf("is prime");
    return 0;   
}
