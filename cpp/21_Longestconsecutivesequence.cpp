#include <bits/stdc++.h>
using namespace std;
bool ls(vector<int>&arr,int x)
{
    int i;
    for(i=0;i<arr.size();i++)
    {
        if(arr[i]==x)
        {
            return true;
        }
    }
    return false;
}
int main() {
	// your code goes here
// 	Longest consecutive sequence

vector<int>arr={102,4,100,1,101,3,2,1,1};
// 1 2 3 4 len=4

// Brute TC->O(N^2) SC->O(1)
int i;
int longest=1;
int count=0;
for(i=0;i<arr.size();i++)
{
    int x=arr[i];
    count=1;
    while(ls(arr,x+1)==true)
    {
        x=x+1;
        count=count+1;
    }
}
cout<<count<<endl;




vector<int>arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
// sort [1,1,1,2,2,2,3,3,4,100,100,101,101,102]
// 1 2 3 4 len=4

// Better TC->O(NlogN)+O(N) SC->O(1)
sort(arr.begin(),arr.end());
int longest=1;
int countCur=0;
int lastSmall=INT_MIN;
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]-1==lastSmall)
    {
        countCur=countCur+1;
    }
    else if(arr[i]!=lastSmall)
    {
        countCur=1;
        lastSmall=arr[i];
    }
    longest=max(longest,countCur);
}
cout<<longest<<endl;





// Optimal TC->O(N)+O(2N)=O(3N) SC->O(N)
int i;
unordered_set<int>st;
int longest=1;
for(i=0;i<arr.size();i++)
{
    st.insert(arr[i]);
}
// st  2 3 101 1 100 4 102

for(auto it:st)
{
    if(st.find(it-1)==st.end())
    {
        int count=1;
        int x=it;
        while(st.find(x+1)!=st.end())
        {
            x=x+1;
            count=count+1;
        }
        longest=max(longest,count);
    }
}
cout<<longest<<endl;
} 
