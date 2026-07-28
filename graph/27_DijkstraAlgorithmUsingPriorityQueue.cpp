#include <bits/stdc++.h>
using namespace std;
vector<int>dijkstra(int V,vector<vector<int>>adj[],int S)
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>dis(V);
int i;
for(i=0;i<V;i++)
{
    dis[i]=1e9;
}
dis[S]=0;
pq.push({0,S});
while(!pq.empty())
{
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto it:adj[node])
    {
        int edgeWeight=it[1];
        int adjNode=it[0];
        
        if(dis+edgeWeight<dis[adjNode])
        {
            dis[adjNode]=dis+edgeWeight;
            pq.push({dis[adjNode],adjNode});
        }
    }
}
return dis;
}
int main() {
	// your code goes here
// 	Dijkstra's algorithm
// TC->O(ElogV)
// E number of edges V number of nodes
}
