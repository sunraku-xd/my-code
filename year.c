#include <stdio.h>
int main(){
    int _days, years, monthes, days, temp;
    
    printf("Enter time in days: ");
    scanf("%d", &_days);

    //conversion 
    years = _days/365;
    temp = _days%365;

    monthes = temp/30;
    days = temp%30;

    printf("%d days is equivalent to %d years %d monthes %d days", _days, years, monthes, days);
}