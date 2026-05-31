#include<stdio.h>
int main(){
    int n, a=1, i;

    printf("Enter range:");
    scanf("%d", &n);

    for(i=0; i<=n; i++)
    {
        printf("2^%d = %d\n", i, a);
        a = a + a;
    }
     return 0;
}