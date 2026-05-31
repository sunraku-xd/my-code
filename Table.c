#include<stdio.h>
int main(){
    int n, mul, i;

    printf("Enter a number to print the table:");
    scanf("%d", &n);

    for(i=1; i<=10; i++)
    {
        mul = n*i;
        printf("%d x %d = %d\n", n, i, mul);
    }
    return 0;
}