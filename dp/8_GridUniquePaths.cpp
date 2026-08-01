#include <bits/stdc++.h>
using namespace std;
int f(int i,int j)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up=f(i-1,j);
    int left=f(i,j-1);
    return up+left;
}
int uniquepaths(int m,int n)
{
    return f(m-1,n-1);
}
int main() {
	// your code goes here
// 	Dp on greeds 2d matrix
// Total unique paths
// recursion top down
// TC->O(2^M*N)
// SC->O(path length)(m-1)(n-1)
// (0,0)->(0,1)->(0,2)->(0,3)
//                        |
//                      (1,3)
//                        |
//                      (2,3)
//                        |
//                      (3,3)
// count | and -> path length = 6

// 	Dp on greeds 2d matrix
// count pairs
// count paths with obstacles
// min path sum
// max path sum
// triangle
// 2 start points
}

#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j]=up+left;
}
int uniquepaths(int m,int n)
{
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}
int main() {
	// your code goes here
// 	Dp on greeds 2d matrix
// Total unique paths

// dp memoization recursion ma overlaping subproblems hoy tyare kariye memoization
// TC->O(N*M) SC->O((N-1)+(M-1))recursion stack space +O(M*N)Dp

}


#include <bits/stdc++.h>
using namespace std;
int uniquepaths(int m,int n)
{
    int dp[m][n];
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else
            {
                int up=0;
                int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}
int main() {
	// your code goes here
// 	Dp on greeds 2d matrix
// Total unique paths

// tabulation bottom up
// TC->O(N*M) SC->O(N*M)
}


#include <bits/stdc++.h>
using namespace std;
int uniquepaths(int m,int n)
{
    vector<int>prev(n,0);
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        vector<int>cur(n,0);
        for(j=0;j<n;j++)
        {
            if(i==0 && j==0) cur[j]=1;
            else
            {
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=cur[j-1];
                cur[j]=up+left;
            }
        }
        prev=cur;
    }
    return prev[n-1];
}
int main() {
	// your code goes here
// 	Dp on greeds 2d matrix
// Total unique paths

// space optimization
// TC->O(N*M) SC->O(N)+O(N)
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
// 	Dp on greeds 2d matrix
// Total unique paths
}


