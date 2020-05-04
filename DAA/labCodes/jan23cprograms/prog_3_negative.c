#include<stdio.h>

int c=0;

void count(int a[],int beg,int end)
{if(beg==end)
{          if(a[beg]<0)
           c++;
}
else
{count(a,beg,(beg+end)/2);
count(a,(beg+end)/2+1,end);
}

}

int main()
{
int a[100],n;

scanf("%d",&n);

printf("Enter array ");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

count(a,0,n-1);

printf("\n\n----%d---",c);

return 0;
}
