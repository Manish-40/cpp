#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
    vector<int>ans;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
         ans.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=ans[i-low];
    }
}
void mergesort(int arr[],int low,int high)
{
    if(low==high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main() {
	// your code goes here
	int arr[]={3,2,4,1,3};
	mergesort(arr,0,4);
	int i;
	for(i=0;i<5;i++)
	{
	    cout<<arr[i]<<endl;
	}

}
