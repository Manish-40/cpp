#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Majority element N/3 times

vector<int>arr={1,1,1,3,3,2,2,2};
int n=arr.size();

// Brute TC->O(N^2) SC->O(1)

vector<int>ans;
int i;
int j;
int count=0;
for(i=0;i<arr.size();i++)
{
    if(ans.size()==0 || ans[0]!=arr[i])
    {
    count=0;
    for(j=0;j<arr.size();j++)
    {
        if(arr[j]==arr[i])
        {
            count=count+1;
        }
    }
    if(count>n/3) ans.push_back(arr[i]);
    }
    if(ans.size()==2) break;
}

for(auto it:ans)
{
    cout<<it<<endl;
}




vector<int>arr={1,1,1,3,3,2,2,2};
int n=arr.size();

// Optimal Hashing TC->O(N)*logN SC->O(n)
int i;
map<int,int>m;
vector<int>ans;
for(i=0;i<arr.size();i++)
{
    m[arr[i]]++;
    if(m[arr[i]]>arr.size()/3)
    {
        ans.push_back(arr[i]);
    }
    if(ans.size()==2) break;
}

for(auto it:ans)
{
    cout<<it<<endl;
}








vector<int>arr={1,1,1,3,3,2,2,2};
int n=arr.size();

// Optimal TC->O(2*N) SC->O(1)

int count1=0;
int count2=0;
int el1=INT_MIN;
int el2=INT_MIN;
int i;
for(i=0;i<arr.size();i++)
{
    if(count1==0 && arr[i]!=el2)
    {
        count1=1;
        el1=arr[i];
    }
    else if(count2==0 && arr[i]!=el1)
    {
        count2=1;
        el2=arr[i];
    }
    else if(arr[i]==el1) count1++;
    else if(arr[i]==el2) count2++;
    else
    {
        count1--;
        count2--;
    }
}

vector<int>ans;
count1=0;
count2=0;
for(i=0;i<arr.size();i++)
{
    if(arr[i]==el1) count1++;
    if(arr[i]==el2) count2++;
}
if(count1>arr.size()/3) ans.push_back(el1);
if(count2>arr.size()/3) ans.push_back(el2);
for(auto it:ans)
{
    cout<<it<<endl;
}
}
