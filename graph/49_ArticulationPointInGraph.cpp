#include <bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],
vector<int>&mark,vector<int>adj[])
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(!vis[it])
        {
            dfs(it,node,vis,tin,low,mark,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node] && parent!=-1)
            {
                mark[node]=1;
            }
            child++;
        }
        else
        {
            low[node]=min(low[node],tin[it]);
        }
    }
    if(child>1 && parent==-1)
    {
        mark[node]=1;
    }
}
vector<int>articulationpoints(int n,vector<int>adj[])
{
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<int>mark(n,0);
    int i;
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,tin,low,mark,adj);
        }
    }
    vector<int>ans;
    for(i=0;i<n;i++)
    {
        if(mark[i]==1)
        {
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
}
int main() {
	// your code goes here
// 	Articulation point in graph
// TC->O(V+2E)+O(N) SC->O(3N)
}
