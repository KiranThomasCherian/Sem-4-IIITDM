#include<stdio.h>
int gcd(int a,int b)
{
if(b==0)
return a;
else
gcd(b,a%b);
}
void main()
{
int a,b,x;
printf("Enter a and b : ");
scanf("%d%d",&a,&b);
if(a<0)
a=-a;
if(b<0)
b=-b;
//int s=((a<b)?a:b);

printf("Gcd = %d ",gcd(a,b));
}
