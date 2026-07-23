#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int i;
        int j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j]==0)
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

        int deltarow[]={-1,0,1,0};
        int deltacol[]={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dist[row][col]=step;
            for(i=0;i<4;i++)
            {
                int nrow=row+deltarow[i];
                int ncol=col+deltacol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
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
