#include <bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<int>>&arr,int n,vector<string>&ans,
string move,vector<vector<int>>&vis)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    
    // downward
    if(i+1<n && !vis[i+1][j] && arr[i+1][j]==1)
    {
        vis[i][j]=1;
        solve(i+1,j,arr,n,ans,move+'D',vis);
        vis[i][j]=0;
    }
    
    // left
    if(j-1>=0 && !vis[i][j-1] && arr[i][j-1]==1)
    {
        vis[i][j]=1;
        solve(i,j-1,arr,n,ans,move+'L',vis);
        vis[i][j]=0;
    }
    
    // right
    if(j+1<n && !vis[i][j+1] && arr[i][j+1]==1)
    {
        vis[i][j]=1;
        solve(i,j+1,arr,n,ans,move+'R',vis);
        vis[i][j]=0;
    }
    
    // upward
    if(i-1>=0 && !vis[i-1][j] && arr[i-1][j]==1)
    {
        vis[i][j]=1;
        solve(i-1,j,arr,n,ans,move+'U',vis);
        vis[i][j]=0;
    }
}
int main() {
	// your code goes here
	vector<vector<int>>arr={{1,0,0,0},
	                        {1,1,0,1},
	                        {1,1,0,0},
	                        {0,1,1,1}};
	                     
	 int n=arr.size();
	 
	 vector<string>ans;
	 vector<vector<int>>vis(n,vector<int>(n,0));
	 
	 if(arr[0][0]==1)
	 {
	     solve(0,0,arr,n,ans,"",vis);
	 }
	 
	 int i;
	 int j;
	 for(i=0;i<ans.size();i++)
	 {
	     cout<<ans[i]<<endl;
	 }

}


#include <bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<int>>&arr,int n,vector<string>&ans,
string move,vector<vector<int>>&vis, int di[], int dj[])
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    
    string dir="DLRU";
    int index;
    for(index=0;index<4;index++)
    {
        int next_i=i+di[index];
        int next_j=j+dj[index];
        
        if(next_i>=0 && next_j>=0 && next_i<n && next_j<n &&
        !vis[next_i][next_j] && arr[next_i][next_j]==1)
        {
            vis[next_i][next_j]=1;
            solve(next_i,next_j,arr,n,ans,move+dir[index],vis,di,dj);
            vis[next_i][next_j]=0;
        }
    }
}
int main() {
	// your code goes here
	vector<vector<int>>arr={{1,0,0,0},
	                        {1,1,0,1},
	                        {1,1,0,0},
	                        {0,1,1,1}};
	                     
	 int n=arr.size();
	 
	 vector<string>ans;
	 vector<vector<int>>vis(n,vector<int>(n,0));
	 
	 int di[]={1,0,0,-1};
	 int dj[]={0,-1,1,0};
	 
	 if(arr[0][0]==1)
	 {
	     solve(0,0,arr,n,ans,"",vis,di,dj);
	 }
	 
	 int i;
	 int j;
	 for(i=0;i<ans.size();i++)
	 {
	     cout<<ans[i]<<endl;
	 }

}
