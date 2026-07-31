#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,vector<vector<int>>adj[])
{
    // O(E)
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // O(V)
    vector<int>vis(V,0);
    // {weight,node}
    pq.push({0,0});
    int sum=0;
    // E log E+E log E
    // E log E
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int weight=it.first;
        if(vis[node]==1) continue;
        // add it to the mst
        vis[node]=1;
        sum=sum+weight;
        // E log E
        for(auto it:adj[node])
        {
            int adjNode=it[0];
            int edgeW=it[1];
            if(!vis[adjNode])
            {
                pq.push({edgeW,adjNode});
            }
        }
    }
    return sum;
    
}
int main() {
	// your code goes her
// 	Prims algorithm minimum spanning tree
// aama khali sum return karvanu hatu mst natu return karvanu to e nathi banavyu and store bhi nathi karyu pq ma parent
// TC->O(E log E) SC->O(E)
}