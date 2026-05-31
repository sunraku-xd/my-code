#include <stdio.h>
#include <string.h>
int main(){
    char ar[100],ar1[100],ar2[100];
    int len;
    printf("Enter name 1 : ");
    gets(ar);
    printf("Enter name 2 : ");
    gets(ar1);
    printf("Enter name 3 : ");
    gets(ar2);
    len=strlen(ar);
    
    printf("lenght of ar 1 is %d\n",len);
    
    printf("ar copied on ar2 is : %s\n",strcpy(ar2,ar));
    printf("concatenated value of ar and ar1 %s\n",strcat(ar1,ar));
    printf("on comparing ar1 and ar2 we get %d",strcmp(ar1,ar2));
    
}
     
     
