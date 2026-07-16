#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Leaders in an array   everything on the right should be smaller

vector<int>arr={10,22,12,3,0,6};
// ans 22 is leader 
// ans 12 is leader
// last element is the always leader
// ans=[22,12,6]

// Brute TC->O(N^2) SC->O(1)
int i;
int j;
bool leader;
vector<int>ans;
for(i=0;i<arr.size();i++)
{
    leader=true;
    for(j=i+1;j<arr.size();j++)
    {
        if(arr[j]>=arr[i])
        {
            leader=false;
            break;
        }
    }
    if(leader==true) ans.push_back(arr[i]);
}
for(auto it:ans)
{
    cout<<it<<endl;
}




vector<int>arr={10,22,12,3,0,6};
// ans 22 is leader 
// ans 12 is leader
// last element is the always leader
// ans=[22,12,6]

// Optimal TC->O(N)+sort-NlogN SC->O(1)

int i;
int maxi=INT_MIN;
vector<int>ans;
for(i=arr.size()-1;i>=0;i--)
{
    if(arr[i]>maxi)
    {
        ans.push_back(arr[i]);
    }
    maxi=max(maxi,arr[i]);
}
sort(arr.begin(),arr.end());
for(auto it:ans)
{
    cout<<it<<endl;
}
}
