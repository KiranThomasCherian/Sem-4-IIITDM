#include<stdio.h>

int main()
{
int a[100],n;

printf("Enter n ");
scanf("%d",&n);

printf("Enter array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

int a1[100],a2[100],a3[100],k1=0,k2=0,k3=0;

for(int i=0;i<n;i++)
if(a[i]==0)
{a1[k1]=0;k1++;
}
else if(a[i]==1)
{
a2[k2]=1;k2++;}
else
{a3[k3]=2;k3++;}

int j=0,j1=0,j2=0;

while(j<k1)
{
a[j]=0;
j++;}


while(j1<k2)
{a[j]=1;
j1++;j++;}

while(j2<k3)
{
a[j]=2;
j2++;j++;
}


for(int i=0;i<n;i++)
printf(" %d",a[i]);

return 0;
}
