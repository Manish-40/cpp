#include <bits/stdc++.h>
using namespace std;
int f(int index,int target,vector<int>&num)
{
    if(index==0)
    {
        if(target%num[0]==0) return target/num[0];
        return 1e9;
    }
    
    int nottake=0+f(index-1,target,num);
    int take=INT_MAX;
    if(num[index]<=target) take=1+f(index,target-num[index],num);
    
    return min(take,nottake);
}
int main() {
	// your code goes here
// Minimum coins

// recursion TC-> greater than O(2^N) SC->O(N) more than that che

vector<int>num{1,2,3};
int target=7;
int n=num.size();

int ans=f(n-1,target,num);

if(ans>=1e9) cout<<-1<<endl;
else cout<<ans<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,int target,vector<int>&num,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(target%num[0]==0) return target/num[0];
        return 1e9;
    }
    
    if(dp[index][target]!=-1) return dp[index][target];
    
    int nottake=0+f(index-1,target,num,dp);
    int take=INT_MAX;
    if(num[index]<=target) take=1+f(index,target-num[index],num,dp);
    
    return dp[index][target]=min(take,nottake);
}
int main() {
	// your code goes here
// Minimum coins

// memoization TC->O(N*target) SC->O(N*target)+O(N)

vector<int>num{1,2,3};
int target=7;
int n=num.size();
vector<vector<int>>dp(n,vector<int>(target+1,-1));

int ans=f(n-1,target,num,dp);

if(ans>=1e9) cout<<-1<<endl;
else cout<<ans<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// Minimum coins

// tabulation TC->O(N*target) SC->O(N*target)

vector<int>num{1,2,3};
int target=7;
int n=num.size();
vector<vector<int>>dp(n,vector<int>(target+1,0));

int i;
for(i=0;i<=target;i++)
{
    if(i%num[0]==0)
    {
        dp[0][i]=i/num[0];
    }
    else
    {
        dp[0][i]=1e9;
    }
}

int index;
for(index=1;index<n;index++)
{
    for(i=0;i<=target;i++)
    {
        int nottake=0+dp[index-1][i];
        int take=INT_MAX;
        if(num[index]<=i) take=1+dp[index][i-num[index]];
        
        dp[index][i]=min(take,nottake);
    }
}

int ans=dp[n-1][target];

if(ans>=1e9) cout<<-1<<endl;
else cout<<ans<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// Minimum coins

// space optimization

vector<int>num{1,2,3};
int target=7;
int n=num.size();

vector<int>prev(target+1,0);
vector<int>cur(target+1,0);

int i;
for(i=0;i<=target;i++)
{
    if(i%num[0]==0)
    {
        prev[i]=i/num[0];
    }
    else
    {
        prev[i]=1e9;
    }
}

int index;
for(index=1;index<n;index++)
{
    for(i=0;i<=target;i++)
    {
        int nottake=0+prev[i];
        int take=INT_MAX;
        if(num[index]<=i)
        {
            take=1+cur[i-num[index]];
        }
        
        cur[i]=min(take,nottake);
    }
    prev=cur;
}

int ans=prev[target];

if(ans>=1e9) cout<<-1<<endl;
else cout<<ans<<endl;
}
