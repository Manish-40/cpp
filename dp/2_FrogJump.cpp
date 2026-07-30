#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr)
{
    if(index==0) return 0;
    int left=f(index-1,arr)+abs(arr[index]-arr[index-1]);
    int right=INT_MAX;
    if(index>1)
    {
        right=f(index-2,arr)+abs(arr[index]-arr[index-2]);
    }
    return min(left,right);
}
int main() {
	// your code goes her
// 	Frog jump
// recursion
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	cout<<f(n-1,arr)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr,vector<int>&dp)
{
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];
    int left=f(index-1,arr,dp)+abs(arr[index]-arr[index-1]);
    int right=INT_MAX;
    if(index>1)
    {
        right=f(index-2,arr,dp)+abs(arr[index]-arr[index-2]);
    }
    return dp[index]=min(left,right);
}
int main() {
	// your code goes her
// 	Frog jump
// memoization
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	vector<int>dp(n,-1);
	cout<<f(n-1,arr,dp)<<endl;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes her
// 	Frog jump
// tabulation optimization
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	vector<int>dp(n,-1);
	dp[0]=0;
	int i;
	for(i=1;i<n;i++)
	{
	    int left=dp[i-1]+abs(arr[i]-arr[i-1]);
	    int right=INT_MAX;
	    if(i>1)
	    {
	        right=dp[i-2]+abs(arr[i]-arr[i-2]);
	    }
	    dp[i]=min(left,right);
	}
	cout<<dp[n-1]<<endl;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes her
// 	Frog jump
// space optimization 
// TC->O(N) SC->O(1)
	vector<int>arr={10,20,30,10};
	int n=arr.size();
	int prev1=0;
	int prev2=0;
	int curi;
	int i;
	for(i=1;i<n;i++)
	{
	    int left=prev1+abs(arr[i]-arr[i-1]);
	    int right=INT_MAX;
	    if(i>1)
	    {
	        right=prev2+abs(arr[i]-arr[i-2]);
	    }
	    curi=min(left,right);
	    prev2=prev1;
	    prev1=curi;
	}
	cout<<prev1<<endl;
}
