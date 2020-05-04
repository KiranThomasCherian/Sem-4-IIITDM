#include<stdio.h>
void main()
{
int a[10000],x;
printf("Enter array ... enter -999 to exit...\n  " );
int i=0,k=1,flag=0;
while(k)
{
scanf("%d",&x);
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
a[i]=x;
i++;
}
i=0;
while(a[i]!=-1)
{

i++;
}
printf("\n answer =%d",i+1);
}
