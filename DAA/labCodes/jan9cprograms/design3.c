#include<stdio.h>
void main()
{
int i,j,k,x;
printf("Enter dimension : ");
scanf("%d",&x);
for(i=1;i<=x;i++)
{
for(j=1;j<=i;j++)
printf("%d",j);
printf("\n");
}
}
