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
vector<vector<string>>mergedetails(vector<vector<string>>&details)
{
    int n=details.size();
    DisjointSet ds(n);
    unordered_map<string,int>mapMailNode;
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            string mail=details[i][j];
            if(mapMailNode.find(mail)==mapMailNode.end())
            {
                mapMailNode[mail]=i;
            }
            else
            {
                ds.unionBySize(i,mapMailNode[mail]);
            }
        }
    }
    vector<string>mergeMail(n);
    for(auto it:mapMailNode[])
    {
        string mail=it.first;
        int node=ds.findUltimateParent(it.second);
        mergeMail[node].push_back(mail);
    }
    
    vector<vector<string>>ans;
    
    for(i=0;i<n;i++)
    {
        if(mergeMail[i].size()==0)continue;
        sort(mergeMail[i].begin(),mergeMail[i].end());
        vector<string>temp;
        temp.push_back(details[i][0]);
        for(auto it:mergeMail[i])
        {
            temp.push_back(temp);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main() {
	// your code goes here
// 	Accounts merge merging details

}
