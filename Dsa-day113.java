class Solution {
    public long maxPower(int[] stations, int r, int k) {
        int n = stations.length;
        long[] power = new long[n];
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stations[i];
        for (int i = 0; i < n; i++) {
            int left = Math.max(0, i - r), right = Math.min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }
        long left = 0, right = prefix[n] + k, ans = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (can(mid, power, r, k)) {
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return ans;
    }

    private boolean can(long mid, long[] power, int r, long k) {
        int n = power.length;
        long[] added = new long[n + 1];
        long totalAdd = 0, used = 0;
        for (int i = 0; i < n; i++) {
            totalAdd += added[i];
            if (power[i] + totalAdd < mid) {
                long need = mid - (power[i] + totalAdd);
                if (used + need > k) return false;
                used += need;
                totalAdd += need;
                if (i + 2 * r + 1 < n) added[i + 2 * r + 1] -= need;
            }
        }
        return true;
    }
}
