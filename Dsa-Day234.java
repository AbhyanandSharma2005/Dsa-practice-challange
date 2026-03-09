class Solution {

    int MOD = 1000000007;
    int limit;
    int[][][] dp = new int[201][201][2];

    int dfs(int oneLeft, int zeroLeft, int last) {
        if(oneLeft == 0 && zeroLeft == 0) return 1;

        if(dp[oneLeft][zeroLeft][last] != -1)
            return dp[oneLeft][zeroLeft][last];

        long ans = 0;

        if(last == 1) {
            int mx = Math.min(zeroLeft, limit);
            for(int len = 1; len <= mx; len++)
                ans = (ans + dfs(oneLeft, zeroLeft - len, 0)) % MOD;
        } else {
            int mx = Math.min(oneLeft, limit);
            for(int len = 1; len <= mx; len++)
                ans = (ans + dfs(oneLeft - len, zeroLeft, 1)) % MOD;
        }

        return dp[oneLeft][zeroLeft][last] = (int)ans;
    }

    public int numberOfStableArrays(int zero, int one, int lim) {
        limit = lim;

        for(int i=0;i<201;i++)
            for(int j=0;j<201;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k] = -1;

        long ans = dfs(one, zero, 0);
        ans = (ans + dfs(one, zero, 1)) % MOD;

        return (int)ans;
    }
}