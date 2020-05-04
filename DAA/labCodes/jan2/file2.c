#include<stdio.h>
int v=1;
int gcd(int a,int b,int s,int i)
{
if(a%i==0&&b%i==0)
v=i;
if(i==s)
return v;
else
gcd(a,b,s,i+1);
}





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
int s=((a<b)?a:b);
if(s<0)
s=s*-1;
printf("Gcd = %d ",gcd(a,b,s,1));
}
}
