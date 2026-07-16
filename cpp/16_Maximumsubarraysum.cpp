#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Kadanes algorithm Maximum subarray sum contiguos part of the array

vector<int>arr={-2,-3,4,-1,-2,1,5,-3};   //contigous 4,-1,-2,1,5  
                                         //subsequence -2,-3,4,1,5
int ans=7;
// Brute TC->O(N^3) SC->O(1)

int i;
int j;
int sum=0;
int maxi=INT_MIN;
for(i=0;i<arr.size();i++)
{
    for(j=i;j<arr.size();j++)
    {
        sum=0;
        for(int l=i;l<j;l++)
        {
            sum=sum+arr[l];
        }
        maxi=max(maxi,sum);
    }
}
cout<<maxi<<endl;





vector<int>arr={-2,-3,4,-1,-2,1,5,-3};   //contigous 4,-1,-2,1,5  
                                         //subsequence -2,-3,4,1,5
int ans=7;
// Better TC->O(N^2) SC->O(1)

int i;
int j;
int sum=0;
int maxi=INT_MIN;
for(i=0;i<arr.size();i++)
{
    sum=0;
    for(j=i;j<arr.size();j++)
    {
        sum=sum+arr[j];
        maxi=max(maxi,sum);
    }
}
cout<<maxi<<endl;



vector<int>arr={-2,-3,4,-1,-2,1,5,-3};   //contigous 4,-1,-2,1,5  
                                         //subsequence -2,-3,4,1,5
// int ans=7;
// Optimal Kadanes algorithm TC->O(N) SC->O(1)

int i;
int sum=0;
int maxi=INT_MIN;
int start;
int ansStart=-1;
int startEnd=-1;
for(i=0;i<arr.size();i++)
{
    if(sum==0) start=i;
    sum=sum+arr[i];
    if(sum>maxi)
    {
        maxi=sum;
        ansStart=start;
        startEnd=i;
    }
    if(sum<0)
    {
        sum=0;
    }
}
if(maxi<0)
{
    cout<<0<<endl;
}
cout<<maxi<<endl;
cout<<ansStart<<endl;
cout<<startEnd<<endl;
}
