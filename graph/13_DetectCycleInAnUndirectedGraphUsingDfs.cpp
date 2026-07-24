#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent, int vis[],vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(dfs(it,node,vis,adj)==true)
        {
            return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}
bool iscyclic(int V,vector<int>adj[])
{
    int vis[V]={0};
    int i;
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,vis,adj)==true)
            {
                return true;
            }
        }
    }
    return false;
}
int main() {
	// your code goes here

// Detect cycle in a undirected graph using dfs
// TC->O(N+2E)+O(N) and SC->O(N)+O(N) 
}
