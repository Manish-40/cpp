#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int i;
    int j;
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else
            {
                vis[i][j]=0;
            }
        }

    }
    
    int deltarow[]={-1,0,+1,0};
    int deltacol[]={0,1,0,-1};
    
    // n*m*4
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().seond;
        q.pop();
        dist[row][col]=steps;
        
        for(i=0;i<n;i++)
        {
            int nrow=row+deltarow[i];
            int ncol=col+deltacol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    return dist;
}
int main() {
	// your code goes here
// 	Distance of nearest cell having 1 in leetcode 0 1 matrix

// TC->O(N*M) SC->O(N*M)

}
