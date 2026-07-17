#include <bits/stdc++.h>
using namespace std;
int f(vector<int>&arr,int mid)
{
    int hour=0;
    int i;
    for(i=0;i<arr.size();i++)
    {
       hour = hour + (arr[i] + mid - 1) / mid;
    }
    return hour;
}
int main() {
	// your code goes here
	vector<int>arr={3,6,7,11};
	int h=8;
	int low=1;
	int high=*std::max_element(arr.begin(), arr.end());
	int mid;
	int ans=INT_MAX;
	while(low<=high)
	{
	    mid=low+(high-low)/2;
	    int totalhour=f(arr,mid);
	    if(totalhour<=h)
	    {
	        ans=mid;
	        high=mid-1;
	    }
	    else
	    {
	        low=mid+1;
	    }
	}
	cout<<ans<<endl;
}
