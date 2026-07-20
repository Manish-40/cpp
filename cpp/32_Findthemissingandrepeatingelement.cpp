#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Find the missing and repeating number

vector<int>arr={4,3,6,2,1,1};
int n=arr.size();

// Repeating number 1
// Missing number 5

// Brute TC->O(N^2) SC->O(1)

int repeating=-1;
int missing=-1;
int i;
int j;
int maxi=*std::max_element(arr.begin(), arr.end());
int count=0;
for(i=1;i<maxi;i++)
{
    count=0;
    for(j=0;j<n;j++)
    {
        if(arr[j]==i)
        {
            count=count+1;
        }
    }
    if(count==2) repeating=i;
    else if(count==0) missing=i;
    if(repeating!=-1 && missing!=-1) break;
}
cout<<repeating<<endl;
cout<<missing<<endl;





vector<int>arr={4,3,6,2,1,1};
int n=arr.size();

// Repeating number 1
// Missing number 5

// Better TC->O(2N) SC->O(N)


int hash[n+1]={0};
int i;
int repeating=-1;
int missing=-1;
for(i=0;i<n;i++)
{
    hash[arr[i]]++;
}
for(i=0;i<n;i++)
{
    if(hash[i]==2)
    {
        repeating=i;
    }
    else if(hash[i]==0 && i!=0)
    {
        missing=i;
    }
    if(repeating!=-1 && missing!=-1)
    {
        break;
    }
}
cout<<repeating<<endl;
cout<<missing<<endl;




vector<int>arr={4,3,6,2,1,1};
int n=arr.size();

// Repeating number 1
// Missing number 5

// Optimal TC->O(N) SC->O(1)
// 2 optimal maths  xor

// maths  2 equation vadu
// s - sn
// s2 - s2n

// aa n nu sum ane square nu sum che
long long SN=(n*(n+1))/2;
long long S2N=(n*(n+1)*(2*n+1))/6;
long long s=0;
long long s2=0;
int i;

// aa arr nu sum ane square nu sum che
for(i=0;i<n;i++)
{
    s+=arr[i];
    s2+=(long long)arr[i]*(long long)arr[i];
}
long long val1=s-SN;     //x-y
long long val2=s2-S2N;  
val2=val2/val1;   // x+y

long long x=(val1+val2)/2;
long long y=x-val1;
cout<<(int)x<<endl;  // x repeating
cout<<(int)y<<endl;  // y missing





vector<int>arr={4,3,6,2,1,1};
int n=arr.size();

// Repeating number 1
// Missing number 5

// Optimal TC->O(N) SC->O(1)
// 2 optimal maths  xor

// xor

// even number of same number xor give 0 
// odd number of same number xor give that number

// 2^2=0
// 1^1^1=1
// 5^5=0

// (4^3^6^2^1^1) ^ (1^2^3^4^5^6)
// 1^5=4
// x^y=4
// right ma je 001^101 = 100 aavyu e levanu to e 2 bit che 
// bitno=2

// all number are even number vakhat che
// x odd  1
// y odd  5

// bit = 2
// /  \
// 0  1
// 1  4
// 1  4
// 1  5
// 3  6
// 3  6
// 2
// 2

// ^ karyu to 
// 1  5

int i;
int xor1=0;
for(i=0;i<n;i++)
{
    xor1=xor1^arr[i];
    xor1=xor1^(i+1);
}
int bitNo=0;
while(1)
{
    if((xor1&(1<<bitNo))!=0)
    {
        break;
    }
    bitNo++;
}
int zero=0;
int one=0;
for(i=0;i<n;i++)
{
    if((arr[i]&(1<<bitNo))!=0)
    {
        one=one^arr[i];
    }
    else
    {
        zero=zero^arr[i];
    }
}
for(i=1;i<=n;i++)
{
    if((i&(1<<bitNo))!=0)
    {
        one=one^arr[i];
    }
    else
    {
        zero=zero^arr[i];
    }
}
int count=0;
for(i=0;i<n;i++)
{
    if(arr[i]==zero) count=count+1;
}
if(count==2) cout<<zero<<one<<endl;

cout<<one<<zero<<endl;
}
