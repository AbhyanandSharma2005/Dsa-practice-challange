class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] heights = new int[n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) heights[j]++;
                else heights[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                int h = heights[j];
                for (int k = j; k >= 0 && h > 0; k--) {
                    h = Math.min(h, heights[k]);
                    ans += h;
                }
            }
        }
        return ans;
    }
}
