#include <bits/stdc++.h>
using namespace std;
void f(int i,int n,vector<int>&arr,vector<int>&array)
{
    if(i>=n)
    {
        for(auto it:array)
        {
            cout<<it<<" ";
        }
        if(array.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    
    array.push_back(arr[i]);
    
    f(i+1,n,arr,array);
    
    array.pop_back();
    
    f(i+1,n,arr,array);
}
int main() {
	// your code goes here
	vector<int>arr{3,1,2};
	int n=arr.size();
	
	vector<int>array;
	f(0,n,arr,array);
}