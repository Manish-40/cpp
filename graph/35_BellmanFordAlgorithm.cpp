#include <bits/stdc++.h>
using namespace std;
vector<int>bellman_ford(int V,vector<vector<int>>&edges,int S)
{
    vector<int>dist(V,1e8);
    dist[S]=0;
    int i;
    for(i=0;i<V-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            if(dist[u]!=1e8 && dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }
        }
    }
    // Nth relaxation to check negative cycle
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        int weight=it[2];
        if(dist[u]!=1e8 && dist[u]+weight<dist[v])
        {
            return {-1};
        }
    }
    return dist;
}
int main() {
	// your code goes here
// Bellman ford algorithm
// TC->O(V*E)
}
