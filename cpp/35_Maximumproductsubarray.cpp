#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Maximum product subarray

vector<int>arr={2,3,-2,4};
int n=arr.size();
// ans=6

// Brute TC->O(N^3) SC->O(1)

int i;
int j;
int l;
int maxi=INT_MIN;
int product=1;
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++)
    {
        product=1;
        for(l=i;l<=j;l++)
        {
        product=product*arr[l];
        }
        maxi=max(maxi,product);
    }
}
cout<<maxi<<endl;




vector<int>arr={2,3,-2,4};
int n=arr.size();
// ans=6

// Better TC->O(N^2) SC->O(1)

int i;
int j;
int maxi=INT_MIN;
int product=1;
for(i=0;i<n;i++)
{
    product=1;
    for(j=i;j<n;j++)
    {
        product=product*arr[j];
        maxi=max(maxi,product);
    }
}
cout<<maxi<<endl;




vector<int>arr={2,3,-2,4};
int n=arr.size();
// ans=6

// Optimal TC->O(N) SC->O(1)

// 2 Optimal observation  kadanes

// Observation

// 1 all +ve=ans +ve
// 2 even negative =ans +ve
// 3 odd negative=1 -ve remove karsu ans +ve
// 4 if has zeros

int prefix=1;
int suffix=1;
int i;
int maxi=INT_MIN;
for(i=0;i<n;i++)
{
    if(prefix==0) prefix=1;
    if(suffix==0) suffix=1;
    
    prefix=prefix*arr[i];
    suffix=suffix*arr[n-i-1];
    
    maxi=max(maxi,max(prefix,suffix));
}
cout<<maxi<<endl;
}
