#include <bits/stdc++.h>
using namespace std;
void f(int index,int sum,vector<int>&arr,int n,vector<int>&sumSubset)
{
    if(index==n)
    {
        sumSubset.push_back(sum);
        return;
    }
    
    // pick element
    f(index+1,sum+arr[index],arr,n,sumSubset);
    
    // not pick element
    f(index+1,sum,arr,n,sumSubset);
}
int main() {
	// your code goes here
vector<int>arr{3,1,2};
int n=arr.size();

vector<int>sumSubset;
f(0,0,arr,n,sumSubset);

sort(sumSubset.begin(),sumSubset.end());

int i;
for(i=0;i<sumSubset.size();i++)
{
    cout<<sumSubset[i]<<endl;
}

}