class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int x : nums) {
            vector<int> temp = dp;
            int r = x % 3;
            if (r == 0) {
                if (temp[0] > 0) dp[0] += x;
                if (temp[1] > 0) dp[1] += x;
                if (temp[2] > 0) dp[2] += x;
            } else if (r == 1) {
                dp[0] = max(dp[0], temp[1] + x);
                dp[1] = max(dp[1], temp[2] + x);
                dp[2] = max(dp[2], temp[0] + x);
            } else {
                dp[0] = max(dp[0], temp[2] + x);
                dp[1] = max(dp[1], temp[0] + x);
                dp[2] = max(dp[2], temp[1] + x);
            }
        }
        return dp[0];
    }
};