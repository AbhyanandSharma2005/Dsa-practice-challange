class Solution {
    public long minOperations(int[][] queries) {
        long[] pow4 = new long[20];
        pow4[0] = 1;
        int len = 1;
        while (pow4[len - 1] <= 1_000_000_000L) {
            pow4[len] = pow4[len - 1] * 4;
            len++;
        }

        long ans = 0;

        for (int[] q : queries) {
            long l = q[0], r = q[1];
            long totalOps = 0;

            for (int k = 1; k < len; k++) {
                long left = Math.max(l, pow4[k - 1]);
                long right = Math.min(r, pow4[k] - 1);
                if (left <= right) {
                    long cnt = right - left + 1;
                    totalOps += cnt * k;
                }
            }

            ans += (totalOps + 1) / 2; 
        }

        return ans;
    }
}
