#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Next permutation  

vector<int>arr={3,1,2}
// next permuation arr.size() ! factorial 3 factorial 6
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// ans 3 2 1

// for 3 2 1 next permutation 1 2 3

// Brute

// recursion TC->O(N!*N)
// 1 generate all sorted
// 2 linear search
// 3 next index


vector<int>arr={3,1,2};
// next permuation arr.size() ! factorial 3 factorial 6
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// ans 3 2 1

// for 3 2 1 next permutation 1 2 3

// Better

std::next_permutation(arr.begin(),arr.end());
for(auto it:arr)
{
    cout<<it<<endl;
}



vector<int>arr={2,1,5,4,3,0,0};
// 2 3 0 0 1 4 5
// TC->O(3N) SC->O(1)
// Optimal
// 1 longer prefix match
// 2 find > greater than 1 but the smallest longer so that you stay close
// 3 try to place remaining in sorted array
int i;
int ind=-1;
for(i=arr.size()-2;i>=0;i--)
{
    if(arr[i]<arr[i+1])
    {
        ind=i;
        break;
    }
}
if(ind==-1)
{
    std::reverse(arr.begin(), arr.end());
}
for(i=arr.size()-1;i>ind;i--)
{
    if(arr[i]>arr[ind])
    {
        swap(arr[i],arr[ind]);
        break;
    }
}
std::reverse(arr.begin()+ind+1, arr.end());
for(auto it:arr)
{
    cout<<it<<endl;
}
}
