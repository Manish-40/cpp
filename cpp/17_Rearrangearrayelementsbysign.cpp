#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Rearrange array elements by sign

vector<int>arr={3,1,-2,-5,2,-4};
// reaarange arr[3,-1,1,-5,2,-4]

int n=arr.size();
// n ----- n/2 +ve, n/2 -ve che
// n be even number

// Brute TC->O(N)+O(N/2) SC->O(N)

vector<int>pos;
vector<int>neg;

int i;
for(i=0;i<n;i++)
{
    if(arr[i]>0)
    {
        pos.push_back(arr[i]);
    }
    else
    {
        neg.push_back(arr[i]);
    }
}
for(i=0;i<n/2;i++)
{
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
}
for(i=0;i<n;i++)
{
    cout<<arr[i]<<endl;
}




vector<int>arr={3,1,-2,-5,2,-4};
// reaarange arr[3,-1,1,-5,2,-4]

int n=arr.size();

// Optimal TC->O(N) SC->O(N)
// varieties 1
vector<int>ans(n,0);
int i;
int pos=0;
int neg=1;
for(i=0;i<n;i++)
{
    if(arr[i]<0)
    {
        ans[neg]=arr[i];
        neg=neg+2;
    }
    else
    {
        ans[pos]=arr[i];
        pos=pos+2;
    }
}
for(i=0;i<n;i++)
{
    cout<<ans[i]<<endl;
}




vector<int>arr={1,2,-4,-5,3,6};
// reaarange arr[1,-4,2,-5,3,6]

int n=arr.size();

// Brute TC->O(N) + O(min(pos,neg)) + O(leftovers) = O(2N) SC->O(N)
                //  |min     |max
                //  O(0)+O(n)  O(N/2)+O(0)
                // = O(N)
// varieties 2

vector<int>pos;
vector<int>neg;
 int i;
 for(i=0;i<n;i++)
 {
     if(arr[i]>0)
     {
         pos.push_back(arr[i]);
     }
     else
     {
         neg.push_back(arr[i]);
     }
 }
// 1,2,3,6
// -4,-5
if(pos.size()>neg.size())
{
    for(i=0;i<neg.size();i++)
    {
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    int index=neg.size()*2;
    for(i=neg.size();i<pos.size();i++)
    {
        arr[index]=pos[i];
        index=index+1;
    }
}
else
{
    for(i=0;i<pos.size();i++)
    {
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    int index=pos.size()*2;
    for(i=pos.size();i<neg.size();i++)
    {
        arr[index]=pos[i];
        index=index+1;
    }
}
for(i=0;i<n;i++)
{
    cout<<arr[i]<<endl;
}
}
