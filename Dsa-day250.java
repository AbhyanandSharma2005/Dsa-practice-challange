class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        long total = 0;
        for (int[] row : grid)
            for (int val : row)
                total += val;
        
        if (total % 2 != 0) return false;
        long half = total / 2;
        
        long prefix = 0;
        for (int i = 0; i < grid.length - 1; i++) {
            for (int val : grid[i]) prefix += val;
            if (prefix == half) return true;
        }
        
        prefix = 0;
        for (int j = 0; j < grid[0].length - 1; j++) {
            for (int i = 0; i < grid.length; i++) prefix += grid[i][j];
            if (prefix == half) return true;
        }
        
        return false;
    }
}