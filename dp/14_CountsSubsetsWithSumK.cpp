#include <bits/stdc++.h>
using namespace std;
int f(int index,int sum,vector<int>&num)
{
    if(sum==0) return 1;
    if(index==0) return(num[index]==sum);
    
    int notpick=f(index-1,sum,num);
    int pick=0;
    if(num[index]<=sum) pick=f(index-1,(sum-num[index]),num);
    
    return (notpick+pick);
}
int main() {
	// your code goes here
// 	Counts subsets with sum pick
// Number of subsets

// recursion TC->(2^N) SC->O(N)
	vector<int>num{1,3,2};
	int n=num.size();
	int target=3;
	cout<<f(n-1,target,num)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,int sum,vector<int>&num,vector<vector<int>>&dp)
{
    if(sum==0) return 1;
    if(index==0) return(num[index]==sum);
    if(dp[index][sum]!=-1) return dp[index][sum];

    int notpick=f(index-1,sum,num,dp);
    int pick=0;
    if(num[index]<=sum) pick=f(index-1,(sum-num[index]),num,dp);
    
    return dp[index][sum]=(notpick+pick);
}
int main() {
	// your code goes here
// 	Counts subsets with sum pick
// Number of subsets

// Memoization TC->(N*sum) SC->O(N*sum)+O(N)
	vector<int>num{1,3,2};

	int n=num.size();
	int target=3;

	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	cout<<f(n-1,target,num,dp)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// 	Counts subsets with sum pick
// Number of subsets

// Tabulation TC->(N*sum) SC->O(N*sum)
	vector<int>num{1,3,2};
	int n=num.size();
	int target=3;
	vector<vector<int>>dp(n,vector<int>(target+1,0));
	
	int i;
	for(i=0;i<n;i++) dp[i][0]=1;
	
	if(num[0]<=target) dp[0][num[0]]=1;
	
	int index;
	int sum;
	for(index=1;index<n;index++)
	{
	    for(sum=0;sum<=target;sum++)
	    {
	        int notpick=dp[index-1][sum];
            int pick=0;
            if(num[index]<=sum) pick=dp[index-1][sum-num[index]];
            
            dp[index][sum]=notpick+pick;
	    }
	}
	cout<<dp[n-1][target]<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// 	Counts subsets with sum pick
// Number of subsets

// space optimization TC->(N*sum) SC->O(N*N)
	vector<int>num{1,3,2};
	int n=num.size();
	int target=3;
	
	vector<int>prev(target+1);
	vector<int>cur(target+1);
	
	int i;
	prev[0]=cur[0]=1;
	
	if(num[0]<=target) prev[num[0]]=1;
	
	int index;
	int sum;
	for(index=1;index<n;index++)
	{
	    for(sum=0;sum<=target;sum++)
	    {
	        int notpick=prev[sum];
            int pick=0;
            if(num[index]<=sum) pick=prev[sum-num[index]];
            
            cur[sum]=notpick+pick;
	    }
	    prev=cur;
	}
	cout<<prev[target]<<endl;
}

