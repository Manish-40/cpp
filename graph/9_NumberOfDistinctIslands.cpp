#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});
    int deltarow[] = {-1, 0, +1, 0};
    int deltacol[] = {0, +1, 0, -1};
    int i;
    int j;
    for (i = 0; i < 4; i++)
    {
        int nrow = row + deltarow[i];
        int ncol = col + deltacol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
}
int countdistinctislands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>(n.vector<int>(m, 0));
    int i;
    int j;
    set<vector<pair<int, int>>> st;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, grid, vis, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
int main()
{
    // your code goes here
    // Number of distinct islands
    // TC->N*M*log(set length)+(N*M*4) SC->O(N*M)
}
