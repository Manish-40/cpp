#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&matrix)
{
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    
    int up=matrix[i][j]+f(i-1,j,matrix);
    int leftDigonal=matrix[i][j]+f(i-1,j-1,matrix);
    int rightDigonal=matrix[i]j]+f(i-1,j+1,matrix);
    
    return max(up,max(leftDigonal,rightDigonal));
}
int getmaxpathsum(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int j;
    int maxi=-1e8;
    for(j=0;j<m;j++)
    {
        maxi=max(maxi,f(n-1,j,matrix));
    }
    return maxi;
}
int main() {
	// your code goes here
// 	Minimum maximum falling path sum
// recursion
// TC->O(3^N) exponential in nature SC->O(N)
}


#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>dp)
{
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up=matrix[i][j]+f(i-1,j,matrix,dp);
    int leftDigonal=matrix[i][j]+f(i-1,j-1,matrix,dp);
    int rightDigonal=matrix[i]j]+f(i-1,j+1,matrix,dp);
    
    return dp[i][j]=max(up,max(leftDigonal,rightDigonal));
}
int getmaxpathsum(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int j;
    int maxi=-1e8;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(j=0;j<m;j++)
    {
        maxi=max(maxi,f(n-1,j,matrix,dp));
    }
    return maxi;
}
int main() {
	// your code goes here
// 	Minimum maximum falling path sum
// memoization
// TC->O(N*M) SC->O(N*M)+O(N)
}


#include <bits/stdc++.h>
using namespace std;
int getmaxpathsum(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int j;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(j=0;j<m;j++)
    {
        dp[0][j]=matrix[0][j];
    }
    int i;
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int up=matrix[i][j]+dp[i-1][j];
            int leftDigonal=matrix[i][j]
            if(j-1>=0)leftDigonal+=dp[i-1][j-1];
            else leftDigonal+=-1e8;
            
            int rightDigonal=matrix[i]j]
            if(j+1<m)rightDigonal+=dp[i-1][j+1];
            else rightDigonal+=-1e8;
            
            dp[i][j]=max(up,max(leftDigonal,rightDigonal));
        }
    }
    int maxi=-1e8;
    for(j=0;j<m;j++)
    {
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}
int main() {
	// your code goes here
// 	Minimum maximum falling path sum
// tabulation
// TC->O(N*M)+o(M) SC->O(N*M)
}


#include <bits/stdc++.h>
using namespace std;
int getmaxpathsum(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int j;
    vector<int>prev(m,0);
    vector<int>cur(m,0);
    for(j=0;j<m;j++)
    {
        prev[j]=matrix[0][j];
    }
    int i;
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int up=matrix[i][j]+prev[j];
            int leftDigonal=matrix[i][j]
            if(j-1>=0)leftDigonal+=prev[j-1];
            else leftDigonal+=-1e8;
            
            int rightDigonal=matrix[i][j];
            if(j+1<m)rightDigonal+=prev[j+1];
            else rightDigonal+=-1e8;
            
            cur[j]=max(up,max(leftDigonal,rightDigonal));
        }
        prev=cur;
    }
    int maxi=-1e8;
    for(j=0;j<m;j++)
    {
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}
int main() {
	// your code goes here
// 	Minimum maximum falling path sum
// space optimization
// TC->O(N*M)+o(M) SC->O(N)
}



