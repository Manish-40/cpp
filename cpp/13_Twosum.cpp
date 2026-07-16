#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    // Two sum

    vector<int> arr = {2, 6, 5, 8, 11};

    // Brute TC->O(N^2) SC->O(1)
    int target = 14;
    int i;
    int j;
    for (i = 0; i < arr.size(); i++)
    {
        for (j = 0; j < arr.size(); j++) // i+1 bhi kari sake
        {
            if (arr[i] + arr[j] == target)
            {
                cout << i << " " << j << endl;
            }
        }
    }

    vector<int> arr = {2, 6, 5, 8, 11};

    // Better TC->O(NlogN) SC->O(N)
    int target = 14;
    map<int, int> m;
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        int a = arr[i];
        int more = target - a;
        if (m.find(more) != m.end())
        {
            cout << "yes" << endl; // return (m[more],i);
        }
        m[a] = i;
    }
    cout << "no" << endl;

    vector<int> arr = {2, 6, 5, 8, 11};

    // Optimal TC->O(N) + O(NlogN) SC->O(1)
    int target = 14;
    std::sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << "yes" << endl;
            break;
        }
        else if (sum > target)
        {
            right = right - 1;
        }
        else
        {
            left = left + 1;
        }
    }
    cout << "no" << endl;
}
