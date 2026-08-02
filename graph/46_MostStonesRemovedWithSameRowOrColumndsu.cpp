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
int maxremove(vector<vector<int>>&stones,int n)
{
    int maxRow=0;
    int maxCol=0;
    for(auto it:stones)
    {
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[1]);
    }
    DisjointSet ds(maxRow+maxCol+1);
    unordered_set<int,int>stoneNodes;
    for(auto it:stones)
    {
        int nodeRow=it[0];
        int nodeCol=it[1];
        ds.unionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow]=1;
        stoneNodes[nodeCol]=1;
    }
    int count=0;
    for(auto it:stoneNodes)
    {
        if(ds.findUltimateParent(it.first)==it.first)
        {
            count++;
        }
    }
    return n-count;
}
int main() {
	// your code goes here
// Most stones removed with same row or column

}
