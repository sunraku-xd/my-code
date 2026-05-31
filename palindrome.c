#include <stdio.h>
#include <string.h>
int main(){
    char ar[100];
    int len,check=1;
    printf("Enter name : ");
    gets(ar);
    
    len=strlen(ar);
    for(int i=0;i<len/2;i++)
    {
        if(ar[i]!= ar[len-i-1])
        {
            check=0;
        }
    }
        if(check==1){
        printf("yes palindrome");
        }
        else{
        printf("not palindrome ");
        }
}
     
     
