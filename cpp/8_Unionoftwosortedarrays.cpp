#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Union of two sorted arrays

vector<int>arr1={1,1,2,3,4,5};
vector<int>arr2={2,3,4,4,5,6};
// union combine kare bev array ne pan unique 1 var j hovu joiye union array ma

// Brute step1-O(N1logN)+O(N2logN) step2-O(N1+N2
// TC->O(n1logn +n2logn) + O(n1+n2) SC->O(n1+n2)+O(n1+n2)
set<int>st;
int i;
// step1
for(i=0;i<arr1.size();i++)
{
    st.insert(arr1[i]);
}
for(i=0;i<arr2.size();i++)
{
    st.insert(arr2[i]);
}
// step2
vector<int>union1;

for(auto it:st)
{
    union1.push_back(it);
}
for(auto it:union1)
{
    cout<<it<<endl;
}




vector<int>arr1={1,1,2,3,4,5};
vector<int>arr2={2,3,4,4,5,6};
// Optimal TC->O(n1+n2) SC->O(n1+n2)
int n1=arr1.size();
int n2=arr2.size();

int i=0;
int j=0;

vector<int>unionArr;
while(i<n1 && j<n2)
{
    if(arr1[i]<=arr2[j])
    {
        if(unionArr.size()==0 || unionArr.back()!=arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    else
    {
     if(unionArr.size()==0 || unionArr.back()!=arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;   
    }
}
while(i<n1)
{
 if(unionArr.size()==0 || unionArr.back()!=arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;   
}
while(j<n2)
{
    if(unionArr.size()==0 || unionArr.back()!=arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++; 
}

for(auto it:unionArr)
{
    cout<<it<<endl;
}
}
