#include <bits/stdc++.h>
using namespace std;
int f(int index,int weight,vector<int>&wt,vector<int>&val)
{
    if(index==0)
    {
        if(wt[0]<=weight) return val[0];
        return 0;
    }
    
    int nottake=0+f(index-1,weight,wt,val);
    int take=INT_MIN;
    if(wt[index]<=weight)
    {
        take=val[index]+f(index-1,weight-wt[index],wt,val);
    }
    return max(take,nottake);
}
int main() {
	// your code goes here
// 	0/1 Knapsack

// recursion TC->O(2^N) SC->O(N)
vector<int>wt{3,2,5};
vector<int>val{30,40,60};
int maxWeightofBag=6;
int n=val.size();
cout<<f(n-1,maxWeightofBag,wt,val)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int index,int weight,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(wt[0]<=weight) return val[0];
        return 0;
    }
    
    if(dp[index][weight]!=-1) return dp[index][weight];
    
    int nottake=0+f(index-1,weight,wt,val,dp);
    int take=INT_MIN;
    if(wt[index]<=weight)
    {
        take=val[index]+f(index-1,weight-wt[index],wt,val,dp);
    }
    return dp[index][weight]=max(take,nottake);
}
int main() {
	// your code goes here
// 	0/1 Knapsack

// memoization TC->O(N*weight) SC->O(N*weight)+O(N)
vector<int>wt{3,2,5};
vector<int>val{30,40,60};
int maxWeightofBag=6;
int n=val.size();
vector<vector<int>>dp(n,vector<int>(maxWeightofBag+1,-1));
cout<<f(n-1,maxWeightofBag,wt,val,dp)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// 	0/1 Knapsack

// tabulation TC->O(N*weight) SC->O(N*weight)
vector<int>wt{3,2,5};
vector<int>val{30,40,60};
int maxWeightofBag=6;
int n=val.size();

vector<vector<int>>dp(n,vector<int>(maxWeightofBag+1,0));

int i;
for(i=wt[0];i<=maxWeightofBag;i++) dp[0][i]=val[0];

int index;
for(index=1;index<n;index++)
{
    for(i=0;i<=maxWeightofBag;i++)
    {
        int nottake=0+dp[index-1][i];
        int take=INT_MIN;
        if(wt[index]<=i)
        {
            take=val[index]+dp[index-1][i-wt[index]];
        }
        dp[index][i]=max(take,nottake);
    }
}
cout<<dp[n-1][maxWeightofBag]<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// 	0/1 Knapsack

// space optimization
vector<int>wt{3,2,5};
vector<int>val{30,40,60};
int maxWeightofBag=6;
int n=val.size();

vector<int>prev(maxWeightofBag+1,0);
vector<int>cur(maxWeightofBag+1,0);

int i;
for(i=wt[0];i<=maxWeightofBag;i++) prev[i]=val[0];

int index;
for(index=1;index<n;index++)
{
    for(i=0;i<=maxWeightofBag;i++)
    {
        int nottake=0+prev[i];
        int take=INT_MIN;
        if(wt[index]<=i)
        {
            take=val[index]+prev[i-wt[index]];
        }
        cur[i]=max(take,nottake);
    }
    prev=cur;
}
cout<<prev[maxWeightofBag]<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// 	0/1 Knapsack

// space optimization
vector<int>wt{3,2,5};
vector<int>val{30,40,60};
int maxWeightofBag=6;
int n=val.size();

vector<int>prev(maxWeightofBag+1,0);

int i;
for(i=wt[0];i<=maxWeightofBag;i++) prev[i]=val[0];

int index;
for(index=1;index<n;index++)
{
    for(i=maxWeightofBag;i>=0;i--)
    {
        int nottake=0+prev[i];
        int take=INT_MIN;
        if(wt[index]<=i)
        {
            take=val[index]+prev[i-wt[index]];
        }
        prev[i]=max(take,nottake);
    }
}
cout<<prev[maxWeightofBag]<<endl;
}
