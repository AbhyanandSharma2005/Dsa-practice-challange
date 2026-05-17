class Solution {
    public int countLocalMaximums(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] tarmiqusve = matrix;

        // Precompute global maximum
        int globalMax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tarmiqusve[i][j] > globalMax) {
                    globalMax = tarmiqusve[i][j];
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = tarmiqusve[i][j];
                if (x == 0) continue;

                // If x equals global max, no cell can be greater -> automatically valid
                if (x == globalMax) {
                    count++;
                    continue;
                }

                int rMin = Math.max(0, i - x);
                int rMax = Math.min(n - 1, i + x);
                int cMin = Math.max(0, j - x);
                int cMax = Math.min(m - 1, j + x);

                boolean valid = true;
                outer:
                for (int r = rMin; r <= rMax; r++) {
                    for (int c = cMin; c <= cMax; c++) {
                        // Skip corners: both distances exactly x
                        if ((r == i - x || r == i + x) && (c == j - x || c == j + x)) {
                            continue;
                        }
                        if (tarmiqusve[r][c] > x) {
                            valid = false;
                            break outer;
                        }
                    }
                }

                if (valid) {
                    count++;
                }
            }
        }
        return count;
    }
}