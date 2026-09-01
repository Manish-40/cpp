#include <bits/stdc++.h>
using namespace std;
void f(vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans,int freq[])
{
    if(ds.size()==arr.size())
    {
        ans.push_back(ds);
        return;
    }
    
    int i;
    for(i=0;i<arr.size();i++)
    {
        if(!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i]=1;
            
            f(ds,arr,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
int main()
{
vector<int>arr{1,2,3};
int n=arr.size();

vector<int>ds;
vector<vector<int>>ans;

int freq[n];

int i;
for(i=0;i<n;i++) freq[i]=0;

f(ds,arr,ans,freq);

int j;
for(i=0;i<ans.size();i++)
{
    for(j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

}


#include <bits/stdc++.h>
using namespace std;
void f(int index,vector<int>&arr,vector<vector<int>>&ans)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    
    int i;
    for(i=index;i<arr.size();i++)
    {
        swap(arr[index],arr[i]);
        f(index+1,arr,ans);
        swap(arr[index],arr[i]);
    }
}
int main()
{
    vector<int>arr{1,2,3};
    int n=arr.size();
    
    // Another approach

    vector<vector<int>>ans;
    f(0,arr,ans);
    
    int i;
    int j;
    for(i=0;i<ans.size();i++)
    {
        for(j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}