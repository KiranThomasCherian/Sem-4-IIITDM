#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int start,int mid,int end)
{
int i=start,j=mid+1,k=start,c[1000002];

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
void sort(int a[],int start,int end,int s)
{
    if(s <= 10000)
    {
        int val;
        for(int i = start; i <= end; i++)
        {
        val = a[i];
        int j = i - 1;
        while(j >= start && a[j] > val)
        {
        a[j + 1] = a[j];
        j--;
        } 
        a[j + 1] = val;
        }
    }
    else
    {
    int mid = (start + end) / 2;
    sort(a,start,mid,s/2);
    int s2= s-(s/2);
    sort(a,mid + 1,end,s2);
    merge(a,start,mid,end);
    }
    
}

void main()
{
    srand(time(0));
    long int size;
    scanf("%ld",&size);
    int a[size];
    for(int i = 0; i < size;i++)
    {
    a[i] = rand()%100001;
    }
    sort(a,0,size - 1,size);
    for(int i = 0; i < size; i++)
    printf(" %d ",a[i]);
   
}






