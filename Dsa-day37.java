class Solution {
    @FunctionalInterface
    interface IntQuadFunction<R> {
        R apply(int a, int b, int c, int d);
    }

    public int minimumSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        IntQuadFunction<Integer> boundingArea = (r1, c1, r2, c2) -> {
            int minr = n, maxr = -1, minc = m, maxc = -1;
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j] == 1) {
                        if (i < minr) minr = i;
                        if (i > maxr) maxr = i;
                        if (j < minc) minc = j;
                        if (j > maxc) maxc = j;
                    }
                }
            }
            if (maxr == -1) return -1;
            return (maxr - minr + 1) * (maxc - minc + 1);
        };

        int res = Integer.MAX_VALUE;

        for (int c1 = 0; c1 <= m - 3; c1++) {
            for (int c2 = c1 + 1; c2 <= m - 2; c2++) {
                int a1 = boundingArea.apply(0, 0, n - 1, c1);
                int a2 = boundingArea.apply(0, c1 + 1, n - 1, c2);
                int a3 = boundingArea.apply(0, c2 + 1, n - 1, m - 1);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
        }

        for (int r1 = 0; r1 <= n - 3; r1++) {
            for (int r2 = r1 + 1; r2 <= n - 2; r2++) {
                int a1 = boundingArea.apply(0, 0, r1, m - 1);
                int a2 = boundingArea.apply(r1 + 1, 0, r2, m - 1);
                int a3 = boundingArea.apply(r2 + 1, 0, n - 1, m - 1);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
        }

        for (int c = 0; c <= m - 2; c++) {
            for (int r = 0; r <= n - 2; r++) {
                int a1 = boundingArea.apply(0, 0, r, c);
                int a2 = boundingArea.apply(r + 1, 0, n - 1, c);
                int a3 = boundingArea.apply(0, c + 1, n - 1, m - 1);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
            for (int r = 0; r <= n - 2; r++) {
                int a1 = boundingArea.apply(0, c + 1, r, m - 1);
                int a2 = boundingArea.apply(r + 1, c + 1, n - 1, m - 1);
                int a3 = boundingArea.apply(0, 0, n - 1, c);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
        }

        for (int r = 0; r <= n - 2; r++) {
            for (int c = 0; c <= m - 2; c++) {
                int a1 = boundingArea.apply(0, 0, r, c);
                int a2 = boundingArea.apply(0, c + 1, r, m - 1);
                int a3 = boundingArea.apply(r + 1, 0, n - 1, m - 1);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
            for (int c = 0; c <= m - 2; c++) {
                int a1 = boundingArea.apply(r + 1, 0, n - 1, c);
                int a2 = boundingArea.apply(r + 1, c + 1, n - 1, m - 1);
                int a3 = boundingArea.apply(0, 0, r, m - 1);
                if (a1 != -1 && a2 != -1 && a3 != -1) res = Math.min(res, a1 + a2 + a3);
            }
        }

        return res;
    }
}
