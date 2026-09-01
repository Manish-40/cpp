#include <bits/stdc++.h>
using namespace std;
void f(int i,int n,int target, vector<int>&arr, vector<int>&array, set<vector<int>>&ans)
{
    if(i>=n)
    {
        if(target==0)
        {
            ans.insert(array);
        }
        return;
    }
    
    if(arr[i]<=target)
    {
        array.push_back(arr[i]);
        f(i+1,n,target-arr[i],arr,array,ans);
        array.pop_back();
    }
    
    f(i+1,n,target,arr,array,ans);
}
int main() {
	// your code goes here
// 	Brute Force TC->O(2^N)*O(K*logN) SC->O(K*X)
	vector<int>arr{1,1,1,2,2};
	int target=4;
	int n=arr.size();
	
	vector<int>array;
	set<vector<int>>ans;
	f(0,n,target,arr,array,ans);
	
	vector<vector<int>>ansArr(ans.begin(),ans.end());
	int i;
	int j;
	for(i=0;i<ansArr.size();i++)
	{
	    for(j=0;j<ansArr[i].size();j++)
	    {
	        cout<<ansArr[i][j]<<" ";
	    }
	    cout<<endl;
	}
}


#include <bits/stdc++.h>
using namespace std;
void f(int index,int target, vector<int>&arr, vector<vector<int>>&ans,
vector<int>&ds)
{
    int n=arr.size();
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }
    
    int i;
    for(i=index;i<n;i++)
    {
        if(i>index && arr[i]==arr[i-1]) continue;
        
        if(arr[i]>target) break;
        
        ds.push_back(arr[i]);
        f(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
        
    }
    
}
int main() {
	// your code goes here
vector<int>arr{1,1,1,2,2};
int n=arr.size();

int target=4;

sort(arr.begin(),arr.end());

vector<vector<int>>ans;
vector<int>ds;

f(0,target,arr,ans,ds);

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