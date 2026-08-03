#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&triangle,int n)
{
    if(i==n-1)
    {
        return triangle[n-1][j];
    }
    int down=triangle[i][j]+f(i+1,j,triangle,n);
    int digonal=triagle[i][j]+f(i+1,j+1,triangle,n);
    return min(down,digonal);
}
int minumumpathsum(vector<vector<int>>&triangle,int n)
{
    return f(0,0,triangle,n);
}
int main() {
	// your code goes here
// Triangle fixed starting point and variable ending point dp on grids
// recursion
// TC->O(2^1+2+3+....n) SC->O(N)
// memoization
// TC->O(N*N) SC->O(N)+O(N*N)
// tabulation
// TC->O(N*N) SC->O(N*n)
// space optimization
// TC->O(N*N) SC->O(N)
}


#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp)
{
    if(i==n-1)
    {
        return triangle[n-1][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int digonal=triagle[i][j]+f(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(down,digonal);
}
int minumumpathsum(vector<vector<int>>&triangle,int n)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}
int main() {
	// your code goes here
// Triangle fixed starting point and variable ending point dp on grids
// recursion
// TC->O(2^1+2+3+....n) SC->O(N)
// memoization
// TC->O(N*N) SC->O(N)+O(N*N)
// tabulation
// TC->O(N*N) SC->O(N*n)
// space optimization
// TC->O(N*N) SC->O(N)
}


#include <bits/stdc++.h>
using namespace std;
int minumumpathsum(vector<vector<int>>&triangle,int n)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int i;
    int j;
    for(j=0;j<n;j++)
    {
        dp[n-1][j]=triangle[n-1][j];
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            int down=triangle[i][j]+dp[i+1][j];
            int digonal=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(dodwn,digonal);
        }
    }
    return dp[0][0];
}
int main() {
	// your code goes here
// Triangle fixed starting point and variable ending point dp on grids
// recursion
// TC->O(2^1+2+3+....n) SC->O(N)
// memoization
// TC->O(N*N) SC->O(N)+O(N*N)
// tabulation
// TC->O(N*N) SC->O(N*n)
// space optimization
// TC->O(N*N) SC->O(N)
}


#include <bits/stdc++.h>
using namespace std;
int minumumpathsum(vector<vector<int>>&triangle,int n)
{
    int i;
    int j;
    vector<int>front(n,0);
    vector<int>cur(n,0);
    for(j=0;j<n;j++)
    {
        front[j]=triangle[n-1][j];
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            int down=triangle[i][j]+front[j];
            int digonal=triangle[i][j]+front[j+1];
            cur[j]=min(down,digonal);
        }
        front=cur;
    }
    return front[0];
}
int main() {
	// your code goes here
// Triangle fixed starting point and variable ending point dp on grids
// recursion
// TC->O(2^1+2+3+....n) SC->O(N)
// memoization
// TC->O(N*N) SC->O(N)+O(N*N)
// tabulation
// TC->O(N*N) SC->O(N*n)
// space optimization
// TC->O(N*N) SC->O(N)
}
