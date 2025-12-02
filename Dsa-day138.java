class Solution {
    private static final int MOD = 1_000_000_007;

    public int countTrapezoids(int[][] points) {
        Map<Integer, Long> cnt = new HashMap<>();
        for (int[] p : points) cnt.merge(p[1], 1L, Long::sum);

        long sum = 0, sumSq = 0;
        for (long f : cnt.values()) {
            if (f >= 2) {
                long c = f * (f - 1) / 2;
                sum = (sum + c) % MOD;
                sumSq = (sumSq + c * c % MOD) % MOD;
            }
        }
        long total = sum * sum % MOD;
        long ans = (total - sumSq + MOD) % MOD;
        ans = ans * 500000004L % MOD;  // modular inverse of 2
        return (int) ans;
    }
}