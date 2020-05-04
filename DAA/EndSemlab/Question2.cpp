/* 
SET 8:Question 2-Longest Path in Graph

LOGIC:    ---FOR DAG

the longest path in a DAG does have optimal substructure, which allows us to solve for it using dynamic programming
A DAG can always be topologically sorted , which allows us to traverse the vertices in linearized order from left to right.
Souce(s) distance is taken as 0;
we perform topological sort
The for each v dis(v) from s=max(dis(ancestor1 from s)+edge weight,dis(ancestor2 from s)+edge weight,..);
this is reccured and  we can compute this bottom-up for each vertex v belongsto V taken in a linearized order
Finally if we take max of all paths we can get the required answer
Algorithm:
longest-path(G)
Input:Weighted DAG G =(V, E)
Output: Largest path cost in G
    Topologically sort G
    for each vertex v ∈ V in linearized(topological) order
    do dis(v) = max(u,v) belongsto E {dis(u) + w(u, v)}
    return max v belongsto V {dis(v)}


*/

#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
int mdis=INT_MIN;
int flag=0;
using namespace std;

class edges
{
int v;
int weight;
public:
edges(int vv,int ww)
{
v = vv;
weight = ww;}
int returnv()
{
return v;}
int returnweight()
{
return weight;}
};
class Graph
{
int V;//No. of vertices’
list<edges> *adj;
void toposort(int v, bool visit[], stack<int> &Stack);

public:
Graph(int V)
{
this->V =V;
adj = new list<edges> [V];
}
void addedge(int u,int v,int weight)
{
edges node(v,weight);
adj[u].push_back(node);
}
void lpath(int s)
{
stack<int> Stack;
int dis[V];
bool *visit = new bool[V];
for (int i = 0;i < V;i++)
visit[i] = false;
for (int i = 0; i < V; i++)
{
    if (visit[i] == false)
    toposort(i, visit, Stack);
}   
for(int i = 0;i<V;i++)
dis[i] = INT_MIN;
dis[s] = 0;
while (Stack.empty()==false)
{
int u =Stack.top();
Stack.pop();
list<edges>::iterator i;
if (dis[u] != INT_MIN)
{
for(i =adj[u].begin();i!= adj[u].end();i++)
if(dis[i->returnv()]<dis[u]+i->returnweight())
dis[i->returnv()]=dis[u]+i->returnweight();
}
}

for (int i=0;i <V;i++)
{
if(flag==0)
(dis[i]==INT_MIN)?cout<<" infinity ":cout<<dis[i]<<" ";
if(dis[i]>mdis)
mdis=dis[i];
}
//cout<<"\nAnd Longest path distance : "<<mdis;
}


};
void Graph::toposort(int v, bool visit[], stack<int> &Stack)
{
visit[v] = true;
list<edges>::iterator i;
for(i =adj[v].begin(); i!=adj[v].end();i++)
        {
        edges node = *i;
        if(!visit[node.returnv()])
        toposort(node.returnv(),visit,Stack);
        }
    Stack.push(v);
}


int main()
{
int n,nv;
cout<<"0 is the source vertex and vetices are 0,1,2..n-1";
cout<<"\nEnter number of vertices of DAG(n) :";
cin>>n;
Graph G(n);
int s,d,w;
cout<<"Enter number of edges : ";
cin>>nv;
cout<<"Note:If undirected graph give weight as 1 for all edges\n";
cout<<"Enter source destination and weight in that order:\n";
for(int i=0;i<nv;i++)
{
cin>>s>>d>>w;
G.addedge(s, d, w);
}
s=0;
cout<<"Path values from source :"<<"\n";
G.lpath(s);
flag=1;
cout<<"\n\n";
for(int i=0;i<n;i++)
{
G.lpath(i);

}
cout<<"\nand Longest path in graph(Need not be from source , considering overall ) = "<<mdis;    //had no time to print path, start and stop can be found from where we update mdis
return 0;
}