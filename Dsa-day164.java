class Solution {
    public int countNegatives(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        int m = grid.length, n = grid[0].length;
        int count = 0;
        for (int[] row : grid) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            count += n - left;
        }
        return count;
    }
}