#include<stdio.h>
void main()
{
int a,b,x;
printf("Enter a nd b : ");
scanf("%d%d",&a,&b);

if(a<0)
a=-a;
if(b<0)
b=-b;
if(a==0&&b==0)
printf("Gcd = 0 ");
else if(a==0)
printf("Gcd= %d ",b);
else if(b==0)
printf("Gcd= %d ",a);
else
{
int s=(((a<b)?a:b));
if(s<=0)
s=s*-1;
for(int i=1;i<=s;i++)
{
if(a%i==0&&b%i==0)
x=i;
}
printf("Gcd = %d ",x);
}
}
