class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int total = m * n;
        k %= total;
        int[] flat = new int[total];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                flat[i * n + j] = grid[i][j];
        int[] shifted = new int[total];
        for (int i = 0; i < total; i++)
            shifted[(i + k) % total] = flat[i];
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++)
                row.add(shifted[i * n + j]);
            res.add(row);
        }
        return res;
    }
}