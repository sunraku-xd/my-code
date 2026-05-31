#include<stdio.h>

int main(){
    int a=0, b=1, n=10, i, c;

    printf("%d\n",a);
    printf("%d\n",b);

    for(i=3; i<=n; i++)
    {
            c = a + b;
            printf("%d\n",c);
            a=b;
            b=c;
    }
    return 0;
}
