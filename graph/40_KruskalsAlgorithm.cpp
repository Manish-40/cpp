#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        int i;
        for(i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findUltimateParent(int node)
    {
        // parent itself aena mate
        if(node==parent[node]) return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int ultimate_u=findUltimateParent(u);
        int ultimate_v=findUltimateParent(v);
        if(ultimate_u==ultimate_v) return;
        if(rank[ultimate_u]<rank[ultimate_v])
        {
            parent[ultimate_u]=ultimate_v;
        }
        else if(rank[ultimate_v]<rank[ultimate_u])
        {
            parent[ultimate_v]=ultimate_u;
        }
        else
        {
            parent[ultimate_v]=ultimate_u;
            rank[ultimate_u]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int ultimate_u=findUltimateParent(u);
        int ultimate_v=findUltimateParent(v);
        if(ultimate_u==ultimate_v) return;
        if(size[ultimate_u]<size[ultimate_v])
        {
            parent[ultimate_u]=ultimate_v;
            size[ultimate_v]+=size[ultimate_u];
        }
        else
        {
            parent[ultimate_v]=ultimate_u;
            size[ultimate_u]+=size[ultimate_v];
        }
    }
};
int spanningTree(int V,vector<vector<int>>adj[])
{
    // undirected graph che aetle bidirectional edges
    // 1-2 weight=5
    // 1->{2,5}
    // 2->{1,5}
    
    // 5, 1, 2
    // 5, 2, 1
    vector<int,pair<int,int>>edges;
    int i;
    for(i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            int adjNode=it[0];
            int weight=it[1];
            it node=i;
            
            edges.push_back({weight,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstWeight=0;
    for(auto it:edges)
    {
        int weight=it.first;
        int u=it.second.first;
        int v=it.second.second;
        
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
        {
            mstWeight=weight;
            ds.unionBySize(u,v);
        }
    }
    return mstWeight;
}
int main() {
	// your code goes her
// 	Krushkals algorithm
// undirected graph
// TC->O(N+E)+MlogM+M*4*alpha*2
// SC->O(parent,size)+O(M)
}