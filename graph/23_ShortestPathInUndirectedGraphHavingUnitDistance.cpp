#include <bits/stdc++.h>
using namespace std;
vector<int>shortestpath(vector<vector<int>>&endges,int N,int M,int src)
{
    vector<int>adj[N];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dist[N];
    int i;
    for(i=0;i<N;i++)
    {
        dist[i]=1e9;
    }
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    vector<int>ans(N,-1);
    for(i=0;i<N;i++)
    {
        if(dist[i]!=ie9)
        {
            ans[i]=dist[i];
        }
    }
    return ans;
}
int main() {
	// your code goes here
// 	Shortest path in undirected graph having unit distance
// TC is same bfs SC->vector<int>adj queue<int>q
}
