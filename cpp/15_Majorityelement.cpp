#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    // 	Majority element(n>n/2 times)

    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    // ans=4
    // count>n/2
    // Brute TC->O(N^2)

    int i;
    int j;
    int count = 0;
    for (i = 0; i < arr.size(); i++)
    {
        count = 0;
        for (j = 0; j < arr.size(); j++)
        {
            if (arr[j] == arr[i])
            {
                count = count + 1;
            }
        }
        if (count > arr.size() / 2)
        {
            cout << arr[i] << endl; // count kidhu hoy to cout<<count<<endl;
            break;
        }
    }


    vector<int>arr={2,2,3,3,1,2,2};
// ans=4
// count>n/2
// Better TC->O(NlogN) + O(N) SC->O(N)

int i;
map<int,int>m;
for(i=0;i<arr.size();i++)
{
    m[arr[i]]++;
}
for(auto it:m)
{
    if(it.second>arr.size()/2)
    {
        cout<<it.first<<endl;
        break;
    }
}




vector<int>arr={2,2,3,3,1,2,2};
// ans=4
// count>n/2
// Optimal Moore's voting algorithm TC->O(N)+O(N) SC->O(1)

// 1 Apply moore's voting algorithm
// 2 verifies if element is majority or not

int count=0;
int el;
int i;
for(i=0;i<arr.size();i++)
{
    if(count==0)
    {
        count=1;
        el=arr[i];
    }
    else if(arr[i]==el)
    {
        count=count+1;
    }
    else
    {
        count=count-1;
    }
}
// ayya tak to count=1 avvyu el=2 thayu
int count1=0;
for(i=0;i<arr.size();i++)
{
    if(arr[i]==el) count1=count1+1;
    // ayya el=2 ne check karyu 2==2 to aetla element count karyu
}


if(count1>arr.size()/2) // ayya pachi count1>n/2   4>n/2 che to ans=2
{
    cout<<el<<endl;
}
}
