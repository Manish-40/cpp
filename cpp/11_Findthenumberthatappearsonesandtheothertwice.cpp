#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    // 	Find the number that appears ones and the other twice

    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    // ans=2

    // Brute TC->O(N^2) n square SC->O(1)
    int i;
    int num;
    int j;
    int count = 0;
    for (i = 0; i < arr.size(); i++)
    {
        num = arr[i];
        count = 0;
        for (j = 0; j < arr.size(); j++)
        {
            if (arr[j] == num)
            {
                count = count + 1;
            }
        }
        if (count == 1)
        {
            cout << num << endl;
            break;
        }
    }

    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    // ans=2

    // Better TC->O(3N) SC->O(maxi)
    int maxi = arr[0];
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int hash[maxi] = {0};

    for (i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    for (i = 0; i < maxi; i++)
    {
        if (hash[arr[i]] == 1)
        {
            cout << arr[i] << endl;
            break;
        }
    }

    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    // ans=2

    // Better TC-> NlogM + (N/2)+1 SC-> O(N)

    map<long, long> m;
    int i;
    for (i = 0; i < arr.size(); i++)
    { // Ordered map NlogM N->size of array logM->size of map
      // Unordered map O(N)
        m[arr[i]]++;
    }
    for (auto it : m)
    { // O((N/2)+1)
        if (it.second == 1)
        {
            cout << it.first << endl;
            break;
        }
    }

    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    // ans=2

    // Better TC-> NlogM + (N/2)+1 SC-> O(N)

    map<long, long> m;
    int i;
    for (i = 0; i < arr.size(); i++)
    { // Ordered map NlogM N->size of array logM->size of map
      // Unordered map O(N)
        m[arr[i]]++;
    }
    for (auto it : m)
    { // O((N/2)+1)
        if (it.second == 1)
        {
            cout << it.first << endl;
            break;
        }
    }

    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    // ans=2

    // Optimal TC->O(N) SC->O(1)
    int i;
    int xor1 = 0;
    for (i = 0; i < arr.size(); i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    cout << xor1 << endl;
}
