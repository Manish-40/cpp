#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Merge 2 sorted arrays without extra space

vector<int>arr1={1,3,5,7};
vector<int>arr2={0,2,6,8,9};
// [0,1,2,3,5,6,7,8,9]

// Brute TC->O(N+M)+O(N+M) SC->O(N+M)
int n=arr1.size();
int m=arr2.size();
long long arr3[n+m];
int left=0;
int right=0;
int index=0;
while(left<n && right<m)
{
    if(arr1[left]<=arr2[right])
    {
        arr3[index]=arr1[left];
        left++;
        index++;
    }
    else
    {
        arr3[index]=arr2[right];
        right++;
        index++;
    }
}
while(left<n)
{
    arr3[index]=arr1[left];
    index++;
    left++;
}
while(right<m)
{
    arr3[index]=arr2[right];
    index++;
    right++;
}

int i;
for(i=0;i<n+m;i++)
{
    if(i<n) arr1[i]=arr3[i];
    else arr2[i-n]=arr3[i];
}
for(auto it:arr1)
{
    cout<<it<<endl;
}
for(auto it:arr2)
{
    cout<<it<<endl;
}





vector<int>arr1={1,3,5,7};
vector<int>arr2={0,2,6,8,9};
// [0,1,2,3,5,6,7,8,9]

// Optimal TC->O(min(n,m))+O(NlogN)+O(MlogM) SC->O(1)
int n=arr1.size();
int m=arr2.size();
int left=n-1;
int right=0;
while(left>=0 && right<m)
{
    if(arr1[left]>arr2[right])
    {
        swap(arr1[left],arr2[right]);
        left--;
        right++;
    }
    else
    {
        break;
    }
}
sort(arr1.begin(),arr1.end());
sort(arr2.begin(),arr2.end());
for(auto it:arr1)
{
    cout<<it<<endl;
}
for(auto it:arr2)
{
    cout<<it<<endl;
}




vector<int>arr1={1,3,5,7};
vector<int>arr2={0,2,6,8,9};
// [0,1,2,3,5,6,7,8,9]

// Optimal TC->Olog base * (n+m)+O(NlogN)+O(MlogM) SC->O(1)

// gap method = sell sort

int n=arr1.size();
int m=arr2.size();

// n+m/2 = 4.5 ceil(4.5)=5 gap=5
// left=0;
// right=5 place right ma aetle 2 par

// if gap = 1 2 var aave to stop

int len=n+m;
//  int ma 4   + odd che to 1 = 5
int gap=(len/2)+(len%2);

while(gap>0)
{
    int left=0;
    int right=left+gap;
    while(right<len)
    {
        // arr1 and arr2
        if(left<n && right>=n)
        {
            swapIfGreater(arr1,arr2,left,right-n);
        }
        // arr2 and arr2
        else if(left>=n)
        {
            swapIfGreater(arr1,arr2,left-n,right-n);
        }
        // arr1 and arr1
        else
        {
            swapIfGreater(arr1,arr2,left,right);
        }
        left++;
        right++;
    }
    if(gap==1) break;
    gap=(gap/2)+(gap%2);
}
for(auto it:arr1)
{
    cout<<it<<endl;
}
for(auto it:arr2)
{
    cout<<it<<endl;
}
}
