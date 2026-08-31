#include <bits/stdc++.h>
using namespace std;
bool f(int i,int n,int s, int sum, vector<int>&arr,vector<int>&array)
{
    if(i>=n)
    {
        if(s==sum)
        {
            for(auto it:array)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else return false;
    }
    
    array.push_back(arr[i]);
    s=s+arr[i];
    if(f(i+1,n,s,sum,arr,array)==true)
    {
        return true;
    }
    
    array.pop_back();
    s=s-arr[i];
    if(f(i+1,n,s,sum,arr,array)==true)
    {
        return true;
    }
    
    return false;
}
int main() {
	// your code goes here
	vector<int>arr{1,2,1};
	int sum=2;
	int n=arr.size();
	
	vector<int>array;
	f(0,n,0,sum,arr,array);
}