#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n=4;
	int k=17;
	
	vector<int>numbers;
	int fact=1;
	int i;
	for(i=1;i<n;i++)
	{
	    fact=fact*i;
	    numbers.push_back(i);
	}
	numbers.push_back(n);
	
	string ans="";
	k=k-1;
	while(true)
	{
	    ans=ans+to_string(numbers[k/fact]);
	    numbers.erase(numbers.begin()+k/fact);
	    if(numbers.size()==0)
	    {
	        break;
	    }
	    k=k%fact;
	    fact=fact/numbers.size();
	}
	cout<<ans<<endl;

}
