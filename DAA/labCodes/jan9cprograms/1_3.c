#include<stdio.h>

void sortt(int a[100],int n)
{
printf(" SORT ");
int i,temp,j;

for(i=1;i<n;i++)
{
temp=a[i];
j=i-1;

while(j>=0&& a[j]>temp)
{
a[j+1]=a[j];
j--;
}

a[j+1]=temp;

}

}


int main()
{
int a[100],p,n;

printf("Enter n ");
scanf("%d",&n);

printf("Enter the array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

sortt(a,n);

int flag=0;

printf("Enter p ");
scanf("%d",&p);

if((a[0]+a[1])>p || (a[n-1]+a[n-2])<p)
printf("NOT FOUND ");
else
for(int i=0,j=n-1;i<j;)
{
if(a[i]+a[j]==p)
{printf("%d %d",a[i],a[j]);
flag=1;
break;}
else if(a[i]+a[j]<p)
i++;
else
j--;
}

if(flag==0)
printf("\nNOT FOUND");

return 0;
}
























