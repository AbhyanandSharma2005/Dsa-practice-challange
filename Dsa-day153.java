import java.util.*;

class Solution {
    private long[][][] memo;
    private int[] prices;
    private int n;
    
    public long maximumProfit(int[] prices, int k) {
        this.prices = prices;
        this.n = prices.length;
        this.memo = new long[n + 1][k + 1][3];
        
        for (long[][] layer : memo) {
            for (long[] row : layer) {
                Arrays.fill(row, -1);
            }
        }
        
        return dfs(0, k, 0);
    }
    
    private long dfs(int i, int rem, int state) {
        if (i == n) {
            return (state == 0) ? 0L : Long.MIN_VALUE / 2;
        }
        
        if (memo[i][rem][state] != -1) {
            return memo[i][rem][state];
        }
        
        long ans = Long.MIN_VALUE / 2;
        
        if (state == 0) {
            ans = dfs(i + 1, rem, 0);
            
            if (rem > 0) {
                ans = Math.max(ans, dfs(i + 1, rem - 1, 1) - prices[i]);
                ans = Math.max(ans, dfs(i + 1, rem - 1, 2) + prices[i]);
            }
        }
        else if (state == 1) {
            long keep = dfs(i + 1, rem, 1);
            long sell = dfs(i + 1, rem, 0) + prices[i];
            ans = Math.max(keep, sell);
        }
        else if (state == 2) {
            long keep = dfs(i + 1, rem, 2);
            long cover = dfs(i + 1, rem, 0) - prices[i];
            ans = Math.max(keep, cover);
        }
        
        memo[i][rem][state] = ans;
        return ans;
    }
}