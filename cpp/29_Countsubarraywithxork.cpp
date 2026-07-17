#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Count number of subarray with given xor k

vector<int>arr={4,2,2,6,4};
int k=6;
// [4,2] [6] [2,2,6] [4,2,2,6,4] ans=4

// Brute TC->O(N^3) SC->O(1)
int i;
int j;
int n=arr.size();
int l;
int xorel;
int count=0;
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++)
    {
        xorel=0;
      for(l=i;l<=j;l++)
      {
          xorel=xorel^arr[l];
      }
      if(xorel==k) count=count+1;
    }
}
cout<<count<<endl;



vector<int>arr={4,2,2,6,4};
int k=6;
// [4,2] [6] [2,2,6] [4,2,2,6,4] ans=4

// Better TC->O(N^2) SC->O(1)
int i;
int j;
int n=arr.size();
int xorel;
int count=0;
for(i=0;i<n;i++)
{
    xorel=0;
    for(j=i;j<n;j++)
    {
        xorel=xorel^arr[j];
        if(xorel==k) count=count+1;
    }
}
cout<<count<<endl;


vector<int>arr={4,2,2,6,4};
int k=6;
// [4,2] [6] [2,2,6] [4,2,2,6,4] ans=4

// Optimal hashmap TC->O(N log n) SC->O(N)

// focus on ending point

// x=xr^k
// is there a subarray ending at 6 & having < xor of k

int xr=0;
map<int,int>m;
m[xr]++; //(0,1)
int count=0;
for(int i=0;i<arr.size();i++)
{
    xr=xr^arr[i];
    // k
    int x=xr^k;
    count+=m[x];
    m[xr]++;
}
cout<<count<<endl;

}
