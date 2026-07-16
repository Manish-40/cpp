#include <bits/stdc++.h>
using namespace std;

int main() {
    // Left rotate an array by d places

vector<int>a={1,2,3,4,5,6,7}; // left rotate array 3,4,5,6,7,1,2
// int d=2; //3,4,5,6,7,1,2
int d=3; //4,5,6,7,1,2,3 
// int d=7 will bring it back to same place 1,2,3,4,5,6,7
// d=d%n  20%7=6 7+7+6

// Brute TC->O(d)+O(n-d)+O(d)=O(n+d) SC->O(d)
d=d%a.size();
vector<int>temp;
int i;
for(i=0;i<d;i++)
{
    temp.push_back(a[i]);
}
// temp[]={1,2,3}
// shifting
for(i=d;i<a.size();i++)
{
    a[i-d]=a[i];
}
// a[]={4,5,6,7}
// put back temp

// first approach
// int j=0;
// for(i=a.size()-d;i<a.size();i++)
// {
//     a[i]=temp[j];
//     j++;
// }

// second approach
for(i=a.size()-d;i<a.size();i++)
{
    a[i]=temp[i-(a.size()-d)];
}
// a[]={4,5,6,7,1,2,3}
for(auto it:a)
{
    cout<<it<<endl;
}


// Optimal TC-> O(D)+O(N-D)+O(N)=O(2N) SC->(1)
// 1,2,3,4,5,6,7
// reverse(a,a+d);
// reverse(a+d,a+a.size());
// reverse(a,a+a.size());

vector<int>a={1,2,3,4,5,6,7};
int d=3;
d=d%a.size();
std::reverse(a.begin(), a.begin()+d);
std::reverse(a.begin()+d,a.begin()+a.size());
std::reverse(a.begin(),a.begin()+a.size());

for(auto it:a)
{
    cout<<it<<endl;
}

}