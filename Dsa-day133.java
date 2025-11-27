class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long ans = Long.MIN_VALUE / 2;
        long[] modMin = new long[k];
        Arrays.fill(modMin, Long.MAX_VALUE / 2);
        
        for (int i = 0; i <= n; ++i) {
            int r = i % k;
            if (modMin[r] != Long.MAX_VALUE / 2) {
                ans = Math.max(ans, prefix[i] - modMin[r]);
            }
            modMin[r] = Math.min(modMin[r], prefix[i]);
        }
        
        return ans;
    }
}