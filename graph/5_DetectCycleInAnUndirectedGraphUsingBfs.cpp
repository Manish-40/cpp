#include <bits/stdc++.h>
using namespace std;
bool detect(int src,vector<int>adj[],int vis[])
{
    vis[src]=1;
    std::queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjacentNode:adj[node])
        {
            if(!vis[adjacentNode])
            {
            vis[adjacentNode]=1;
            q.push({adjacentNode,node});
            }
            else if(parent!=adjacentNode)
            {
                return true;
            }
        }
    }
    return false;
}
bool iscycle(int V,vector<int>adj[])
{
    int vis[V]={0};
    int i;
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;
}
int main() {
	// your code goes here
// Detecting cycle in an undirected graph BFS
// adj list


// degree of graph=2*Edges
// TC->O(N+2Edge)+O(N)
// SC->O(N)+O(N)=O(N)

}
