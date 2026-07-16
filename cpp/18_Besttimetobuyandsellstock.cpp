#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	Best time to buy and sell stock
// Dynamic Programming // remembering the past aene dynamic programming kehvay
vector<int>arr={7,1,5,3,6,4};
// TC->O(N) SC->O(1)
int n=arr.size(); //n days
// Buy-1 rupees ma
// Sell-6 rupees ma
// profit=5  profit maximize

// if you are selling on ith day you buy on the minimum price from 1st->(i-1)

int mini=arr[0];
int profit=0;
int i;
for(i=1;i<n;i++)
{
    int cost=arr[i]-mini;
    profit=max(profit,cost);
    mini=min(mini,arr[i]);
}
cout<<profit<<endl;



}
