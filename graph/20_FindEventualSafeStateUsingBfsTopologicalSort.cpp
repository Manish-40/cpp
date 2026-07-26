#include <bits/stdc++.h>
using namespace std;
vector<int>eventualSafeNodes(int V,vector<int>adj[])
{
    vector<int>adjReverse;
    int indegree[V]={0};
    int i;
    for(i=0;i<V;i++)
    {
        // i->it
        // it->i
        for(auto it:adj[i])
        {
            adjReverse[it].push_back(i);
          indegree[i]++;
        }
    }
    queue<int>q;
    vector<int>safeNodes;
    for(i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty)
    {
        int node=q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it:adjReverse[node])
        {
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}
int main() {
	// your code goes here
// Find eventual sfae state using bfs topological sort
// TC is same topo sort extra time is for sort NlogN SC is same topo sort adjReverseis extra space

}
