#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&,vector<int>adj[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs3(int node,vector<int>&vis,vector<int>adjT[])
{
    vis[node]=1;
    for(auto it:adjT[node])
    {
        if(!vis[it])
        {
            dfs3(it,vis,adjT);
        }
    }
}
int kasaraju(int V,vector<int>adj[])
{
    // O(2*V)
    vector<int>vis(V,0);
    stack<int>st;
    // O(V+E)
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    // O(V+E)
    vector<int>adjT(V);
    // O(V+E)
    for(int i=0;i<V;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            // i->it
            // it->i
            adjT[it].push_back(i);
        }
    }
    int scc=0;
    // O(V+E)
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}
int main() {
	// your code goes here
// 	Strongly connected components kosarajus algorithm
// TC->O(V+E) SC->O(2*V)+O(V+E)

}
