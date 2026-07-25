#include <bits/stdc++.h>
using namespace std;
void dfs(int node,int vis[],stack<int>&st,vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it]) dfs(node,vis,st,adj);
    }
    st.push(node);
}
vector<int>toposort(int V,vector<int>adj[])
{
    int vis[V]={0};
    stack<int>st;
    int i;
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main() {
	// your code goes here
//  Topological sorting (DFS) 
// TC->O(V+E) SC->O(N)+O(N)
}
