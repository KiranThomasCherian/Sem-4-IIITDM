#include<stdio.h>
void sortt(int a[100],int n);
int bsearch(int a[100],int r,int beg,int end);
int main()
{
int a[100],n,p;



printf("Enter n ");
scanf("%d",&n);

printf("Enter array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

printf("Enter p ");
scanf("%d",&p);

//getchar();

printf("ddd");
sortt(a,n);

for(int i=0;i<n-1;i++)
{
int q=a[i];
int r=p-q;

if(bsearch(a,r,i+2,n-1)==1)
printf("%d %d\n",q,r);

}
return 1;

}


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


int bsearch(int a[100],int r,int beg,int end)
{
int mid=(beg+end)/2;
while(beg<=end && a[mid]!=r)
{
if(a[mid]>r)
end=mid-1;
else
beg=mid+1;

mid=(beg+end)/2;

}

if(a[mid]==r)
return 1;
else
return 0;

}


