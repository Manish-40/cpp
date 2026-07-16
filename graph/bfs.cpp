#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	bfs traversal of graph
// TC->O(N)+O(2*E) SC->O(3N)
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
	queue<int>q;
	q.push(1);
	vis[1]=1;
	vector<int>bfs;
	while(!q.empty())
	{
	    int node=q.front();
	    q.pop();
	    bfs.push_back(node);
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            vis[it]=1;
	            q.push(it);
	        }
	    }
	}
	for(auto it:bfs)
	{
	    cout<<it<<endl;
	}

}
