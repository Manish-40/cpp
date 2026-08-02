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
bool isValid(int newr,int newc,int n)
{
    return newr>=0 && newr<n && newc>=0 && newc<n;
}
int maxconnection(vector<vector<int>>&grid)
{
    int n=grid.size();
    DisjointSet ds(n*n);
    // step 1 connecting componenets
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==0) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int ind=0;ind<4;ind++)
            {
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(isValid(newr,newc,n) && grid[newr][newc]==1)
                {
                    int nodeNo=row*n+col;
                    int adjNodeNo=newr*n+newc;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==1) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            set<int>components;
            for(int ind=0;ind<4;ind++)
            {
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(isValid(newr,newc,n))
                {
                    if(grid[newr][newc]==1)
                    {
                    components.insert(ds.findUltimateParent(newr*n+newc));
                    }
                }
            }
            int sizeTotal=0;
            for(auto it:components)
            {
                sizeTotal+=ds.size[it];
            }
            mx=max(mx,sizeTotal+1);
        }
    }
    // aa aena mate ke badha matrix ma 1 hoy to aena mate
    for(int cellNo=0;cellNo<n*n;cellNo++)
    {
        mx=max(mx,ds.size[findUltimateParent(cellNo)]]);
    }
    return mx;
}
int main() {
	// your code goes here
// Making a large island dsu
// TC->O(N^2)

}
