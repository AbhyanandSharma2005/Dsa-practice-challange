class Solution {
    public int minCost(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        final int INF = 1000000000;
        
        int[][][] dp = new int[m][n][k + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(dp[i][j], INF);
            }
        }
        
        dp[0][0][0] = 0;
        
        List<Integer> vals = new ArrayList<>();
        for (int[] row : grid) {
            for (int val : row) {
                vals.add(val);
            }
        }
        Collections.sort(vals);
        vals = new ArrayList<>(new LinkedHashSet<>(vals));
        
        for (int p = 0; p <= k; p++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j][p] == INF) continue;
                    
                    if (i + 1 < m) {
                        dp[i + 1][j][p] = Math.min(dp[i + 1][j][p], dp[i][j][p] + grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1][p] = Math.min(dp[i][j + 1][p], dp[i][j][p] + grid[i][j + 1]);
                    }
                }
            }
            
            if (p < k) {
                int[] suffixMin = new int[vals.size()];
                Arrays.fill(suffixMin, INF);
                
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dp[i][j][p] != INF) {
                            int idx = Collections.binarySearch(vals, grid[i][j]);
                            suffixMin[idx] = Math.min(suffixMin[idx], dp[i][j][p]);
                        }
                    }
                }
                
                for (int i = vals.size() - 2; i >= 0; i--) {
                    suffixMin[i] = Math.min(suffixMin[i], suffixMin[i + 1]);
                }
                
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int idx = Collections.binarySearch(vals, grid[i][j]);
                        if (suffixMin[idx] != INF) {
                            dp[i][j][p + 1] = Math.min(dp[i][j][p + 1], suffixMin[idx]);
                        }
                    }
                }
            }
        }
        
        int ans = INF;
        for (int p = 0; p <= k; p++) {
            ans = Math.min(ans, dp[m - 1][n - 1][p]);
        }
        return ans;
    }
}