#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
    // linear
	int n;
	cin>>n;
	
	int arr[n];
	
	arr[0]=0;
	arr[1]=1;
	
	int i;
	for(i=2;i<=n;i++)
	{
	    arr[i]=arr[i-1]+arr[i-2];
	}
	
	for(i=0;i<=n;i++)
	{
	    cout<<arr[i]<<endl;
	}
}


#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n<=1) return n;
    
    return f(n-1)+f(n-2);
}
int main() {
	// your code goes here
    // functional recursion
	int n;
	cin>>n;
	
	cout<<f(n)<<endl;
}


#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n<=1) return n;
    
    int last=f(n-1);
    int slast=f(n-2);
    
    return last+slast;
}
int main() {
	// your code goes here
    // functona recursion
	int n;
	cin>>n;
	
	cout<<f(n)<<endl;
}
