#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>adj[],int vis[],int pathVis[],int check[])
{
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0
    // tarverse for adjacent nodes
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if((dfs(it,adj,vis,pathVis,check)==true)
            {
                check[node]=0;
                return true;
            }
            // if the node has been previously visited
            // but it has to be evisited on the same path
            else if(pathVis[it])
            {
                check[node]=0;
                return true;
            }
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}
vector<int>eventualsafenodes(int V,vector<int>adj[])
{
    int vis[V]={0};
    int pathVis[V]={0};
    int i;
    vector<int>safenodes;
    int check[V]={0};
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,pathvis,check);
        }
    }
    return false;
}
for(i=0;i<V;i++)
{
    if(check[i]==1) safenodes.push_back(i);
}
return safenodes;
int main() {
	// your code goes here
// 	Find eventual safe states

}
