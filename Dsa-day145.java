class Solution {
    public int specialTriplets(int[] nums) {
        final int MOD = 1000000007;
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        for (int x : nums) {
            right.put(x, right.getOrDefault(x, 0) + 1);
        }
        long ans = 0;
        for (int x : nums) {
            right.put(x, right.get(x) - 1);
            long target = 2L * x;
            if (target > Integer.MAX_VALUE) {
                left.put(x, left.getOrDefault(x, 0) + 1);
                continue;
            }
            long cntLeft = left.getOrDefault((int)target, 0);
            long cntRight = right.getOrDefault((int)target, 0);
            ans = (ans + cntLeft * cntRight % MOD) % MOD;
            left.put(x, left.getOrDefault(x, 0) + 1);
        }
        return (int) ans;
    }
}