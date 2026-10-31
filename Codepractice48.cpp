
class Solution {
    long long mod = 1e9 + 7;

public:
    int fun(vector<vector<int>>& grid, int i, int j, int k,
            vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m)
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        if (i == n-1 && j == m-1)
            return dp[i][j][k] = 1;

        long long ans = 0;

        if (grid[i][j] == 0) {
            ans += fun(grid, i+1, j, 2, dp);
            ans += fun(grid, i, j+1, 1, dp);
        }
        else {
            if (k == 1) {
                ans += fun(grid, i+1, j, 2, dp);
            }
            else {
                ans += fun(grid, i, j+1, 1, dp);
            }
        }

        return dp[i][j][k] = ans % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, -1))
        );

        return fun(grid, 0, 0, 1, dp);
    }
};