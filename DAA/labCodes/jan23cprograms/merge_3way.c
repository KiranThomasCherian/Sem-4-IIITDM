#include<stdio.h>
#include<stdlib.h>


void merge(int a[],int start,int mid,int end)
{
int i=start,j=mid+1,k=start,c[100];

while(i<=mid && j<=end)
{
           if(a[i]<a[j])
           {c[k]=a[i];
           //printf("-%d-",c[k]);           
           k++;i++;
           }
           else
           {c[k]=a[j];
           //printf("-%d-",c[k]);            
           k++;j++;}
}
while(i<=mid)
c[k++]=a[i++];
while(j<=end)
c[k++]=a[j++];


for(int i=start;i<=end;i++)
a[i]=c[i];
//printf("-%d ",c[i]);

}



void mergesort(int a[],int start,int end)
{
if(start<end)
{
int mid1,mid2;
mid1=start+(end-start)/3;
mid2=start+(2*(end-start))/3;
mergesort(a,start,mid1);
mergesort(a,mid1+1,mid2);
mergesort(a,mid2+1,end);

merge(a,start,mid1,mid2);
merge(a,start,mid2,end);


}
}







int main()
{
int a[100],n;
printf("Enter n");
scanf("%d",&n);

printf("Enter array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

mergesort(a,0,n-1);

for(int i=0;i<n;i++)
printf("%d ",a[i]);

return 0;
}






