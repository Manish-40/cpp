#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
void func(int index, string s, vector<string>&arr, vector<vector<string>>&ans)
{
    if(index==s.size())
    {
        ans.push_back(arr);
        return;
    }
    
    int i;
    for(i=index;i<s.size();i++)
    {
        if(isPalindrome(s,index,i))
        {
            arr.push_back(s.substr(index,i-index+1));
            func(i+1,s,arr,ans);
            arr.pop_back();
        }
    }
}
int main() {
	// your code goes here
	string s="aabb";
	vector<vector<string>>ans;
	vector<string>arr;
	func(0,s,arr,ans);
	int i;
	int j;
	for(i=0;i<ans.size();i++)
	{
	    for(j=0;j<ans[i].size();j++)
	    {
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
}
