#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	vector<int>nums={1,1,1,2,2,3};
	int k=2;
	int i;
	int n=nums.size();
        map<int,int>m;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto it:m)
        {
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(i=n-1;i>=0 && ans.size()<k;i--)
        {
            for(int num:bucket[i])
            {
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
        for(auto it:ans)
        {
            cout<<it<<endl;
        }
}
