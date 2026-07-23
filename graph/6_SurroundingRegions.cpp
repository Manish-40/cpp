#include <bits/stdc++.h>
using namespace std;
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat, int deltarow[], int deltacol[]) {

        int n = mat.size();
        int m = mat[0].size();

        vis[row][col] = 1;

        // check for top right bottom left
        int i;
        for (i = 0; i < 4; i++) {
            int nrow = row + deltarow[i];
            int ncol = col + deltacol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, deltarow, deltacol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // check for top right bottom left
        int deltarow[] = {-1, 0, +1, 0};
        int deltacol[] = {0, +1, 0, -1};

        int j;
        // traverse first row and last row
        for (j = 0; j < m; j++) {
            // first row
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, deltarow, deltacol);
            }
            // last row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, deltarow, deltacol);
            }
        }
        // traverse first column and last column
        int i;
        for (i = 0; i < n; i++) {
            // first column
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, deltarow, deltacol);
            }
            // last column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, deltarow, deltacol);
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
int main() {
	// your code goes here
// 	Surrounded regions

// TC->O(N*M) SC->O(N*M)

}
