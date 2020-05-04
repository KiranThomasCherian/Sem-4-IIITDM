
//works only for positive numbers inputted in increasing order
#include<stdio.h>
void main()
{
int a[10000],x;
printf("Enter array ... enter -999 to exit...\n  " );
int i=0,k=1,flag=0;
while(k)
{
scanf("%d",&x);
a[i]=x;
if(x==-999)
break;
/*if(i!=0)
{
if(a[i]<a[i-1])
{
printf("Invalid entry ");
break;
}
}*/

i++;
}
i=0;
if(a[i]==-1)
printf("1");
else if(a[i]==-999)
printf("Not found");
else
{
i++;
while(a[i]!=-999)
{
if(a[i]<=a[i-1])
{
printf(" %d ",i+1);
break;
}
i++;
}
//printf("\n answer =%d",i+1);
}
}
