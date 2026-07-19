#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Merge overlapping subintervals

// [(1,3) (2,6) (8,9) (9,11) (8,10) (2,4) (16,18) (16,17)]

// ans={1,6} {8,11} {15,18}

// subintervals
// 1 start, 3 end

//   ____          _____
//   _______         ______                ____
// ____            ___                  __________
// 1 2 3 4 6       8 9 10 11            15 16 17 18

// (1,6)           (8,11)               (15,18)


// Brute TC->O(NlogN)+O(2N) SC->O(N)

vector<vector<int>>arr={{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
int n=arr.size();
sort(arr.begin(),arr.end());  // nlogn
vector<vector<int>>ans;
int i;
int j;
for(i=0;i<n;i++)
{
    int start=arr[i][0];
    int end=arr[i][1];
    if(!ans.empty() && end<=ans.back()[1])
    {
        continue;
    }
    for(j=i+1;j<n;j++)
    {
        if(arr[j][0]<=end)
        {
            end=max(end,arr[j][1]);
        }
        else
        {
            break;
        }
    }
    ans.push_back({start,end});
    
}
for(i=0;i<ans.size();i++)
{
    for(j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<endl;
    }
}









// Optimal TC->O(NlogN)+O(N) SC->O(N)

vector<vector<int>>arr={{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
int n=arr.size();
sort(arr.begin(),arr.end());  // nlogn
vector<vector<int>>ans;
int i;
int j;
for(i=0;i<n;i++)
{
    if(ans.empty() || arr[i][0]>ans.back()[1])
    {
        ans.push_back(arr[i]);
    }
    else
    {
        ans.back()[1]=max(ans.back()[1],arr[i][1]);
    }
}
for(i=0;i<ans.size();i++)
{
    for(j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<endl;
    }
}
}
