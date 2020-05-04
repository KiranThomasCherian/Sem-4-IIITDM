#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char a[10];

string fd[50][2];
string fdr[50][2];
int q=0;
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
getline(cin,fd[i][0]);
printf("Enter rhs of fd %d : ",i+1);
getline(cin,fd[i][1]);
}
}
void print(){
for(int i=0;i<fn;i++)
{
cout<<fd[i][0];
printf(" -> ");
cout<<fd[i][1];
cout<<endl;
}

/*cout<<"others"<<endl;
for(int i=0;i<q;i++)
{
cout<<fdr[i][0];
printf(" -> ");
cout<<fdr[i][1];
cout<<endl;
}
*/

}
void equalremove()                      //not working
{
string fdr[25];
string fdl[25];
for(int i=0;i<fn;i++)
{
    fdl[i]=fd[i][0];
    fdr[i]=fd[i][1];
}
for(int i=0;i<fn;i++)
{
    for(int j=i+1;j<fn;j++)
    {
        if((fdr[i]==fdr[j])&&(fdl[i]==fdl[j]))
        {
        fdr[j]=fdr[fn-1];
        fdl[j]=fdl[fn-1];
        fn--;
        cout<<"here";
        break; 
        }
    }
}

for(int i=0;i<fn;i++)
{
fd[i][0]=fdl[i];
fd[i][1]=fdr[i];
}
 

}


void expand(){
string fdr[25];
string fdl[25];
for(int i=0;i<fn;i++)
{
    fdl[i]=fd[i][0];
    fdr[i]=fd[i][1];
}

int nnow=fn;
for(int i=0;i<nnow;i++)
{
//cout<<sizeof(fdr[i])<<endl;
if(fdl[i].size()==1)
{
//string temp;
//strcpy(temp,fd[i][1]);
for(int k=1;k<fdr[i].size();k++)
{
fdl[fn]=fdl[i];
fdr[fn]=fdr[i][k];
fn++;
}
fdr[i]=fdr[i][0];
//printf("here");
}

}
for(int i=0;i<fn;i++)                 //duplicte remove
{
if(fdr[i]==fdl[i])
{
fdr[i]=fdr[fn-1];
fdl[i]=fdl[fn-1];
fn--;
}
}

for(int i=0;i<fn;i++)
{
fd[i][0]=fdl[i];
fd[i][1]=fdr[i];
}
 
 
 }

void trans(){
//cout<<fn<<endl;
//vector<pair<string,string>>pairs={};
//for(int i=0;i<fn;i++){
//pairs[i].first=fdr[i];
//pairs[i].second=fdl[i];
//pairs.push_back(make_pair(fdr[i],fdl[i]));
for(int i=0;i<fn;i++)
{
    for(int j=(i+1)%fn;j!=i;j=(j+1)%fn)
    {
        for(int k=(j+1)%fn;k!=j;k=(k+1)%fn)
        {
            if(fd[i][1]==fd[j][0]&&fd[j][1]==fd[k][1])
            {
                if(fd[k][0]==fd[i][0])
                {
                    fdr[q][0]=fd[k][0];
                    fdr[q][1]=fd[k][1];
                    q++;
                
            
                                      
                    
                    
                    fd[k][0]="zz";
                    fd[k][1]="zz";
                    
                    
                                    }


                }



            }
        }
    }


string fdr[25];
string fdl[25];
for(int i=0;i<fn;i++)
{
    fdl[i]=fd[i][0];
    fdr[i]=fd[i][1];
}

for(int i=0;i<fn;i++)                 //duplicte remove
{
if(fdr[i]==fdl[i])
{
fdr[i]=fdr[fn-1];
fdl[i]=fdl[fn-1];
fn--;
i--;                //if last becomes zz case
}
}

for(int i=0;i<fn;i++)
{
fd[i][0]=fdl[i];
fd[i][1]=fdr[i];
}
 



}

void calc()
{
for(int k=0;k<n;k++)
{
    char dep[n];
    string fdr[25];
    string fdl[25];
    for(int i=0;i<fn;i++)
    {
    fdl[i]=fd[i][0];
    fdr[i]=fd[i][1];
    }
        int deps=0;
    for(int i=0;i<fn;i++)
    {
    //vector<string>assos={};
    

    if(fdl[i].size()==1&&(fdl[i][0])==a[k])
    {
     dep[deps++]=fdr[i][0];
    }
    //cout<<deps<<endl;
    }    
for(int i=0;i<fn;i++)
{
    if(fdl[i].size()!=1)
    {
        for(int z=0;z<fdl[i].size();z++)
        {
           // for(char zz:dep)
           // {
               //cout<<z<<endl;
            if(fdl[i][z]==a[k])
            {
                //cout<<"here";
                string temp=fdl[i];
                int ss=temp.size();
               // cout<<ss<<endl;
               for(int q=0;q<ss;q++)
               {
                   for(int r=0;r<strlen(dep);r++)
                   {
                  // cout<<temp[q]<<" "<<dep[r]<<endl;
                   if(temp[q]==dep[r])
                   {    if(q==ss-1)
                   temp[q]='\0';
                   else{
                       temp[q]=temp[q+1];
                       q--;
                   }
                       ss--;
                      //cout<<"here"<<fdl[i]<<" "<<dep[r]<<temp[q+1]<<endl;
                       break;
                   }
                   }
               }
               fdl[i]=temp;
               //cout<<fdl[i];
            }
            
        }
    }
}

for(int i=0;i<fn;i++)
{
fd[i][0]=fdl[i];
fd[i][1]=fdr[i];
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


//for(int i=0;i<n;i++)
//{
//for(int j=0;j<fn;j++)










int main()
{
input();
expand();
//trans();



calc();
trans();
equalremove();      //not working
print();

return 0;
}
