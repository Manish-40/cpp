#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int>arr={3,5,8,15,19};
// 	Binary search upper bound smallest index

int x=5;
int low=0;
int high=arr.size()-1;
int mid;
int ans=arr.size()-1;
while(low<=high)
{
    mid=low+high/2;
    if(arr[mid]>x)
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

int lb=std::upper_bound(arr.begin(), arr.end(),x)-arr.begin();
cout<<lb<<endl;
}
