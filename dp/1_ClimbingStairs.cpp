#include <bits/stdc++.h>
using namespace std;
int f(int index)
{
    if(index==0) return 1;
    if(index==1) return 1;
    int left=f(index-1);
    int right=f(index-2);
    return left+right;
}
int main() {
	// your code goes her
	int n;
	cin>>n;
	cout<<f(n-1)<<endl;
}
