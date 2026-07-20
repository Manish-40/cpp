#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vectro<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    // {{row,col},time}
    queue<pair<pair<int,int>,int>>q;
    int vis[n][m];
    int contFresh=0;
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else
            {
                vis[i][j]=0;
            }
            if(grid[i][j]==1) contFresh=contFresh+1;
        }
    }
    int time1=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    int count=0;
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        time1=max(time1,t);
        q.pop();
        for(i=0;i<4;i++)
        {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    count=count+1;
                }
        }
    }
    if(count!=contFresh) return -1;
    return time1;
    
}
int main() {
	// your code goes here
// 	TC->O(N*M)+(N*M*4) = O(N*M) SC->(N*M)

}
