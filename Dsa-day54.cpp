class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        long long share = 0;
        for (int day = 2; day <= n; day++) {
            share = (share + dp[max(0, day - delay)] - dp[max(0, day - forget)]) % mod;
            dp[day] = (share + mod) % mod;
        }
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) ans = (ans + dp[i]) % mod;
        return ans;
    }
};
