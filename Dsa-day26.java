class Solution {
    public int numberOfWays(int n, int x) {
        int MOD = 1_000_000_007;

        int[] dp = new int[n + 1];
        
        dp[0] = 1;

        int num = 1;
        while (true) {
            int p = (int) Math.pow(num, x);
            
            if (p > n) {
                break;
            }

            for (int j = n; j >= p; j--) {
                dp[j] = (dp[j] + dp[j - p]) % MOD;
            }
            
            num++;
        }

        return dp[n];
    }
}