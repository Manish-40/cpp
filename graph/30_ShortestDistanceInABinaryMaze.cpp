#include <bits/stdc++.h>
using namespace std;
int shortestpath(vector<vector<int>>&grid,pair<int,int>source,pair<int,int>destination)
{
    queue<int,pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[source.first][source.second]=0;
    q.push({0,{source.first,source.second}});
    int deltarow[]={-1,0,1,0};
    int deltacol[]={0,1,0,-1};
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.first;
        int i;
        for(i=0;i<4;i++)
        {
            int newr=r+deltarow[i];
            int newc=c+deltacol[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 &&dis+1<dist[newr][newc]
            )
            {
                dist[newr][newc]=1+dis;
                if(newr==destination.first && newc==destination.second)
                {
                    return dis+1;
                }
                q.push({dis+1,{newr,newc}});
            }
        }
    }
    return -1;
    
}
int main() {
	// your code goes here
// 	Shortest distance in a binary maze

}
