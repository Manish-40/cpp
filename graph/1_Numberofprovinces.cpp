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
// number of provinces
// TC->O(N)+O(N+(2*E)) SC->O(N)+O(N)
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
	vector<int>ls;
	int count=0;
	for(i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        count=count+1;
	        dfs(i,adj,vis,ls);
	    }
	}
	for(auto it:ls)
	{
	    cout<<it<<endl;
	}
	
	cout<<"number of provinces "<<count<<endl;
	
// input
// 8 5
// 1 2 
// 2 3
// 4 5
// 5 6
// 7 8

}
