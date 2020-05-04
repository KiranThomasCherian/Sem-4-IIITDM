#include <iostream>
#include<vector>
#include "Graph.h"
#include"module1.h"
#include"module2.h"
#include"module4.h"
#include"module5.h"
using namespace std;

int main()
{
    Graph G;
    int x,y,z;
    cout << "Enter 1 for directed and 0 for undirected: ";
    cin >> x;
    if(x == 1)
        G.directed = 1;
    
    cout << "Enter number of vertices: ";
    cin >> x;
    G.addVertex(x);

    cout << "Enter number of edges: ";
    cin >> z;

    for(int i = 1; i <= z; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> x >> y;
        G.addEdge(x,y);
    }
    G.showGraph();

    /*Remaining driver function is not implemented,i.e user input for example what to call, where to start etc..
    Also module 3 is as cpp file didnt integrate to pgm............
    BUT ALL FUNCTIONS DO WORK IN MOST OF THE CASES!!!! 

    MODULE 1,2,4 is fully integrated..just take input and call them manually for verification......

Test_articulationpoint(G);
Test_bridge(G);
Test_Bipartite(G);   
    
    //dfs(G);
    //dfs(G,5);
    //dfs(G,2,5);
    //bfs(G);
    //bfs(G,2);
    //bfs(3,6);



mst_Prim(Graph G);
mst_kruskal(Graph G);    

*/
    return 0;
}



