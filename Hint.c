#include<stdio.h>
int main(){
int a, b, c, second;

printf("Enter three numbers:");
scanf("%d %d %d", &a, &b, &c);

if ((a>b && a<c) || (a<b && a>c))
{
    second = a;
}
else if ((b>a && b<c) || (b<a && b>c))
{
    second = b;
}
else
{
    second = c;
}
printf("The second highest number:%d", second);
return 0;
}