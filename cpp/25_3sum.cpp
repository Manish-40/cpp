#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
//  3Sum

vector<int>arr={-1,0,1,2,-1,-4};
// arr[i]+arr[j]+arr[l]=0
// (i!=j!=l)

// Brute TC->O(N^3)*log(no of unique triplets) SC->2*O(no of triplets)

int i;
int j;
int l;
set<vector<int>>st;
for(i=0;i<arr.size();i++)
{
    for(j=i+1;j<arr.size();j++)
    {
        for(l=j+1;l<arr.size();l++)
        {
            if(arr[i]+arr[j]+arr[l]==0)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[l]);
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
        }
    }
}
vector<vector<int>>ans(st.begin(),st.end());
for(i=0;i<ans.size();i++)
{
    for(j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<endl;
    }
}




vector<int>arr={-1,0,1,2,-1,-4};
// arr[i]+arr[j]+arr[l]=0
// (i!=j!=l)

// Better Hashing TC->O(N^2)*log(m(size of set)) SC->O(N)+2*O(no of unique triplets)
int i;
int j;
set<vector<int>>st;
for(i=0;i<arr.size();i++)
{
    set<int>hashset;
    for(j=i+1;j<arr.size();j++)
    {
        int third=-(arr[i]+arr[j]);
        if(hashset.find(third)!=hashset.end())
        {
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            temp.push_back(third);
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        hashset.insert(arr[j]);
    }
}
vector<vector<int>>ans(st.begin(),st.end());
for(i=0;i<ans.size();i++)
{
    for(j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<endl;
    }
}




vector<int>arr={-1,0,1,2,-1,-4};
// arr[i]+arr[j]+arr[l]=0
// (i!=j!=l)

// Optimal 2 pointer TC->O(NlogN) for sorting + O(N*N) SC->O(no of unique triplets)


sort(arr.begin(),arr.end());
// [-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2]
vector<vector<int>>ans;
int i;
for(i=0;i<arr.size();i++)
{
    if(i>0 && arr[i]==arr[i-1]) continue;
    // 1 1 1 2 aa 3 var continue thase pachi 2 par aavse
    int j=i+1;
    int l=arr.size()-1;
    while(j<l)
    {
        int sum=arr[i]+arr[j]+arr[l];
        if(sum<0)
        {
            j++;
        }
        else if(sum>0)
        {
            l--;
        }
        else
        {
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            temp.push_back(arr[l]);
            ans.push_back(temp);
            j++;
            l--;
            while(j<l && arr[j]==arr[j-1]) j++;
            while(j<l && arr[l]==arr[l+1]) l--;
        }
    }
}
int i1;
int j1;
for(i1=0;i1<ans.size();i1++)
{
    for(j1=0;j1<ans[i1].size();j1++)
    {
        cout<<ans[i1][j1]<<endl;
    }
}
}
