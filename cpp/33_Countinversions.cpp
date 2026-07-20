#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Count inversions

vector<int>arr={5,3,2,4,1};
// i<j & arr[i] > arr[j]

// (5,3) (5,2) (5,4) (5,1)
// (3,2) (3,1)
// (2,1)
// (4,1)
// ans=8
// Brute TC->O(N^2) SC->O(1)

int i;
int j;
int count=0;
for(i=0;i<arr.size();i++)
{
    for(j=i+1;j<arr.size();j++)
    {
        if(arr[i]>arr[j])
        {
            count=count+1;
        }
    }
}
cout<<count<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int merge(int arr[],int low,int mid,int high)
{
    vector<int>ans;
    int left=low;
    int right=mid+1;
    int count=0;
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
            count=count+(mid-left+1);
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
    return count;
}
int mergesort(int arr[],int low,int high)
{
    int count=0;
    if(low>=high) return count;
    int mid=(low+high)/2;
    count=count+mergesort(arr,low,mid);
    count=count+mergesort(arr,mid+1,high);
    count=count+merge(arr,low,mid,high);
    return count;
}
int main() {
	// your code goes here
// 	Count inversions

int arr[]={5,3,2,4,1};
// i<j & arr[i] > arr[j]

// (5,3) (5,2) (5,4) (5,1)
// (3,2) (3,1)
// (2,1)
// (4,1)
// ans=8
// Optimal TC->O(NlogN) SC->O(N)
// Merge sort
//                    1 2 3 4 5
//                   [5,3,2,4,1]
//                 2,3,5/  \ 1 4
//               [5,3,2]    [4,1]
//           3 5  /  \       /  \
//           [5,3]    [2]  [4]   [1]
//            /  \
//          [5]  [3]  5>3 count=1    3,5  3>2count=1  5>2 count=2 count=1+2

cout<<mergesort(arr,0,5-1)<<endl;;

}

