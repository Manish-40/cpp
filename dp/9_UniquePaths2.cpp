#include <bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int f(int i,int j,vector<vector<int>>&mat)
{
    // valid cell      invalid cell
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up=f(i-1,j);
    int left=f(i,j-1);
    return (up+left)%mod;
}
int mazeobstacles(int m,int n,vector<vector<int>>&mat)
{
    return f(m-1,n-1,mat);
}
int main() {
	// your code goes here
// recursison
}

#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat)
{
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j]=(up+left)%mod;
}
int mazeobstacles(int m,int n,vector<vector<int>>&mat)
{
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(m-1,n-1,,mat,dp);
}
int main() {
	// your code goes here
    // memoization
}


#include <bits/stdc++.h>
using namespace std;
int mazeobstacles(int m,int n,vector<vector<int>>&mat)
{
    int dp[m][n];
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else
            {
                int up=0;
                int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[m-1][n-1];
}
int main() {
	// your code goes here
    // tabulation
}



#include <bits/stdc++.h>
using namespace std;
int mazeobstacles(int m,int n,vector<vector<int>>&mat)
{
    vector<int>prev(n,0);
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        vector<int>cur(n,0);
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==-1) cur[j]=0;
            else if(i==0 && j==0) cur[j]=1;
            else
            {
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=cur[j-1];
                cur[j]=(up+left)%mod;
            }
        }
        prev=cur;
    }
    return prev[n-1];
}
int main() {
	// your code goes here
// space optimization
}


#include <bits/stdc++.h>
using namespace std;
int uniquepaths(int m,int n)
{
    int N=n+m-2;
    int r=m-1;
    double res=1;
    int i;
    for(i=1;i<=r;i++)
    {
        res=res+(N-r+i)/i;
    }
    return (int)res;
}
int main() {
	// your code goes here

}


