#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    // 	Largest subarray wiwth sum k

    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    // Brute TC->O(N^3) N cube SC->O(1)
    int k = 3;
    int i;
    int j;
    int sum = 0;
    int len = 0;
    for (i = 0; i < arr.size(); i++)
    {
        for (j = i; j < arr.size(); j++)
        {
            sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum = sum + arr[l];
            }
            if (sum == k)
            {
                len = max(len, (j - i + 1));
            }
        }
    }
    cout << len << endl;

    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    // Brute TC->O(N^2) N square SC->O(1)
    int k = 3;
    int i;
    int j;
    int sum = 0;
    int len = 0;
    for (i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (j = i; j < arr.size(); j++)
        {
            sum = sum + arr[j];
            if (sum == k)
            {
                len = max(len, (j - i + 1));
            }
        }
    }
    cout << len << endl;

    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    // vector<int> arr = {2, 0, 0, 3};
    // Better hashing hash map aarays has positive and negative TC->O(N*logN) or unordered map O(N*1) worst case O(N*N) O(N^2) SC->O(N)
    int k = 3;

    map<long long, int> preSumMap;
    long long sum = 0;
    int i;
    int maxLength = 0;
    for (i = 0; i < arr.size(); i++)
    {

        sum = sum + arr[i];
        if (sum == k)
        {
            maxLength = max(maxLength, i + 1);
            // index 0 and 1 ma sum thayu 3 to i=1 to +1 to length=2
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLength = max(maxLength, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    cout << maxLength << endl;

    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    // Optimal 2 pointer TC->O(2N) SC->O(1)
    int k = 6;

    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();
    while (right < n) // O(N)
    {
        while (left <= right && sum > k)
        // O(N) N^2 thavu jaoiye pan aa kyare loop chalse jyare sum>k sum vadhare thayu tyare
        {
            sum = sum - arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum = sum + arr[right];
        }
    }
    cout << maxLen << endl;
}
