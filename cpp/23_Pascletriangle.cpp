#include <bits/stdc++.h>
using namespace std;
int ncr(int n,int r)
{
    // TC->O(r) SC->O(1)
    int res=1;
    int i;
    // 10c3
    for(i=0;i<r;i++)
    {
     res=res*(n-i);    // 10-0=10       10-1=9          10-2=8
     res=res/(i+1);  // 10/0+1=10/1    9/1+1=9/2        8/2+1=8/3
    }
    return res;
}
int main() {
	// your code goes here
// Pascal triangle
//          1
//        1   1
//      1   2   1
//    1   3   3   1
//   1  4   6   4   1
//  1  5  10  10  5   1

// 1 Given R&C feel the element at that place
// R=5 C=3
// R=5 1 4 6 4 1
// C=3 6
// ans=6

// 2 Print any nth row of pascal triangle 
// N=5
// ans=1 4 6 4 1

// 3 Given n print the entire triangle
// N=6

// formula R=R-1 C=C-1 nCr=n!/r!*(n-r)!  n=R-1 r=C-1
// 1 R=5 C=3 R=4 C=2 =4*3*2*1/(2*1)*(4-2)!
//                   =4*3*2*1/(2*1)*(2*1)
//                   =6


// 10c3
// Brute
int n=10;
int r=3;
cout<<ncr(n-1,r-1)<<endl;

}

#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
// Pascal triangle
//          1
//        1   1
//      1   2   1
//    1   3   3   1
//   1  4   6   4   1
//  1  5  10  10  5   1

// 1 Given R&C feel the element at that place
// R=5 C=3
// R=5 1 4 6 4 1
// C=3 6
// ans=6

// 2 Print any nth row of pascal triangle 
// N=5
// ans=1 4 6 4 1

// 3 Given n print the entire triangle
// N=6

// 2 
// nth row = n element

// ans=(row-col)/col


// TC->O(N) SC->O(1)
int row=6;
int ans=1;
cout<<ans<<endl;
int i;
for(i=1;i<row;i++)
{
    // col=i
    // row=n
    ans=ans*(row-i);
    ans=ans/(i);
    cout<<ans<<endl;
}


}


#include <bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row)
{
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
int main() {
	// your code goes here
// Pascal triangle
//          1
//        1   1
//      1   2   1
//    1   3   3   1
//   1  4   6   4   1
//  1  5  10  10  5   1

// 1 Given R&C feel the element at that place
// R=5 C=3
// R=5 1 4 6 4 1
// C=3 6
// ans=6

// 2 Print any nth row of pascal triangle 
// N=5
// ans=1 4 6 4 1

// 3 Given n print the entire triangle
// N=6

// 3

// TC->O(N^2) SC->O(1)
vector<vector<int>>ans;
int n=6;
for(int i=1;i<n;i++)
{
    ans.push_back(generateRow(i));
}
for(int i=0;i<ans.size();i++)
{
    for(int j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<endl;
    }
}


}

