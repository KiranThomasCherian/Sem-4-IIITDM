#include<stdio.h>

int calc(int a,int b)
{
int s;

if(a<b)
s=b;
else
s=a;

int i=s;

while(1)
{
if(i%a==0 && i%b==0)
return i;

else
i++;
}

}

int lcm;

void count(int a[],int beg,int end)
{if(beg==end)
{          
 lcm=calc(a[beg],lcm);
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

lcm=a[0];

count(a,0,n-1);

printf("\n\n----%d---",lcm);

return 0;
}
