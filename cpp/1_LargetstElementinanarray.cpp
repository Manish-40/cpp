#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Largest Element in an array 
// Brute, Better, Optimal

vector<int>arr={3,2,1,5,2};
// Brute  TC-> O(NlogN) SC->O(1)

std::sort(arr.begin(),arr.end());
cout<<arr[arr.size()-1]<<endl;

// Optimal TC->O(N) SC->O(1)

int largest=arr[0];
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]>largest)
    {
        largest=arr[i];
    }
}
cout<<largest<<endl;
}
