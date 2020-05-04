#include<stdio.h>

int gcd(int c,int b)
{                                     //gcd of n numbers recurssive
if(b==0)
return c;
else
gcd(b,c%b);
}
int gcddriver(int a[100],int z,int x,int i)
{
if(i==x)
return z;
else
z=gcd(z,a[i]);
gcddriver(a,z,x,i+1);
}
void main()
{
int a[100],x;
printf("Enter size : ");
scanf("%d",&x);
printf(" Enter numbers  : ");
for(int i=0;i<x;i++)
{
scanf("%d",&a[i]);
if(a[i]<0)
a[i]=-a[i];
}

int z=a[0];

printf("Gcd = %d ",gcddriver(a,z,x,1));
}
