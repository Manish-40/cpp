#include <bits/stdc++.h>
using namespace std;
int f(int i,int j, vector<vector<int>>&grid)
{
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    int up=grid[i][j]+f(i-1,j,grid);
    int left=grid[i][j]+f(i,j-1,grid);
    return min(left,up);
}
int minSumPath(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    return f(n-1,m-1,grid);
}
int main() {
	// your code goes her
// Minimum path sum in grid
// TC->O(N*M) SC->O(path length m-1 n-1)
//                       0      1     2
//                   0   5      9     6
//                   1   11     5     2
// allowed only 2 direction   
// right and bottom
// pochvanu che (0,0) thi (1,2)
//    5->11->5->2 sum=23
//    5->9->5->2 sum=21 min

// why not follow greedy?

//                10  8  2
//                10  5  100
//                1   1  2

// greedy hame sa less path ne follow karse jemke 10->8->2->100->2
// pan aama 100 add thayu bahu mptu path che
// min che 10->10->1->1->2

// recursion
// 1 compare (i,j)
// explore all paths
// take the min path

}


#include <bits/stdc++.h>
using namespace std;
int f(int i,int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);
    return dp[i][j]=min(left,up);
}
int minSumPath(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}
int main() {
	// your code goes her
// 	memoization
// TC->O(N*M) SC->O(N*M)+O(path length m-1 n-1)
}


#include <bits/stdc++.h>
using namespace std;
int minSumPath(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else
            {
                int up=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9; // aa if(i<0) return 1e9 e che
                
                int left=grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left+=1e9; // aa if(i<0) return 1e9 e che
                
                dp[i][j]=min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}
int main() {
	// your code goes her
// 	tabulation
}


#include <bits/stdc++.h>
using namespace std;
int minSumPath(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    int i;
    int j;
    vector<int>prev(m,0);
    for(i=0;i<n;i++)
    {
        // i==n
        vector<int>cur(m,0);
        for(j=0;j<m;j++)
        {
            if(i==0 && j==0) cur[j]=grid[i][j];
            else
            {
                int up=grid[i][j];
                // requiring previous row's j column
                if(i>0) up+=prev[j];
                else up+=1e9; // aa if(i<0) return 1e9 e che
                
                int left=grid[i][j];
                // requiring row's j-1 column
                if(j>0) left+=cur[j-1];
                else left+=1e9; // aa if(i<0) return 1e9 e che
                
                cur[j]=min(left,up);
            }
        }
        prev=cur;
    }
    return prev[m-1];
}
int main() {
	// your code goes her
// 	space optimization
}

