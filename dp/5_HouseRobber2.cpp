#include <bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSum(vector<int>&arr)
{
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
    return prev1;
}
int houseRobber(vector<int>&valueInHouse)
{
    vector<int>temp1;
    vector<int>temp2;
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}
int main() {
	// your code goes here
	vector<int>arr={2,3,2};
    cout<<houseRobber(arr)<<endl;;

}
