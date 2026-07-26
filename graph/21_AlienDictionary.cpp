#include <bits/stdc++.h>
using namespace std;
// works for multiple components and single components
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
        // node is in your topo sortingso please remove it from thr indegree
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
        
    }
    return topo;
}   
string findOrder(string dict[],int N,int k)
{
    // N number of strings
    // k number of alphabets
    vector<int>adj[k];
    int i;
    for(i=0;i<N-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        int ptr;
        for(ptr=0;ptr<len;ptr++)
        {
            if(s1[ptr]!=s2[ptr])
            {
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                // aa -'a' kem lakhyu to aena thi automatically convert thai jase 0 1 thi
                break;
            }
        }
    }
    vector<int>topo=toposort(K,adj);
    string ans="";
    for(auto it:topo)
    {
        ans=ans+char(it+'a');
        // aapde upper -'a' lakhyu to +'a' lakvathi pachu alphabet madi jase
    }
    return ans;
}
int main() {
	// your code goes here
// Find alien dictionary

}
