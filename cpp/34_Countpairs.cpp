#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Reverse pairs

vector<int>arr={40,25,19,12,9,6,2};
// i<j && arr[i]>2*arr[j]

// (6,2) (9,2) (12,2) (19,2) (25,2) (40,2)
// ans=15

// Brute TC->O(N^2) SC->O(1)

int i;
int j;
int count=0;
for(i=0;i<arr.size();i++)
{
    for(j=i+1;j<arr.size();j++)
    {
        if(arr[i]>2*arr[j])
        {
            count=count+1;
        }
    }
}
cout<<count<<endl;

}




#include <bits/stdc++.h>
using namespace std;
int countpairs(int arr[],int low,int mid,int high)
{
    int i;
    int count=0;
    int right=mid+1;
    for(i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>2*(arr[right]))
        {
            right++;
        }
        count=count+right-(mid+1);
    }
    return count;
}
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
int mergesort(int arr[],int low,int high)
{
    int count=0;
    if(low>=high) return 0;
    int mid=(low+high)/2;
    count+=mergesort(arr,low,mid);
    count+=mergesort(arr,mid+1,high);
    count+=countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return count;
}
int main() {
	// your code goes here
// 	Reverse pairs

int arr[]={40,25,19,12,9,6,2};
int n=7;
// i<j && arr[i]>2*arr[j]

// (6,2) (9,2) (12,2) (19,2) (25,2) (40,2)
// ans=15

// Optimal TC->O(2NlogN) SC->O(N)

// sorted arrays
// [6,13,21,25]         [1,2,3,4,4,5,9,11,13]

// left array ma thi 1 lesu compare karsu right array na element thi

//                            [40,25,19,12,9,6,2]
//                                  /     \
//                         [40,25,19,12]  [9,6,2]
//                            / \            /  \
//                      [40,25]  [19,12]  [9,6] [2]
//                        /  \     /   \   /  \
//                     [40][25]  [19][12] [9]  [6]
//                   40>2*25 no  19>2*12 no
//      [25,40]  [12,19]
// 25>2*12 yes count=1  25>2*19 no
// 40>2*12 yes count=1+1  40>2*19 yes count=2+1=3

// [6,9]   [2]
// 6>2*2 yes count=4
// 9>2*2 yes count=5

// [12,19,25,40]    [2,6,9]
// 12>2*2 yes count=6  12>2*6 no
// 19>2*2 yes count=7  19>2*6 yes count=8  19>2*9 yes count=9 
// 25>2*2 yes count=10 25>2*6 yes count=11  25>2*9 yes count=12
// 40>2*2 yes count=13 40>2*6 yes count=14 40>2*9 yes count=15
// ans=15

cout<<mergesort(arr,0,n-1)<<endl;

}
