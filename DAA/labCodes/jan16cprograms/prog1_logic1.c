#include<stdio.h>
void main( )
{	int a[100],n,temp;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter the array:(only 0,1,2)\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
   for (int i = 0; i < n-1; i++) 
   { 
     for (int j = 0; j <n-i-1; j++) 
     { 
        if (a[j]>a[j+1]) 
    	{	temp=a[j];
    		a[j]=a[j+1];
    		a[j+1]=temp;
		}
         
     }
     
	}
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
} 

