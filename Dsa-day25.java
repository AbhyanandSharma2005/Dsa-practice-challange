class Solution {
    public int[] productQueries(int n, int[][] queries) {
        int MOD = 1_000_000_007;
        List<Integer> powers = new ArrayList<>();
        int bit = 0;
        int temp = n;
        while (temp > 0) {
            if ((temp & 1) == 1) powers.add(1 << bit);
            bit++;
            temp >>= 1;
        }
        long[] prefix = new long[powers.size() + 1];
        prefix[0] = 1;
        for (int i = 0; i < powers.size(); i++) {
            prefix[i+1] = (prefix[i] * powers.get(i)) % MOD;
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0], r = queries[i][1];
            long prod = prefix[r+1] * modPow(prefix[l], MOD - 2, MOD) % MOD;
            ans[i] = (int) prod;
        }
        return ans;
    }
    private long modPow(long a, long b, int mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
}
