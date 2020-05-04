#include<stdio.h>
void main()
{
int a[100],x,p,q,r,i,j;
printf("Enter size of array : ");
scanf("%d",&x);
for(i=0;i<x;i++)
{
scanf("%d",&a[i]);
}
printf("Enter p : ");
scanf("%d",&p);
for(i=0;i<x;i++)
{
for(j=i;j<x;j++)
{
if(i!=j&&a[i]+a[j]==p)
printf(" \n %d %d ",a[i],a[j]);
}
}
}
