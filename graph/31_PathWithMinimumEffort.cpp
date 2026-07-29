#include <bits/stdc++.h>
using namespace std;
int minimumeffort(vector<vector<int>>&heights)
{
    // {diff,{row,col}}
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;\
    
    int n=heights.size();
    int m=heights[0].size();
    
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    int deltarow[]={-1,0,1,0};
    int deltacol[]={0,1,0,-1};
    // TC->O(
    // E log V
    // n*m*4*log(n*m))
    // SC->O(n*m)
    while(!pq.empty())
    {
        auto it=pq.front();
        pq.pop();
        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;
        if(row==n-1 && col==m-1) return diff;
        // row-1,col
        // row,col+1
        // row+1,col
        // row,col-1
        int i;
        for(i=0;i<4;i++)
        {
            int newrow=row+deltarow[i];
            int newcol=col+deltacol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            {
                int newEffort=max(abs(heights[newrow][newcol]-heights[row][col]),diff);
                // aama tane newDiiff=2 madyu ane dist[newrow][newcol]=1e9 infinity hase to tya position par 2 newEffortnakhse
                if(newEffort<dist[newrow][newcol])
                {
                    dist[newrow][newcol]=newEffort;
                    pq.push({newEffort,{newrow,newcol}});
                }
            }
        }
    }
    return 0;
}
int main() {
	// your code goes here
// 	Path with minimum effort
}
