#include <bits/stdc++.h>
using namespace std;
void f(int i,int sum)
{
    if(i<1) 
    {
        cout<<sum<<endl;
        return;
    }
    
    f(i-1,sum+i);
}
int main() {
	// your code goes here
    // parametersized recursion
	int n;
	cin>>n;
	f(n,0);
}


#include <bits/stdc++.h>
using namespace std;
int f(int i)
{
    if(i==0)
    {
        return 0;
    }
    else
    {
        return i+f(i-1);
    }
}
int main() {
	// your code goes here
    // functinal recursion
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}
