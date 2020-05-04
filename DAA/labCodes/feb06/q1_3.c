#include<stdio.h>
void main()
{
int k;
int a[100][100];
printf("Enter No of arrays: ");
scanf("%d",&k);
int n[100];
for(int i=0;i<k;i++)
	{
	printf("Enter size of array %d: ",i+1);
	scanf("%d",&n[i]);
	printf("Enter array %d \n", i+1);
	for(int j=0;j<n[i];j++)
	scanf("%d",&a[i][j]);
	}
//int (*p)[100]=a;
int ntemp[100];
for(int i=0;i<k;i++)
ntemp[i]=n[i];
int flag=1,i,min,tempmini,minii;


//int count=0;

while(flag)
{

i=0;
ii:
if(ntemp[i]==0)
{
i++;
if(i==k)
break;
goto ii;
}
//printf("Here0");
tempmini=n[i]-(ntemp[i]);
min=a[i][tempmini];
minii=i;
for(;i<k;i++)
{
//printf("Here");
if((a[i][n[i]-(ntemp[i])]<min )&&(ntemp[i]!=0))
{
min=a[i][n[i]-(ntemp[i])];
minii=i;
//printf("Here2");
//ntemp[i]=ntemp[i]-1;
}
}
ntemp[minii]--;
printf(" %d ",min);
for(i=0;i<k;i++)
{
if(ntemp[i]!=0)
{
flag=1;
break;
}
else 
flag=0;
}

}
		/*
if(count==2)
flag=0;
printf("\n%d %d %d",min,ntemp[0],ntemp[1]);
count++;




}	
/*


printf("\nPrinting: ");
for(int i=0;i<k;i++)
	{
	printf("\n");
	for(int j=0;j<n[i];j++)
	printf(" %d ",*(p[i]+j));
	}*/   
//printf("out");
}
