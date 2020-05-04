#include<stdio.h>

int gcd(int a,int b)
{
if(b==0)
return a;
else
gcd (b,a%b);
}

int hcf;

void count(int a[],int beg,int end)
{if(beg==end)
{          
 hcf=gcd(a[beg],hcf);
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

hcf=a[0];

count(a,0,n-1);

printf("\n\n----%d---",hcf);

return 0;
}
