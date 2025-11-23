class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[3];
        for (int x : nums) {
            int a = dp[0], b = dp[1], c = dp[2];
            if (x % 3 == 0) {
                dp[0] += x;
                if (b > 0) dp[1] += x;
                if (c > 0) dp[2] += x;
            } else if (x % 3 == 1) {
                dp[1] = Math.max(dp[1], a + x);
                dp[2] = Math.max(dp[2], c + x);
                dp[0] = Math.max(dp[0], b + x);
            } else {
                dp[2] = Math.max(dp[2], a + x);
                dp[0] = Math.max(dp[0], c + x);
                dp[1] = Math.max(dp[1], b + x);
            }
        }
        return dp[0];
    }
}