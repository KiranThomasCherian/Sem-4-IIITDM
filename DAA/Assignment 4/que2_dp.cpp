#include<iostream> 
using namespace std; 
int l[100];
int num_deno(int deno[], int m, int V) 
{ 
	
    int M[V+1];
	int coin[50][50],k; 
    M[0] = 0; 				 
    for (int i=1; i<=V; i++)
        M[i] = 2147483647; 
    for (int i=1; i<=V; i++) 
    {  
        for (int j=0; j<m; j++)
		{ 
        	if (deno[j] <= i) 
        	{ 
          		int c=0;
          		if(M[i-deno[j]]!=2147483647)
	          		for(k=0;k<M[i-deno[j]];k++)
				  	{
				  		if(coin[i-deno[j]][k]==deno[j])
				  			c++;
					}
				if(c<l[j])
				{
	            	int res = M[i-deno[j]]; 
	            	if (res != 2147483647 && res + 1 < M[i])
					{
				  		M[i] = res + 1; 
				  		for(k=0;k<M[i]-1;k++)
				  		{
				  			coin[i][k]=coin[i-deno[j]][k];
						}
						coin[i][k]=deno[j];
					}  
				}
			}
		}
    } 



    if(M[V]!=2147483647)
    {
    	for(int k=0;k<M[V];k++)
		{
			cout<<coin[V][k]<<" ";
		}
		return M[V];
	}
	else
    	return 0; 
} 
int main() 
{ 
	int num,n,deno[100];
    cout<<"Enter the number of denominations: ";
    cin>>n;
    
    cout<<"Enter the denominations : ";
    for(int i=0;i<n;i++)
    {
    	cin>>deno[i];
	}
	
    cout<<"Enter the limit for each denomination in correct order : ";
    for(int i=0;i<n;i++)
    {
    	cin>>l[i];
	}
    
    cout<<"Enter the Amount ";
    cin>>num; 
   
    cout <<"\nChange for " << num << ": "; 
    int temp=num_deno(deno, n, num);
    if(temp==0)
    cout<<"\nChange is not possible with the given denominations";
    else
    cout<<endl<<"Number of coins required: "<<temp<<endl;
    return 0; 
} 