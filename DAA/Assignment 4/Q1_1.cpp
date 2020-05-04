#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }; 
int n = sizeof(arr) / sizeof(arr[0]); 

void findMin(int V) 
{ 
	
	vector<int> ans; 	
	for (int i = n - 1; i >= 0; i--) 
	{ 
		
		while (V >= arr[i]) 
		{ 
			V -= arr[i]; 
			ans.push_back(arr[i]); 
		} 
	} 

	 
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << " "; 
} 

int main() 
{ 
	int m;
	cout<<"Enter the number whose change you want to obtain(only Indian currency considered)::";
	cin>>m;
	cout << "Following is minimal number of change for " << m << ": "; 
	findMin(m); 
	return 0; 
} 

