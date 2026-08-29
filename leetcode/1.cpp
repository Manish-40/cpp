#include <bits/stdc++.h>
using namespace std;
// bool f(int i,string s)
// {
//     int n=s.size();
//     if(i>=n/2) return true;
//     if(s[i]!=s[n-i-1]) return false;
//     return f(i+1,s);
// }
int main() {
	// your code goes here
// 	4030
// 1 aam bhi kari sakiye
// 	string s="ff";
	
// 	for(char ch:s)
// 	{
// 	        // Convert and print the 8-bit binary representation
//     std::cout << ch << " in binary: " << std::bitset<8>(ch) << "\n"; // 01100001
// 	}
	
// 	2 aam bhi kari sakiye using recursion upper bool f aanu che
// 	string s="leet";
// 	cout<<f(0,s);

   
   
   
   
   
//   4020
   int n=3;
   vector<int>requests{2,0,0};
   int count=0;
   int i;
   count=requests[0];
   for(i=0;i<requests.size()-1;i++)
   {
       count=count+abs(requests[i]-requests[i+1]);
   }
   cout<<count<<endl;
	
}
