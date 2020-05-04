#include<stdio.h>

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
int a1,b;
a1=z;
for(int i=1;i<x;i++)
{

b=a[i];


while(b!=0)
{
int x1=a1;
a1=b;
b=x1%b;
}




}

//int s=((a<b)?a:b);

printf("Gcd = %d ",a1);
}
