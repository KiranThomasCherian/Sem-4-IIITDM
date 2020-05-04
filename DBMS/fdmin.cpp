#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<utility>
#include<vector>a
using namespace std;
int n;
char a[10];
string fdr[25];
string fdl[25];

int fn;
void input(){
printf("Enter no of attributes : ");
cin>>n;
printf("Enter attributes (characters) : ");
for(int i=0;i<n;i++)
cin>>a[i];
printf("Enter no of dependencies : ");
cin>>fn;
fflush(stdin);
char a;
scanf("%c",&a);
for(int i=0;i<fn;i++)
{
printf("Enter lhs of fd %d : ",i+1);
getline(cin,fdr[i]);
printf("Enter rhs of fd %d : ",i+1);
getline(cin,fdl[i]);
}
}
void print(){
for(int i=0;i<fn;i++)
{
cout<<fdr[i];
printf(" -> ");
cout<<fdl[i];
cout<<endl;
}
}
void expand(){
int nnow=fn;
for(int i=0;i<nnow;i++)
{
//cout<<sizeof(fdr[i])<<endl;
if(fdr[i].size()==1)
{
//string temp;
//strcpy(temp,fd[i][1]);
for(int k=1;k<fdl[i].size();k++)
{
fdr[fn]=fdr[i];
fdl[fn]=fdl[i][k];
fn++;
}
fdl[i]=fdl[i][0];
//printf("here");
}

}
}
void equalremove()
{
for(int i=0;i<fn;i++)
{
if(fdr[i]==fdl[i])
{
fdr[i]=fdr[fn-1];
fdl[i]=fdl[fn-1];
fn--;
}
}
}



/*int trans(){
//cout<<fn<<endl;
vector<pair<string,string>>pairs={};
for(int i=0;i<fn;i++){
pairs[i].first=fdr[i];
pairs[i].second=fdl[i];
pairs.push_back(make_pair(fdr[i],fdl[i]));
}
for(auto a:pairs){
for(auto b:pairs)
{
if(b.first==a.second)
{
for(auto c:pairs)
{
if(b.second==c.first&&c.second==a.first)
{
for(int z=0;z<fn;z++)
{
if(fdl[z]==c.first&&fdr[z]==c.second)
{
fdr[z]=fdr[fn-1];
fdl[z]=fdl[fn-1];
fn--;
return z;


break;
}
}
}
}
}
}
}
}
*/
//break;





//cout<<pairs[i].first;
//cout<<pairs[i].second;


for(int i=0;i<n;i++)
{
for(int j=0;j<fn;j++)










int main()
{
input();
int z=trans();
while(z!=-1)
z=trans();
//expand();
//equalremove();
//print();

return 0;
}
