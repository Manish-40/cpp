#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Second largest in an array

vector<int>arr={1,2,4,7,7,5};
// Brute TC->O(NlogN + N) SC->O(1)
std::sort(arr.begin(), arr.end());
int i;
int largest=arr[arr.size()-2];
int second;
int n=arr.size();
for(i=arr.size()-2;i>=0;i--)
{
    if(arr[i]!=largest)
    {
        second=arr[i];
        break;
    }
}
cout<<second<<endl;


// Better TC->O(2N) SC->O(1);
int largest=arr[0];
int slargest=-1; // INT_MIN bhi chale
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]>largest)
    {
        largest=arr[i];
    }
}
for(i=0;i<arr.size();i++)
{
    if(arr[i]>slargest && arr[i]!=largest)
    {
        slargest=arr[i];
    }
}
cout<<slargest<<endl;


// Optimal TC->O(N) SC->O(1)
int largest=arr[0];
int slargest=-1; // INT_MIN bhi chale
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]>largest)
    {
        slargest=largest;
        largest=arr[i];
    }
    else if(arr[i]<largest && arr[i]>slargest)
    {
        slargest=arr[i];
    }
}
cout<<slargest<<endl;

}
