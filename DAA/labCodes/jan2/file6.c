#include<stdio.h>
#include<math.h>
int main()
{
int a,b,x;
printf("Enter a and b : ");
scanf("%d%d",&a,&b);
if(a<0)
a=-a;
if(b<0)
b=-b;

if(a==b)
printf("Gcd = %d ",a);
else if(a==0&&b==0)
printf("Gcd = %d ",a);
else if(a==0)
printf("Gcd = %d ",b);
else if(b==0)
printf("Gcd = %d ",a);
x=0;
while(a%2==0&&b%2==0)
{
a=a/2;
b=b/2;
x=x+1;
}
                                             // do{ from here??
while(a%2==0)
{
a=a/2;
}

while(b%2==0)
{
b=b/2;
}
do
{

if(a>=b)
a=(a-b)/2;
else
{
int temp=a;
a=(b-a)/2;
b=temp;
}
}while(a!=b&&a!=0);
//printf(" %d %d ",x,b);
//int q=pow(2,x);
printf("GCD =%d",b*q);
return 0;
}
