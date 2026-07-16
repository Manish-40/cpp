#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    // 	ans=3

    // Brute TC->O(N*N) SC->O(1)
    int i;
    int j;
    int flag = 0;
    for (i = 1; i <= n; i++)
    {
        flag = 0;
        for (j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << i << endl;
            break;
        }
    }

    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    // 	ans=3

    // Better TC->O(2N) SC->O(N)

    int hash[n + 1] = {0};
    int i;
    for (i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }

    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    // 	ans=3

    // Optimal
    //     SUM : TC->O(N) SC->O(1) 
    int sum = n * (n + 1) / 2;
    int i;
    int s2 = 0;
    for (i = 0; i < n; i++)
    {
        s2 = s2 + arr[i];
    }
    cout << sum - s2 << endl;

    // XOR: TC->O(n) SC->O(1)
    // xor of same elemnet will return 0 a^a=0     0^2=2

    // int xor1=1^2^3^4^5
    // int xor2=1^2^4^5
    // xor1^xor2
    // (1^1)^(2^2)^(3)^(4^4)^(5^5)=3

    int xor1 = 0;
    int i;
    int xor2 = 0;

    for (i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    // xor1=xor1^n;
    cout << (xor1 ^ xor2) << endl;
}
