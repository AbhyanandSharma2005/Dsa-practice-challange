class Solution {
    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        long ans = 1;
        int length = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++length;
            } else {
                length = 1;
            }
            ans += length;
        }
        return ans;
    }
}