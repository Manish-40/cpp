#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, int color[],bool graph[101][101], int n, int col)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(j!=node && graph[j][node]==1 && color[j]==col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if(node==N)
    {
        return true;
    }
    
    int i;
    for(i=1;i<=m;i++)
    {
        if(isSafe(node,color,graph,N,i))
        {
            color[node]=i;
            if(solve(node+1, color, m, N,graph)) return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N]={0};
    if(solve(0,color,m,N,graph)) return true;
    return false;
}
int main() {
	// your code goes here
	
	int N = 4; // Number of nodes
    int m = 3; // Number of colors
    
    bool graph[101][101] = {false};
    
    // Add edges (example graph)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    
    if (graphColoring(graph, m, N)) {
        cout << "Solution Exists";
    } else {
        cout << "No Solution";
    }

}
