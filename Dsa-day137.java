class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long sum = 0;
        for (int b : batteries) sum += b;
        Arrays.sort(batteries);
        
        int m = batteries.length;
        for (int i = m - 1; i >= 0; i--) {
            if (batteries[i] <= sum / n) break;
            sum -= batteries[i];
            n--;
        }
        return sum / n;
    }
}