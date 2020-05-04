#include<stdio.h>
int hcf(int a,int b)
{
if(a%b==0)
return b;
else if(a>0&&b>0)
hcf(a-1,b-1);
else
return 1;
}

void main()
{
int a,b,x;
printf("Enter a nd b : ");
scanf("%d%d",&a,&b);
int s=((a<b)?a:b);

printf("Gcd = %d ",hcf(a,b));
}
