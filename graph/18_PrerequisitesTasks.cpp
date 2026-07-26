#include <bits/stdc++.h>
using namespace std;
bool ispossible(int V,vector<pair<int,int>>&prerequisites)
{
    vector<int>adj[V];
    for(auto it:prerequisites)
    {
        adj[it.first].push_back(it.second);
    }
    int indegree[V]={0};
    int i;
    for(i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(i=0;i<V;i++)
    {
        if (indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sortingso please remove it from thr indegree
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(topo.size()==V) return true;
    return false;
}
int main() {
	// your code goes here
// pre requisite tasks
}
