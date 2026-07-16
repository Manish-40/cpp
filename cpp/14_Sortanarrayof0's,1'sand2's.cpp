#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    // 	Sort an array of 0's, 1's and 2's

    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 1};
    // Brute Merge sort TC->O(NlogN) SC->O(N)

    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    // Better TC->O(2N) SC->O(1)
    int i;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count0 = count0 + 1;
        }
        else if (arr[i] == 1)
        {
            count1 = count1 + 1;
        }
        else
        {
            count2 = count2 + 1;
        }
    }
    for (i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }
    for (i = count0 + count1; i < arr.size(); i++)
    {
        arr[i] = 2;
    }

    for (i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }



vector<int>arr={0,1,2,0,1,2,1,2,0,0,0,1};
// Optimal Dutch national flag algorithm TC->O(N) SC->O(1)

// [0,.....low-1] - 0  extreme left
// [low,......mid-1] - 1 
// [high+1,......n-1] - 2 extreme right


// 0     low-1   low    mid-1   mid     high  high+1   n-1
// |       |      |       |      |        |     |       |
//  000000         111111         0/1/2          222222
//                               unsorted



// a[mid]==0   swap(a[low],a[mid]) low++,mid++
// a[mid]==1   mid++
// a[mid]==2   swap(a[mid],a[high]) high--


int n=arr.size();
int low=0;
int mid=0;
int high=n-1;
while(mid<=high)
{
    if(arr[mid]==0)
    {
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
    else if(arr[mid]==1)
    {
        mid++;
    }
    else
    {
        swap(arr[high],arr[mid]);
        high--;
    }
}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<endl;
}
}
