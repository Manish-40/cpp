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
bool isValid(int adjr,int adjc,int n,int m)
{
    return (adjr>=0 && adjr<n && adjc>=0 && adjc<m);
}
vector<int>numberofislands(int n,int m,vector<vector<int>>&operators)
{
    DisjointSet ds(n*m);
    int vis[n][m];
    memset(vis,0,sizeof vis);
    int count=0;
    vector<int>ans;
    for(auto it:operators)
    {
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1)
        {
            ans.push_back(count);
            continue;
        }
        vis[row][col]=1;
        count++;
        // row-1,col
        // row,col+1
        // row+1,col
        // row,col-1
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ind;
        for(ind=0;ind<4;ind++)
        {
            int adjr=row+dr[i];
            int adjc=col+dc[i];
            if(isValid(adjr,adjc,n,m))
            {
                if(vis[adjr][adjc]==1)
                {
                    int nodeNo=row*m+col;
                    int adjNodeNo=adjr*m+adjc;
                    if(ds.findUltimateParent(nodeNo)!=ds.findUltimateParent(adjNodeNo))
                    {
                        count--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}
int main() {
	// your code goes here
// 	Number of islands 2 online queries dsu

}
