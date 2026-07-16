#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// Check if array is sorted Non-descending order
// [1,2,2,3,3,4] Non-descending order
// [4,3,3,2,2,1] descending order

// TC->O(N) SC->O(1)
vector<int>arr={1,2,2,3,3,4};
int i;
for(i=1;i<arr.size();i++)
{
    if(arr[i]>=arr[i-1])
    {
        
    }
    else
    {
        cout<<"false"<<endl;
        break;
    }
    cout<<"true"<<endl;
}

}
