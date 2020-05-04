#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;

int comp[100],cc=0;
int csmall(int s,int e,int *a)
{
if(s==e)
return(a[s]);
else
{
int s1,s2;
s1=csmall(s,s+(e-s)/2,a);
s2=csmall(s+(e-s)/2+1,e,a);
if(s1>s2)
{
comp[cc]=s1;
cc++;
return s2;
}
else
{
comp[cc]=s2;
cc++;
return s1;
}
}
}

int main()
{
int n;
printf("enter size\n");
scanf("%d",&n);
printf("enter elements\n");
int a[n];
int i;
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
int m1,m2;
m1=csmall(0,n-1,a);
m2=comp[0];
for(i=1;i<cc;i++)
{
if(m2>comp[i])
m2=comp[i];
}
printf("first min %d , second min %d ",m1,m2);
return 0;
}



