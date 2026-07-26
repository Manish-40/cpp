#include <bits/stdc++.h>
using namespace std;
vector<int>findOrder(int V,int m,vector<vector<int>>prerequisites)
{
    vector<int>adj[V];
    for(auto it:prerequisites)
    {
        adj[it[1]].push_back(it[0]);
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
    if(topo.size()==V) return topo;
    return {};
}
int main() {
	// your code goes here
// 	Couser schedule 1 and 2 ma khali pair ne reverse karvanu che 0, 1 to 1 connected to 0

}
