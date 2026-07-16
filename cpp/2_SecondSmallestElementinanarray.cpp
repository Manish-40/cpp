#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
vector<int>arr={1,2,4,7,7,5};
// Second smallest element in an array
// Optimal TC->O(N) SC->O(1)
int smallest=arr[0];
int ssmallest=INT_MAX;
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]<smallest)
    {
        ssmallest=smallest;
        smallest=arr[i];
    }
    else if(arr[i]!=smallest && arr[i]<ssmallest)
    {
        ssmallest=arr[i];
    }
}
cout<<smallest<<endl;
cout<<ssmallest<<endl;

}
