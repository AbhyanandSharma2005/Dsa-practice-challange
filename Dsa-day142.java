class Solution {
    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        if (k < 0) return 0;
        final int MOD = 1_000_000_007;
        long[] dp = new long[n + 1];
        dp[0] = 1L;

        TreeMap<Integer, Integer> window = new TreeMap<>();
        int left = 0;
        long total = 1L;                    

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            window.put(val, window.getOrDefault(val, 0) + 1);

            while (!window.isEmpty() && window.lastKey() - window.firstKey() > k) {
                total = (total - dp[left] + MOD) % MOD;

                int leftVal = nums[left];
                int cnt = window.get(leftVal);
                if (cnt == 1) {
                    window.remove(leftVal);
                } else {
                    window.put(leftVal, cnt - 1);
                }
                left++;
            }

            dp[i + 1] = total;
            total = (total + dp[i + 1]) % MOD;
        }

        return (int) dp[n];
    }
}