#include <bits/stdc++.h>
using namespace std;
bool f(int index,int target,vector<int>&arr)
{
    if(target==0) return true;
    if(index==0) return (arr[index]==target);
    
    bool nottake=f(index-1,target,arr);
    bool take=false;
    
    if(target>=arr[index])
    {
        take=f(index-1,target-arr[index],arr);
    }
    
    return (take)|(nottake);
}
int main() {
    // your code goes here
// DP on subsequences
// recursion TC->O(2^N) SC->O(N)
vector<int>arr{2,3,1,1};
int target=4;
cout<<f(arr.size()-1,target,arr)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
bool f(int index,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(index==0) return (arr[index]==target);
    
    if(dp[index][target]!=-1) return dp[index][target];
    bool nottake=f(index-1,target,arr,dp);
    bool take=false;
    
    if(target>=arr[index])
    {
        take=f(index-1,target-arr[index],arr,dp);
    }
    
    return dp[index][target]=(take)|(nottake);
}
int main() {
    // your code goes here
// DP on subsequences
// memoization TC->O(n*target) SC->O(n*target)+O(n)
vector<int>arr{2,3,1,1};
int target=4;
int n=arr.size();
vector<vector<int>>dp(n,vector<int>(target+1,-1));
cout<<f(n-1,target,arr,dp)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
// DP on subsequences
// tabulation TC->O(n*target) SC->O(n*target)
vector<int>arr{2,3,1,1};
int target=4;
int n=arr.size();
vector<vector<bool>>dp(n,vector<bool>(target+1,-1));
int i;
for(i=0;i<n;i++)
{
    dp[i][0]=true;
}
dp[0][arr[0]]=true;
int index;
int j;
for(index=1;index<n;index++)
{
    for(j=1;j<=target;j++)
    {
        bool nottake=dp[index-1][target];
        bool take=false;
    
        if(target>=arr[index])
        {
            take=dp[index-1][target-arr[index]];
        }
        dp[index][target]=(take)|(nottake);
    }
}
cout<<dp[n-1][target]<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
// DP on subsequences
// space tabulation TC->O(n*target) SC->O(target)
vector<int>arr{2,3,1,1};
int target=4;
int n=arr.size();

vector<bool>prev(target+1,0);
vector<bool>cur(target+1,0);
prev[0]=cur[0]=true;

prev[arr[0]]=true;

int index;
int j;
for(index=1;index<n;index++)
{
    for(j=1;j<=target;j++)
    {
        bool nottake=prev[target];
        bool take=false;
    
        if(target>=arr[index])
        {
            take=prev[target-arr[index]];
        }
        cur[target]=(take)|(nottake);
    }
    prev=cur;
}
cout<<prev[target]<<endl;
}
