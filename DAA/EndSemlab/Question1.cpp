
/*
SET 8 Question 1:
 Given an integer array of size n, present an algorithm to find a maximum contiguous subsequence sum, i.e. a subarray which is contiguous (ai, ai+1, . . . , aj ) and Pj
x=i ax is maximum over all possible values for i and j, 1 ≤ i ≤ j ≤ n.



LOGIC:
We intialize maxnow and maxend to INTMIN and 0 respectively,(beg,end and temp--0//temp for intermidiate beginings),
maxnow keeps mtrack of maximum subsequence sum.
then we iterate through the entire array:
we update maxend as (maxend + current array element):
    if it is greater than maxnow,we upadte maxnow,also update beg and end
    if maxend is less than 0 ,it is assigned as zero and temp as i+1 
        (so as to check if a new cluster starts from there onwards, as sum isnt positive any more..)




Only one time scaning so order(n) //n-size of array.

*/
#include<iostream> 
#include<climits> 
using namespace std; 
int maxsum(int a[100],int s) 
{ 
int maxnow=INT_MIN;
int maxend=0; 
int beg=0,end=0,temp=0; 
for(int i=0;i<s;i++) 
{ 
maxend=maxend+a[i]; 
if(maxnow<maxend) 
{ 
maxnow=maxend;
beg=temp; 
end=i; 
//cout<<end<<maxend;
} 
if(maxend<0) 
{ 
maxend=0; 
temp=i+1;
//cout<<endl<<temp<<endl;
} 
} 
cout<<"Maximum contiguous sunsequence sum is "<<maxnow<<"\nSubsequence Starting index :"<<beg<<"\tEnding index :"<<end<<"\n(Note:Array start from 0)"; 
} 

int main() 
{ 
int a[100],s;
cout<<"Enter size of array : ";
cin>>s;
cout<<"Enter array elements :";
for(int i=0;i<s;i++)
cin>>a[i];
maxsum(a,s);
return 0; 
} 