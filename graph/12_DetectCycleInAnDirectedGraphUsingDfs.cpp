#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>adj[],int vis[],int pathVis[])
{
    vis[node]=1;
    pathVis[node]=1;
    
    // tarverse for adjacent nodes
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if((dfs(it,adj,vis,pathVis)==true)
            {
                return true;
            }
            // if the node has been previously visited
            // but it has to be evisited on the same path
            else if(pathVis[it])
            {
                return true;
            }
        }
    }
    pathVis[node]=0;
    return false;
}
bool iscyclic(int V,vector<int>adj[])
{
    int vis[V]={0};
    int pathVis[V]={0};
    int i;
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,pathvis)==true)
            {
                return true;
            }
        }
    }
    return false;
}
int main() {
	// your code goes here

// Detect cycle in a directed graph using dfs
// TC->O(V+E) and SC->O(2N) 
}
