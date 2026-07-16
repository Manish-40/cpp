#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int>arr={1,2,3,4};
// 	ans 24,12,8,6
    vector<int>output(arr.size(),1);
    int left=1;
    for(int i=0;i<arr.size();i++)
    {
        output[i]=left;
        left=left*arr[i];
    }
    // output 1 1 2 6
    int right=1;
    for(int i=arr.size()-1;i>=0;i--)
    {
        output[i]=output[i]*right;
        right=right*arr[i];
    }
    // output 24 12 8 6
    for(auto it:output)
    {
        cout<<it<<endl;
    }
	
}
