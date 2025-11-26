class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1000000007;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        // first row
        for (int j = 1; j < n; ++j) {
            for (int r = 0; r < k; ++r) {
                int nr = (r + grid[0][j]) % k;
                dp[0][j][nr] = (dp[0][j][nr] + dp[0][j - 1][r]) % MOD;
            }
        }
        
        // first column
        for (int i = 1; i < m; ++i) {
            for (int r = 0; r < k; ++r) {
                int nr = (r + grid[i][0]) % k;
                dp[i][0][nr] = (dp[i][0][nr] + dp[i - 1][0][r]) % MOD;
            }
        }
        
        // rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int r = 0; r < k; ++r) {
                    int nr = (r + grid[i][j]) % k;
                    dp[i][j][nr] = (dp[i][j][nr] + dp[i - 1][j][r]) % MOD;
                    dp[i][j][nr] = (dp[i][j][nr] + dp[i][j - 1][r]) % MOD;
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};