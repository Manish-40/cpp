#include <bits/stdc++.h>
using namespace std;
void f(int i,int fact)
{
    if(i<1)
    {
        cout<<fact<<endl;
        return;
    }
    
    f(i-1,fact*i);
}
int main() {
	// your code goes here
    // parameterized recursion
	int n;
	cin>>n;
	f(n,1);
}


#include <bits/stdc++.h>
using namespace std;
int f(int i)
{
    if(i==0)
    {
        return 1;
    }
    else
    {
        return i*f(i-1);
    }
}
int main() {
	// your code goes here
    // functional recursion
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}
