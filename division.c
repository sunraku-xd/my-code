#include <stdio.h>
int main(){
    int a, b, num, den;
    float result;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

     // find larger and smaller

     if(a>b){
        num = a;
        den = b;
     }
     else{
        num = b;
        den = a;
     }
     result = (float)num/den;
     printf("Fractional form: %d/%d\n", num, den);
     printf("real value: %.2f", result);

     return 0;

}