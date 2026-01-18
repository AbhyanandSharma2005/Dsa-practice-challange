class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] rowSum = new int[m][n + 1];
        int[][] colSum = new int[n][m + 1];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }

        for (int k = Math.min(m, n); k > 1; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    int target = rowSum[i][j + k] - rowSum[i][j];

                    boolean valid = true;
                    for (int r = i; r < i + k; r++) {
                        if (rowSum[r][j + k] - rowSum[r][j] != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    for (int c = j; c < j + k; c++) {
                        if (colSum[c][i + k] - colSum[c][i] != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    int diag1 = 0, diag2 = 0;
                    for (int t = 0; t < k; t++) {
                        diag1 += grid[i + t][j + t];
                        diag2 += grid[i + t][j + k - 1 - t];
                    }
                    if (diag1 == target && diag2 == target) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
}