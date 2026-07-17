#include <bits/stdc++.h>
using namespace std;
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid)
{
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();
    
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.fornt().second;
        q.pop();
        
        // traverse in the neighbours and mark them if it is land
        
        for(int deltarow=-1;deltarow<=1;deltarow++)
        {
            for(deltacol=-1;deltacol<=1;deltacol++)
            {
                int nrow=row+deltarow;
                int ncol=col+deltacol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
}
int numberofislands(vector<vector<char>>grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0)); // visarr matrix banavyu
    int count=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(!vis[row][col] && grid[row][col]=='1')
            {
                count=count+1;
                bfs(row,col,vis,grid);
            }
        }
    }
    return count;
    
}
int main() {
	// your code goes here
// 	TC->O(N^2) SC->O(N^2)+queueO(N^2) 
}
