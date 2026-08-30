#include <bits/stdc++.h>
using namespace std;
void f(int left,int right,int n, int arr[])
{
    if(left>=right)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
        return;
    }
    
    swap(arr[left],arr[right]);
    
    f(left+1,right-1,n,arr);
}
int main() {
	// your code goes here
    // paramerterized recursion
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++) cin>>arr[i];
	
	f(0,n-1,n,arr);
	
}


#include <bits/stdc++.h>
using namespace std;
void f(int i,int n, int arr[])
{
    if(i>=n/2)
    {
        return;
    }
    
    swap(arr[i],arr[n-i-1]);
    
    f(i+1,n,arr);
}
int main() {
	// your code goes here
    // parameterized recursion
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++) cin>>arr[i];
	
	f(0,n,arr);
	
	for(i=0;i<n;i++) cout<<arr[i]<<endl;
	
}
