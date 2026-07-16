#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int>arr={3,5,8,15,19};
// 	Binary search lower bound smallest index
// TC->O(log base 2 N)
int x=20;
int low=0;
int high=arr.size()-1;
int mid;
int ans=arr.size()-1;
while(low<=high)
{
    mid=low+high/2;
    if(arr[mid]>=x)
    {
        ans=mid;
        high--;
    }
    else 
    {
        low++;
    }
}
cout<<ans<<endl;

int lb=std::lower_bound(arr.begin(), arr.end(),x)-arr.begin();
cout<<lb<<endl;
}
