#include <stdio.h>
int main(){
int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // if (scanf("%d %d", &a, &b) != 1 || a <= 0 || b <= 0) {
    //     return 1;
    // }

    while(b!=0){
        int temp =b;
        b = a%b;
        a = temp;
    }
    printf("GCD is:%d", a);
    return 0;
}