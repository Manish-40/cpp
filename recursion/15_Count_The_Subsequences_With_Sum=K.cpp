#include <bits/stdc++.h>
using namespace std;
int f(int i,int n,int s, int sum, vector<int>&arr)
{
    if(i>=n)
    {
        if(s==sum)
        {
            return 1;
        }
        else return 0;
    }
    
    s=s+arr[i];
    int l=f(i+1,n,s,sum,arr);
    
    s=s-arr[i];
    int r=f(i+1,n,s,sum,arr);
    
    return l+r;
}
int main() {
	// your code goes here
	vector<int>arr{1,2,1};
	int sum=2;
	int n=arr.size();
	
	cout<<f(0,n,0,sum,arr)<<endl;
}