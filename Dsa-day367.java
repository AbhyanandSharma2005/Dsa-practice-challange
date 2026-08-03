class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            int best = Integer.MIN_VALUE;
            int total = 0;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                total += stoneValue[i + k - 1];
                best = Math.max(best, total - dp[i + k]);
            }
            dp[i] = best;
        }

        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
}