#include <stdio.h>
int main(){
    int num;
    printf("Enter a five digit number: ");
    scanf("%d", &num);

    int digit, new_num = 0, place = 1;
    
    while(num>0){
        digit = num % 10;
        digit = (digit + 1)%10;

        new_num = (digit*place) + new_num;
        place = place*10;
        num = num/10;
    }
        
    printf("Incremented number is:%d\n", new_num);
    
    return 0;
}