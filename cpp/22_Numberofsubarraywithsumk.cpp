#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Count subarray sum equals k

vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
int k=3;

// subarray contiguous hoy [1,2,3] [1,1,1]
// subsequence non-contiguous hoy [1,4,2] [1,3,4]

// ans [1,2] [1,2,3,-3] [3] [2,3,-3,1] [3,-3,1,1,1] [1,1,1] [4,2,-3] 
// [-3,1,1,1,4,2,-3] =8

// Brute TC->O(N^3) SC->O(1)
int i;
int j;
int sum;
int count=0;
for(i=0;i<arr.size();i++)
{
    for(j=i;j<arr.size();j++)
    {
        sum=0;
        for(int l=i;l<=j;l++)
        {
            sum=sum+arr[l];
        }
        if(sum==k)
        {
            count=count+1;
        }
    }
}
cout<<count<<endl;



vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
int k=3;

// subarray contiguous hoy [1,2,3] [1,1,1]
// subsequence non-contiguous hoy [1,4,2] [1,3,4]

// ans [1,2] [1,2,3,-3] [3] [2,3,-3,1] [3,-3,1,1,1] [1,1,1] [4,2,-3] 
// [-3,1,1,1,4,2,-3] =8

// Better TC->O(N^2) SC->O(1)
int i;
int j;
int sum;
int count=0;
for(i=0;i<arr.size();i++)
{
    sum=0;
    for(j=i;j<arr.size();j++)
    {
        sum=sum+arr[j];
        if(sum==k)
        {
            count=count+1;
        }
    }
}
cout<<count<<endl;





vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
int k=3;

// subarray contiguous hoy [1,2,3] [1,1,1]
// subsequence non-contiguous hoy [1,4,2] [1,3,4]

// ans [1,2] [1,2,3,-3] [3] [2,3,-3,1] [3,-3,1,1,1] [1,1,1] [4,2,-3] 
// [-3,1,1,1,4,2,-3] =8

// Optimal TC->O(N)* O(logN) SC->O(N)
// prefix sum

unordered_map<int,int>m;
m[0]=1;
int preSum=0;
int count=0;
int i;
for(i=0;i<arr.size();i++)
{
    preSum=preSum+arr[i];
    int remove=preSum-k;
    count=count+m[remove];
    m[preSum]+=1;
}
cout<<count<<endl;
}
