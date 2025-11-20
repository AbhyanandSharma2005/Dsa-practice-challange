class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);
        int ans = 0;
        int p1 = -1, p2 = -1;
        for (int[] iv : intervals) {
            int s = iv[0], e = iv[1];
            if (s > p2) {
                ans += 2;
                p1 = e - 1;
                p2 = e;
            } else if (s > p1) {
                ans++;
                p1 = p2;
                p2 = e;
            } else if (e < p2) {
                p1 = Math.max(s, p1);
                p2 = e;
            }
        }
        return ans;
    }
}