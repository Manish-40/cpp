#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Maximum consicutive ones
// Optimal TC->O(N) SC->O(1)

vector<int>arr={1,1,0,1,1,1,0,1,1};
int count=0;
int maxi=0;
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]==1)
    {
        count=count+1;
        maxi=max(maxi,count);
    }
    else
    {
        count=0;
    }
}
cout<<maxi<<endl;
}
