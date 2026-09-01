#include <bits/stdc++.h>
using namespace std;
void f(int index,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
{
    int n=arr.size();
    ans.push_back(ds);
    
    int i;
    for(i=index;i<n;i++)
    {
        if(i!=index && arr[i]==arr[i-1]) continue;
        
        ds.push_back(arr[i]);
        f(i+1,arr,ds,ans);
        ds.pop_back();
    }
}
int main()
{
vector<int>arr{1,2,2,2,3,3};
int n=arr.size();

vector<vector<int>>ans;
vector<int>ds;

sort(arr.begin(),arr.end());

f(0,arr,ds,ans);

int i;
int j;

for(i=0;i<ans.size();i++)
{
    if(ans[i].size()==0) cout<<"{}";
    else
    {
        for(j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
    
    cout<<endl;
}

}