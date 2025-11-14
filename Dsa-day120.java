class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int[n + 1][n + 1];
        
        for (int[] q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1]++;
            if (r2 + 1 < n) diff[r2 + 1][c1]--;
            if (c2 + 1 < n) diff[r1][c2 + 1]--;
            if (r2 + 1 < n && c2 + 1 < n) diff[r2 + 1][c2 + 1]++;
        }
        
        int[][] mat = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) diff[i][j] += diff[i-1][j];
                if (j > 0) diff[i][j] += diff[i][j-1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
                mat[i][j] = diff[i][j];
            }
        }
        return mat;
    }
}