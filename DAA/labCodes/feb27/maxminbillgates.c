#include<stdio.h>

int main()
{
int n,a[100],temp;

printf("Enter the no. of elements ");
scanf("%d",&n);

printf("Enter the elements ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

for(int i=0;i+1<n;i+=2)   
if(a[i]>a[i+1])      
{temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;}

int min=a[0],max=a[1];

for(int i=2;i<n;i+=2)  
if(a[i]<min)
min=a[i];



for(int i=3;i<n;i+=2)
if(a[i]>max)
max=a[i];



if(n%2!=0 && a[n-1]>max)//last element is neglected while comparing for max initially if n is odd
max=a[n-1];

printf("Min = %d Max = %d ",min,max);

return 0;
