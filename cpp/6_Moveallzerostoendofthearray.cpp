#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Move all zeros to the end of the array

vector<int>arr={1,0,2,3,2,0,0,4,5,1};  // 1,2,3,2,4,5,1,0,0,0

// Brute  step1-O(N) step2-O(N) step3-O(N-N) TC->O(2N) SC->O(N)
// step1
vector<int>temp;
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]!=0)
    {
        temp.push_back(arr[i]);
    }
}
// step2
for(i=0;i<arr.size();i++)
{
    arr[i]=temp[i];
}
// step3
for(i=temp.size();i<arr.size();i++)
{
    arr[i]=0;
}
for(auto it:arr)
{
    cout<<it<<endl;
}



vector<int>arr={1,0,2,3,2,0,0,4,5,1};  // 1,2,3,2,4,5,1,0,0,0
// Optimal 2 pointer step1-O(n) step2-O(N-N) TC->O(N) SC->O(1);

int i;
int j=-1;
// step1
for(i=0;i<arr.size();i++)
{
    if(arr[i]==0)
    {
        j=i;
        break;
    }
}
// step2
for(i=j+1;i<arr.size();i++)
{
    if(arr[i]!=0)
    {
        swap(arr[i],arr[j]);
        j++;
    }
}
for(auto it:arr)
{
    cout<<it<<endl;
}
}
