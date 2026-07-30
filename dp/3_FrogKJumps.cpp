#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr,int k)
{
    if(index==0) return 0;
    int minSteps=INT_MAX;
    int i;
    int jumps;
    for(i=1;i<k;i++)
    {
        if(index-i>=0)
        {
            jumps=f(index-i,arr,k)+abs(arr[i]-arr[index-i]);
            minSteps=min(minSteps,jumps);
        }
    }
    return minSteps;
}
int main() {
	// your code goes her
// 	Frog k jump
// recursion
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	int k=2;
	cout<<f(n-1,arr,k)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr,int k,vector<int>&dp)
{
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];
    int minSteps=INT_MAX;
    int i;
    int jumps;
    for(i=1;i<k;i++)
    {
        if(index-i>=0)
        {
            jumps=f(index-i,arr,k,dp)+abs(arr[i]-arr[index-i]);
            dp[index]=min(minSteps,jumps);
        }
    }
    return dp[index];
}
int main() {
	// your code goes her
// 	Frog k jump
// memoization
// TC->O(N*K) SC->O(N)+O(N)
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	int k=2;
	vector<int>dp(n,-1);
	cout<<f(n-1,arr,k,dp)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes her
// 	Frog k jump
// tabulation
// TC->O(N*K) SC->O(N)
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	int k=2;
	vector<int>dp(n,-1);
	int i;
	int j;
	dp[0]=0;
	int jumps;
	int minSteps;
	for(i=1;i<n;i++)
	{
	    minSteps=INT_MAX;
	    for(j=1;j<=k;j++)
	    {
	        if(i-j>=0)
	        {
	            jumps=dp[i-j]+abs(arr[i]-arr[i-j]);
	            minSteps=min(minSteps,jumps);
	        }
	    }
	    dp[i]=minSteps;
	}
	cout<<dp[n-1]<<endl;
	
}


// space optimization to SC->O(K)
