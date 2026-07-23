#include <bits/stdc++.h>
using namespace std;
int numberofenclave(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();

    int vis[n][m] = {0};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            // firstt row, first col, last row, last col
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int deltarow[] = {-1, 0, 1, 0};
    int deltacol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();
        // tarverse all 4 directions
        for (i = 0; i < 4; i++)
        {
            int nrow = row + deltarow[i];
            int ncol = col + deltacol[i];
            if (nroe >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
        |
    }
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                count = count + 1;
            }
        }
    }
    return count;
}
int main()
{
    // your code goes here
    // Number of enclave

    // TC->O(N*M*4) SC->O(N*M)
}
