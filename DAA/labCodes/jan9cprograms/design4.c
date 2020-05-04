#include<stdio.h>
void main()
{
int i,j,k,x;
printf("Enter dimension : ");
scanf("%d",&x);
for(i=x;i>=1;i--)
{
for(j=1;j<=x;j++)
{
if(j>=i)
printf("%d",j);
else
printf(" ");
}
printf("\n");
}
}
