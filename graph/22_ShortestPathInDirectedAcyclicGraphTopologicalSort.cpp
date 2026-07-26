#include <bits/stdc++.h>
using namespace std;
void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        int v=it.first;
        if(!vis[v])
        {
            toposort(v,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int>shortestpath(int N,int M,vector<int>edges[])
{
    // N number of nodes
    // M number of edges
    // edges u,v and weight che aa vector<int>edges[] main
    vector<pair<int,int>>adj[N];
    int i;
    for(i=0;i<M;i++)
    {
// aa edges 1 element ma vector store karyu che jemke 1->2,3 u=1 v=2 weight=3
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];
        adj[u].push_back({v,weight});
    }
    // find the topo sort
    int vis[N]={0};
    stack<int>st;
    for(i=0;i<N;i++)
    {
        if(!vis[i])
        {
            toposort(i,adj,vis,st);
        }
    }
    // do the distance thing
    
    vector<int>dist(N);
    for(i=0;i<N;i++)
    {
        dist[i]=1e9;
    }
    dist[0]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        for(auto it:adj[node])
        {
            int v=it.first;
            int weight=it.second;
            
            if(dist[node]+weight<dist[v])
            {
                dist[v]=dist[node]+weight
            }
        }
    }
    return dist;
    
}
int main() {
	// your code goes here
// Shortest path in directed acyclic graph
// TC is same topo sort SC is same as topo sort

}
