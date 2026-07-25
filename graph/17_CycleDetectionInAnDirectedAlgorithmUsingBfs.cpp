#include <bits/stdc++.h>
using namespace std;
bool iscyclic(int V,vector<int>adj[])
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
    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        node is in your topo sortingso please remove it from thr indegree
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) count=count+1;
        }
        // count == V thayu to cycle nathi aetle false
        if(count==V) return false;
        // else ma true cycle che
        return true;
}
int main() {
	// your code goes here
// Cycle detection in directed graph using bfs
// TC->O(V+E) SC->O(N)+O(N) 
}
