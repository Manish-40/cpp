#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Intersection of two sorted arrays
// intersection matlab present in both the arrays

vector<int>arr1={1,2,2,3,3,4,5,6};
vector<int>arr2={2,3,3,5,6,6,7};
// intersection 2,3,3,5,6

// Brute TC->O(n1*n1) SC->O(n2)
int n1=arr1.size();
int n2=arr2.size();

vector<int>ans;
int visited[n2]={0};

int i;
int j;
for(i=0;i<n1;i++)
{
    for(j=0;j<n2;j++)
    {
        if(arr1[i]==arr2[j] && visited[j]==0)
        {
            ans.push_back(arr1[i]);
            visited[j]=1;
            break;
        }
        if(arr2[j]>arr1[i]) break;
    }
}
for(auto it:ans)
{
    cout<<it<<endl;
}



vector<int>arr1={1,2,2,3,3,4,5,6};
vector<int>arr2={2,3,3,5,6,6,7};
// intersection 2,3,3,5,6

// Optimal 2 pointer TC->O(n1+n2) SC->O(1)
vector<int>ans;

int i=0;
int j=0;

int n1=arr1.size();
int n2=arr2.size();

while(i<n1 && j<n2)
{
    if(arr1[i]<arr2[j])
    {
        i++;
    }
    else if(arr2[j]<arr1[i])
    {
        j++;
    }
    else
    {
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
}

for(auto it:ans)
{
    cout<<it<<endl;
}
}
