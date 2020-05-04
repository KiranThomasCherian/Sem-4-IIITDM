#include<stdio.h>

int c[1000],k3;
void merge(int a[][100],int x[10],int first,int end)
{
int k1=0,k2=0;k3=0;
int p=0;




while(p<=first && k2<x[end])
{k1=0;
while(k1<x[p] && k2<x[end])
  if(a[p][k1]<a[end][k2])
  c[k3++]=a[p][k1++];
  else
  c[k3++]=a[end][k2++];

if(k1==x[p])
{p++;}

}


while(p<=first)
{
while(k1<x[p])
c[k3++]=a[p][k1++];

p++;k1=0;}


while(k2<x[end])
c[k3++]=a[end][k2++];


//for(int t=0;t<k3;t++)
//printf("%d ",c[t]);
//printf("\n");
int q=0;


for(int i1=0;i1<=end;i1++)
for(int i2=0;i2<x[i1];i2++)
{a[i1][i2]=c[q++];
//printf("%d ",a[i1][i2]);
}
}

int main()
{
int a[10][100],x[10];

printf("Enter the no. of arrays: ");
int n;scanf("%d",&n);


for(int i=0;i<n;i++)
{
printf("Enter size of array %d ",i+1);
scanf("%d",&x[i]);

printf("Enter array %d\n ",i+1);
for(int j=0;j<x[i];j++)
scanf("%d",&a[i][j]);

}

printf("OUTPUT +");

for(int i=0;i<n-1;i++)
merge(a,x,i,i+1);


for(int t=0;t<k3;t++)
printf("%d ",c[t]);


return 0;
}
