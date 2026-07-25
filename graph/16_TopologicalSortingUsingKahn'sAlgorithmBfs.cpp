#include <bits/stdc++.h>
using namespace std;
vector<int>toposort(int V,vector<int>adj[])
{
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
        node is in your topo sortingso please remove it from thr indegree
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
        return topo;
    }
}   
int main() {
	// your code goes here
//  Topological sorting (kahn's algoritm /bfs)
// TC->O(V+E) SC->O(N)+O(N)
}
