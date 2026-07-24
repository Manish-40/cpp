#include <bits/stdc++.h>
using namespace std;
bool check(int start,int V, vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(start);
    color[star]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            // if the adjacent node is yet not colored
            // you will give the opposite color of the node
            if(color[it]==-1)
            {
            color[it]=!color[node];
            q.push(it);
            }
            // is the adjacent guy having the same color
            // someone did color it on same other path
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isbipartite(int V,vector<int>adj[])
{
    int color[V];
    int i;
    for(i=0;i<V;i++)
    {
        color[i]=-1;
    }
    // aa connected component mate karyu
    for(i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(check(i,V,adj,color)==false)
            {
                return false;
            }
        }
    }
    return true;
}
int main() {
	// your code goes here
// 	Bipartite graph
// 	TC and SC same bfs code 

}
