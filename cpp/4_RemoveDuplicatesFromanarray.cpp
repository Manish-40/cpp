#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Remove duplicates in-place from sorted array

vector<int>arr={1,1,2,2,2,3,3};
// output 1, 2, 3, _, _, _ return 3 unique element

// Brute TC->O(NlonN+N) SC->O(N)
set<int>ans;
int i;
for(i=0;i<arr.size();i++)
{
    ans.insert(arr[i]);
}
int index=0;
for(auto it:ans)
{
    arr[index]=it;
    index++;
}
for(i=0;i<arr.size();i++)
{
    cout<<arr[i]<<endl;
    
}

// Optimal TC->O(N) SC->O(1)

int i=0;
int j;
for(j=1;j<arr.size();j++)
{
    if(arr[j]!=arr[i])
    {
        arr[i+1]=arr[j];
        i++;
    }
}
cout<<i+1<<endl;;

}
