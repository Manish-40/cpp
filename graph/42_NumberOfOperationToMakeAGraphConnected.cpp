#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int>rank,parent,size;
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
int solve(int n,vector<vector<int>>&edge)
{
    DisjointSet ds(n);
    int countExtra=0;
    for(auto it:edge)
    {
        int u=it[0];
        int v=it[1];
        if(ds.findUltimateParent(u)==ds.findUltimateParent(v))
        {
            countExtra++;
        }
        else
        {
            ds.unionBySize(u,v);
        }
    }
    int numberOfComponent=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(ds.parent[i]==i)
        {
            numberOfComponent++;
        }
    }
    int ans=numberOfComponent-1;
    if(countExtra>=ans)
    {
        return ans;
    }
    return -1;
    
}
int main() {
	// your code goes here
// Number of operatins to make network connected

}
