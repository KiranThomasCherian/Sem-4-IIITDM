#include<stdio.h>
void main()
{
int i,j,k,x;
printf("Enter dimension : ");
scanf("%d",&x);
int s1=0;                    //space count
j=x;

for(k=1;k<=(x+1)/2;k++)
{
for(i=1;i<=j;i++)
{
if(i<=s1)
{
//s1++;
printf(" ");
}
else
printf("%d",i);
}
s1++;
j--;
printf("\n");
}
s1--;                                //space count is more by 1 in last iteration
j=x%2==0?(x/2+1):((x+1)/2);          //even odd case
for(k=(x+1)/2;k<=x;k++)
{
for(i=1;i<=j;i++)
{
if(i<=s1)
{
//s1++;
printf(" ");
}
else
printf("%d",i);
}
s1--;
j++;
printf("\n");
}
}
