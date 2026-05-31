#include <stdio.h>
int main(){
    int seconds, temp, hrs, mins, secs;

        printf("Enter time in seconds: ");
        scanf("%d", &seconds);
    
    //conversion
        hrs = seconds/3600;
        temp = seconds%3600;

        mins = temp/60;
        secs = temp%60;

        printf("%d seconds converted is %d hours %d minutes %d seconds", seconds, hrs, mins, secs);
    
}