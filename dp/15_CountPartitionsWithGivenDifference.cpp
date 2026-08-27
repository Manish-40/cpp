#include <bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int f(int index,int sum,vector<int>&num,vector<vector<int>>&dp)
{
    // 	Counts subsets with sum pick
// Number of subsets

// Memoization TC->(N*sum) SC->O(N*sum)+O(N)

// if constraints 0<=nums[i]<=1000

    if(index==0) 
    {
        if(sum==0 && num[0]==0) return 2;
        if(sum==0 || sum==num[0]) return 1;
        return 0;
    }
    if(dp[index][sum]!=-1) return dp[index][sum];

    int notpick=f(index-1,sum,num,dp);
    int pick=0;
    if(num[index]<=sum) pick=f(index-1,(sum-num[index]),num,dp);
    
    return dp[index][sum]=(notpick+pick)%mod;
}


int findWays(vector<int>&num,int target)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
	return f(n-1,target,num,dp);
}
int countPartition(int n,int d,vector<int>&arr)
{
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
    if(totsum-d<0 || (totsum-d)%2) return false;
    return findWays(arr,(totsum-d)/2);
}
int main() {
	// your code goes here
// 	Partitions with given difference
// memoization
	vector<int>num{5,2,6,4};

	int n=num.size();
	int target=3;
	
	cout<<countPartition(n,target,num)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int findWays(vector<int>&num,int target)
{
    // 	Counts subsets with sum pick
// Number of subsets

// Tabulation TC->(N*sum) SC->O(N*sum)
	int n=num.size();
	vector<vector<int>>dp(n,vector<int>(target+1,0));
	
	if (num[0]==0) dp[0][0]=2;
	else dp[0][0]=1;
	
// 	num[0]=0
	if(num[0]!=0 && num[0]<=target) dp[0][num[0]]=1;
	int index;
	int sum;
	for(index=1;index<n;index++)
	{
	    for(sum=0;sum<=target;sum++)
	    {
	        int notpick=dp[index-1][sum];
            int pick=0;
            if(num[index]<=sum) pick=dp[index-1][sum-num[index]];
            
            dp[index][sum]=(notpick+pick)%mod;
	    }
	}
	return dp[n-1][target];
}
int countPartition(int n,int d,vector<int>&arr)
{
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
    if(totsum-d<0 || (totsum-d)%2) return false;
    return findWays(arr,(totsum-d)/2);
}
int main() {
	// your code goes here
// 	Partitions with given difference
// tabulation
	vector<int>num{5,2,6,4};

	int n=num.size();
	int target=3;
	
	cout<<countPartition(n,target,num)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int findWays(vector<int>&num,int target)
{
    // 	Counts subsets with sum pick
// Number of subsets

// Tabulation TC->(N*sum) SC->O(N*sum)
	int n=num.size();
vector<int>prev(target+1,0);
vector<int>cur(target+1,0);
	
	if (num[0]==0) prev[0]=2;
	else prev[0]=1;
	
// 	num[0]=0
	if(num[0]!=0 && num[0]<=target) prev[num[0]]=1;
	int index;
	int sum;
	for(index=1;index<n;index++)
	{
	    for(sum=0;sum<=target;sum++)
	    {
	        int notpick=prev[sum];
            int pick=0;
            if(num[index]<=sum) pick=prev[sum-num[index]];
            
            cur[sum]=(notpick+pick)%mod;
	    }
	    prev=cur;
	}
	return prev[target];
}
int countPartition(int n,int d,vector<int>&arr)
{
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
    if(totsum-d<0 || (totsum-d)%2) return false;
    return findWays(arr,(totsum-d)/2);
}
int main() {
	// your code goes here
// 	Partitions with given difference
// space optimization
	vector<int>num{5,2,6,4};

	int n=num.size();
	int target=3;
	
	cout<<countPartition(n,target,num)<<endl;
}
