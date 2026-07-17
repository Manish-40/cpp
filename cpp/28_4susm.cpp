#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	4 Sum nums[i]+nums[j]+nums[l]+nums[h]=target
// [i!j!l!h]

vector<int>arr={1,0,-1,0,-2,2};
int target=0;
// [-2,-2,1,2] [-2,0,0,-2] [-1,0,0,1]

// Brute TC->O(N^4) SC->O(No of quads)*2
int i;
int j;
int l;
int h;
set<vector<int>>st;
for(i=0;i<arr.size();i++)
{
    for(j=i+1;j<arr.size();j++)
    {
        for(l=j+1;l<arr.size();l++)
        {
            for(h=l+1;h<arr.size();h++)
            {
                long long sum=arr[i]+arr[j];
                sum=sum+arr[l];
                sum=sum+arr[h];
                if(sum==target)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[l]);
                    temp.push_back(arr[h]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
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


vector<int>arr={1,0,-1,0,-2,2};
int target=0;
// [-2,-2,1,2] [-2,0,0,-2] [-1,0,0,1]

// Better TC->O(N^3)*log(m) SC->O(N)+O(No of quads)*2

// [1,0,-1,-2,2,0]]
//  i j         l
//  i thi j ne hashmap ma nakhsu

int i;
int j;
int l;
set<vector<int>>st;
for(i=0;i<arr.size();i++)
{
    for(j=i+1;j<arr.size();j++)
    {
        set<long long>hashset;
        for(l=j+1;l<arr.size();l++)
        {
            long long sum=arr[i]+arr[j];
            sum=sum+arr[l];
            long long fourth=target-(sum);
            if(hashset.find(fourth)!=hashset.end())
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[l]);
                temp.push_back(fourth);
                std::sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[l]);
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



vector<int>arr={1,1,1,2,2,2,3,3,3,4,4,4,5,5};
int target=8;
// [1,1,1,5] [1,1,2,4] [1,1,3,3] 

// Optimal TC->O(N^3) SC->O(No of quads)

sort(arr.begin(),arr.end());


// 1,1,1,2,2,2,3,3,3,4,4,4,5,5
// i j l                     h
vector<vector<int>>ans;
int i;
int j;
for(i=0;i<arr.size();i++)
{
    if(i>0 && arr[i]==arr[i-1]) continue;
    for(j=i+1;j<arr.size();j++)
    {
        if(j>i+1 && arr[j]==arr[j-1]) continue;
        int l=j+1;
        int h=arr.size()-1;
        while(l<h)
        {
            long long sum=arr[i];
            sum=sum+arr[j];
            sum=sum+arr[l];
            sum=sum+arr[h];
            if(sum==target)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[l]);
                temp.push_back(arr[h]);
                ans.push_back(temp);
                l++;
                h--;
                while(l<h && arr[l]==arr[l-1]) continue;
                while(l<h && arr[h]==arr[h+1]) continue;
            }
            else if(sum<target)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
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
