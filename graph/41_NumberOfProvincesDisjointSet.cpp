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
int main() {
	// your code goes here
// Number of provinces disjoint set
int n,m;
	cin>>n>>m;
	int i;
	DisjointSet ds(n);
	for(i=0;i<m;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    ds.unionBySize(u,v);
	}
	int count=0;
	int j;
	for(i=1;i<=n;i++)
	{
	   if(ds.findUltimateParent(i)==i)
	   {
	       count++;
	   }
	}
	cout<<count<<endl;
}

// input
// 7 8
// 1 2
// 2 1
// 2 3 
// 3 2 
// 4 5 
// 5 4 
// 6 7  
// 7 6