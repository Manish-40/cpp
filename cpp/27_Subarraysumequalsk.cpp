#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int>arr={1,2,3};
	int k=3;
	int i;
	int j;
	int sum=0;
	int count=0;
	for(i=0;i<arr.size();i++)
	{
	    sum=0;
	    for(j=i;j<arr.size();j++)
	    {
	        sum=sum+arr[i];
	        if(sum==k)
	        {
	            count=count+1;
	        }
	    }
	}
	cout<<count<<endl;

	
}
