class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, ones = 0;
        for (int x : nums) if (x == 1) ones++;
        if (ones > 0) return n - ones;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = Math.min(ans, j - i + n - 1);
                    break;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
