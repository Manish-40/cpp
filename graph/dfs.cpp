#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
{
    vis[node]=1;
    ls.push_back(node);
    // travese all its neighbours
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
        dfs(it,adj,vis,ls);
        }
    }
}
int main() {
	// your code goes here
// 	dfs traversal in a graph
// TC->O(N)+(2*E) SC->O(N)+O(N)+O(n)=O(N)
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	int i;
	for(i=0;i<m;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int vis[n+1]={0};
	int start=1;
	vector<int>ls;
	dfs(start,adj,vis,ls);
	for(auto it:ls)
	{
	    cout<<it<<endl;
	}
// input
// 8 8
// 1 2
// 1 3
// 2 5 
// 2 6
// 3 4 
// 3 7
// 4 8
// 7 8

}
