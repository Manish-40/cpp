#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,int col,int color[],vector<int>adj[])
{
    color[node]=col;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            if(dfs(it,!col,color,adj)==false) return false;
        }
        else if(color[it]==col)
        {
            return false;
        }
    }
    return true;
}
bool isbipartite(int V,vector<int>adj[])
{
    int color[V];
    int i;
    for(i=0;i<V;i++)
    {
        color[i]=-1;
    }
    for(i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(dfs(i,0,color,adj)==false)
            {
                return false;
            }
        }
    }
    return true;
}
int main() {
	// your code goes here
// 	Bipartite graph
// 	TC and SC same dfs code 

}
