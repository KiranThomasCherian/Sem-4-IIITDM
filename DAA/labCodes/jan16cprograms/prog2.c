#include<stdio.h>

int main()
{
int a[1000],b[100],n;

printf("Enter n ");
scanf("%d",&n);

printf("Enter array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

int big=n-1,sum=0,half;

for(int i=0;i<n;i++)
sum+=a[i];

half=sum/2;
int s,k,bi;
q:
 s=0,k=0,bi=0;

for(int i=big;i>=0 ;i--)
{
if(a[i]+s<=half && k<n/2)
 {if(a[i]+s>=half&&k!=n/2-1)
continue;
b[bi]=a[i];bi++;k++;s+=a[i];}
if(k==n/2)
break;
}
if(k!=n/2)
{big--;
goto q;}


int s1=0,s2=0;

for(int i=0;i<n/2;i++)
{printf("%d ",b[i]);
s1+=b[i];}
printf("\n\n");

for(int i=0;i<n;i++)
{int flag=0;
for(int j=0;j<n/2;j++)
if(a[i]==b[j])
flag=1;

if(flag==0)
{s2+=a[i];
printf("%d ",a[i]);}
}


printf("\n\nsum1 = %d   sum2 = %d",s1,s2);



return 0;
}










