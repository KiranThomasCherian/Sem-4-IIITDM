#include<stdio.h>
int a[100][100];

int c[100000];
int q=0;
int n[100];
int ntemp[100];
void insertionsort(int s,int e)
{
int s1=n[s];
int s2=n[e];
int sc1=ntemp[s];      //to check  if already inserted
int sc2=ntemp[e];
if(s==e)               //to check if only one array on side
{
if(sc1!=0)
{
for(int i=0;i<s1;i++)
c[q++]=a[s][i];
ntemp[s]=0;
}
}
else
{
if(sc1!=0)
{
for(int i=0;i<s1;i++)
c[q++]=a[s][i];
ntemp[s]=0;
}
if(sc2!=0)
{
for(int i=0;i<s2;i++)
c[q++]=a[e][i];
ntemp[e]=0;
}
}
if(sc1!=0||sc2!=0)
{
int val;
for(int i = 1; i < q; i++)
{
val = c[i];
int j = i - 1;
while(j >= 0 && c[j] > val)
{
c[j + 1] = c[j];
j--;
} 
c[j + 1] = val;
}
}
}
void sortdrive(int s,int e,int k)
{
if(k<=2)
{
insertionsort(s,e);
}
else
{
int m=(s+e)/2;
sortdrive(s,m,k-(k/2));
sortdrive(m+1,e,(k/2));
}
}



/*
void sort(int a[],int b[])
{
int s1=sizeof(a)/sizeof(int);
int s2=sizeof(b)/sizeof(int);
int c[s1+s2];
int i=0,j=0,k=0;
while(i!=s1&&j!=s2)
{
if(a[i]<a[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=b[j];
j++;
}
k++;
}
if(i!=s1)
{
c[k++]=a[i++]
}
if(j!=s2)
{
c[k++]=b[j++]
}
for(i=0;i<s1;i++)
a[i]=c[i];

for(j=0;j<s2;i++,j++)
b[i]=c[i];
}
*/


void main()
{
int z;
printf("Enter No of arrays: ");
scanf("%d",&z);

for(int i=0;i<z;i++)
	{
	printf("Enter size of array %d: ",i+1);
	scanf("%d",&n[i]);
	printf("Enter array %d \n", i+1);
	for(int j=0;j<n[i];j++)
	scanf("%d",&a[i][j]);
	}
for(int i=0;i<z;i++)
ntemp[i]=n[i];
sortdrive(0,z-1,z);
for(int i=0;i<q;i++)
printf(" %d ",c[i]);
}
