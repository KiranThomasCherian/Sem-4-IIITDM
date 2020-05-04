#include<stdio.h>

void main()
{
int a,b,x;
printf("Enter a and b : ");
scanf("%d%d",&a,&b);
if(a<0)
a=-a;
if(b<0)
b=-b;
while(b!=0)
{
x=a;
a=b;
b=x%b;
}
printf("GCD = %d ",a);
}
