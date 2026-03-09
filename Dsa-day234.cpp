class Solution {
public:
    int M = 1000000007;
    int limit;
    int dp[201][201][2];

    int dfs(int oneLeft, int zeroLeft, int last) {
        if(oneLeft == 0 && zeroLeft == 0) return 1;

        int &res = dp[oneLeft][zeroLeft][last];
        if(res != -1) return res;

        long long ans = 0;

        if(last) {
            int mx = zeroLeft < limit ? zeroLeft : limit;
            for(int len = 1; len <= mx; len++)
                ans = (ans + dfs(oneLeft, zeroLeft - len, 0)) % M;
        } else {
            int mx = oneLeft < limit ? oneLeft : limit;
            for(int len = 1; len <= mx; len++)
                ans = (ans + dfs(oneLeft - len, zeroLeft, 1)) % M;
        }

        return res = ans;
    }

    int numberOfStableArrays(int zero, int one, int lim) {
        limit = lim;
        memset(dp, -1, sizeof(dp));
        long long ans = dfs(one, zero, 0);
        ans = (ans + dfs(one, zero, 1)) % M;
        return ans;
    }
};