#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Linear Search
vector<int>arr={6,7,8,4,1};
int num=4;
int i;
for(i=0;i<arr.size();i++)
{
    if(arr[i]==num)
    {
        return i;
    }
}
return -1;
}
