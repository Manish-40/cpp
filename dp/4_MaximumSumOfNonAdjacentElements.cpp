#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr)
{
    if(index==0) return 0;
    if(index<0) return 0;
    int pick=arr[index]+f(index-2,arr);
    int notPick=0+f(index-1,arr);
    return max(pick,notPick);
}
int main() {
	// your code goes her
// 	Maximum sum of nonadjacent elements
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    cout<<f(n-1,arr);
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&arr,vector<int>&dp)
{
    if(index==0) return 0;
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick=arr[index]+f(index-2,arr,dp);
    int notPick=0+f(index-1,arr,dp);
    return dp[index]=max(pick,notPick);
}
int main() {
	// your code goes her
// 	Maximum sum of nonadjacent elements
// memoization
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    vector<int>dp(n,-1);
    cout<<f(n-1,arr,dp);
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes her
// 	Maximum sum of nonadjacent elements
// tabulation
// TC->O(N) SC->O(N)
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    vector<int>dp(n,-1);
    dp[0]=0;
    int neg=0;
    int take;
    int notTake;
    int i;
    for(i=1;i<n;i++)
    {
        take=arr[i];
        if(i>1)
        {
            take+=dp[i-2];
        }
        notTake=0+dp[i-1];
        dp[i]=max(take,notTake);
    }
    cout<<dp[n-1]<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes her
// 	Maximum sum of nonadjacent elements
// space optimization
// TC->O(N) SC->O(1)
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    int prev1=arr[0];
    int prev2=0;
    int i;
    
    for(i=1;i<n;i++)
    {
        int take=arr[i];
        if(i>1)
        {
            take+=prev2;
        }
        int notTake=0+prev1;
        int curi=max(take,notTake);
        prev2=prev1;
        prev1=curi;
    }
    cout<<prev1<<endl;
}
