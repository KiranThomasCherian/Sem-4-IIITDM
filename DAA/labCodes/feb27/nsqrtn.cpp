#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
int main()
{
    printf("Enter n for finding its primalitycheck till sqrt(n) : ");
    int n;
    int unaryn[10000],temp[10000];
    cin>>n;
   
    for(int i=1;i<=sqrt(n);i++)
    {
        
         for(int l=0;l<n;l++)
         unaryn[l]=1;			//here itself n taken;
         for(int j=i-1;j<n;j=j+i)
         {
             unaryn[j]=2;
         }
         if(unaryn[n-1]==2)
         cout<<i<<" ";
         

    }
return 0;
}
