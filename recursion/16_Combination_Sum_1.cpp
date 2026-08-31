#include <bits/stdc++.h>
using namespace std;
void f(int i,int n,int target, vector<int>&arr, vector<int>&array, vector<vector<int>>&ans)
{
    if(i>=n)
    {
        if(target==0)
        {
            ans.push_back(array);
        }
        return;
    }
    
    if(arr[i]<=target)
    {
        array.push_back(arr[i]);
        f(i,n,target-arr[i],arr,array,ans);
        array.pop_back();
    }
    
    f(i+1,n,target,arr,array,ans);
}
int main() {
	// your code goes here
	vector<int>arr{2,3,6,7};
	int target=7;
	int n=arr.size();
	
	vector<int>array;
	vector<vector<int>>ans;
	f(0,n,target,arr,array,ans);
	
	int i;
	int j;
	for(i=0;i<ans.size();i++)
	{
	    for(j=0;j<ans[i].size();j++)
	    {
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
}