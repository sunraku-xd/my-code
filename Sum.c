#include<stdio.h>

int main(){
    // addition of two numbers
    int a, b, sum;
    printf("Enter the first number:");
    scanf("%d",&a);
    printf("Enter the second number:");
    scanf("%d", &b);

    sum = a + b;
    printf("The sum of %d + %d is: %d",a,b,sum);
    return 0;
}
