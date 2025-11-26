class Solution {
    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        final int MOD = 1000000007;
        
        int[][][] dp = new int[m][n][k];
        
        dp[0][0][grid[0][0] % k] = 1;
        
        // first row
        for (int j = 1; j < n; j++) {
            for (int r = 0; r < k; r++) {
                int nr = (r + grid[0][j]) % k;
                dp[0][j][nr] = (dp[0][j][nr] + dp[0][j - 1][r]) % MOD;
            }
        }
        
        // first column
        for (int i = 1; i < m; i++) {
            for (int r = 0; r < k; r++) {
                int nr = (r + grid[i][0]) % k;
                dp[i][0][nr] = (dp[i][0][nr] + dp[i - 1][0][r]) % MOD;
            }
        }
        
        // rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    int nr = (r + grid[i][j]) % k;
                    dp[i][j][nr] = (dp[i][j][nr] + dp[i - 1][j][r]) % MOD;
                    dp[i][j][nr] = (dp[i][j][nr] + dp[i][j - 1][r]) % MOD;
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
}