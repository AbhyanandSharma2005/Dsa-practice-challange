class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1000000007;
        long[] dp = new long[n + 1];
        dp[1] = 1;
        long share = 0;
        for (int day = 2; day <= n; day++) {
            share = (share + dp[Math.max(0, day - delay)] - dp[Math.max(0, day - forget)]) % mod;
            dp[day] = (share + mod) % mod;
        }
        long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) ans = (ans + dp[i]) % mod;
        return (int) ans;
    }
}
