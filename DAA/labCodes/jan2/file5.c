#include<stdio.h>
int gcd(int a,int b)
{
if(a==b)
return a;
if(a==0&&b==0)
return 0;
if(a==0)
return b;
if(b==0)
return a;
if(a%2==0&&b%2==0)
return (gcd(a/2,b/2)*2);
if(a%2==0&&b%2!=0)
return gcd(a/2,b);
if(a%2!=0&&b%2==0)
return gcd(a,b/2);
if(a%2!=0&&b%2!=0)
{
	if(a>b)
	return gcd((a-b)/2,b);
	else
	return gcd((b-a)/2,a);
}
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
printf("Gcd = %d ",gcd(a,b));
}

