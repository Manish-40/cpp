#include <bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int deltarow[],int deltacol[],int iniColor)
{
    ans[row][col]=newColor;
    int i;
    int n=image.size();
    int m=image[0].size();
    for(i=0;i<=4;i++)
    {
        int nrow=row+deltarow[i];
        int ncol=col+deltacol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && image[nrow][ncol]!=newColor)
        {
            dfs(nrow,ncol,ans,image,newColor,deltarow,deltacol,iniColor);
        }
    }
}
vector<vector<int>>floodFill(vector<vector<int>>&image,int sr,int sc,int newColor)
{
    int iniColor=image[sr][sc];
    vector<vector<int>>ans=image;
    int deltarow[]={-1,0,+1,0};
    int deltacol[]={0,+1,0,-1};
    dfs(sr,sc,ans,image,newColor,deltarow,deltacol,iniColor);
}
int main() {
	// your code goes here
// Flood fill algorithm

// TC->O(N*M) SC->O(N*M)+O(N*M)


}
