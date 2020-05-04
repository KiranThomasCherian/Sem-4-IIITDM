#include<cstdlib>
#include<iostream>
#include "lognlogn.h"
using namespace std;

void lognsquare::bmultiply()
{
cout<<"Enter number to multiply to itself : ";
int n1;
cin>>n1;
int a1[100];
int sum[100]={0};
int ans[100];
int temp[100];
int i,j,q;
int s1=0;
while(n1!=0)
{
q=n1%2;
a1[s1++]=q;
n1=n1/2;
}
int ss=s1;          //size of sum intially same 
int l=0,cflag3=0;
int si=0;
int k,cflag;
/*for(i=0;i<s1;i++)
cout<<a1[i];*/
for(i=0;i<s1;i++)
{
 k=0,cflag=0,cflag3=0;
for(j=0;j<l;j++)
{
temp[k++]=0;
}
l++;

for(j=0;j<s1;j++)
temp[k++]=a1[i]*a1[j];  //k is size of temp

q=(k>ss)?k:ss;

for(j=0;j<q;j++)
{
int var=sum[j]+temp[j];
if(var<=1)
{
sum[j]=var;
cflag=0;
}
else
{
cflag=1;
if(var==2)
{
sum[j]=0;
sum[j+1]=sum[j+1]+1;
}
if(var==3)
{
sum[j]=1;
sum[j+1]=sum[j+1]+1;
cflag3=1;
}
}
}
if(cflag==1)
{
sum[j]=1;
ss=j+1;
}
else 
ss=j;
//for(int o=0;o<j;o++)
//cout<<sum[o];
//cout<<endl;


}
/*
if(cflag=0)
si=k;
else if(cflag3==0)
si=k+1;
else
si=k+2;
//si=sizeof(sum)/sizeof(sum[0]);
*/
for(i=0,j=ss-1;i<ss;i++,j--)
{
ans[i]=sum[j];
}

//cout<<si<<endl;
for(i=0;i<ss;i++)     
{
cout<<ans[i]<<" ";
}
}
