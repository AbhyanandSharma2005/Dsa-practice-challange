class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] zeros = new int[n];
        
        for (int i = 0; i < n; i++) {
            int count = 0, j = n - 1;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            zeros[i] = count;
        }

        int operations = 0;
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int rowToSwap = -1;
            
            for (int j = i; j < n; j++) {
                if (zeros[j] >= required) {
                    rowToSwap = j;
                    break;
                }
            }
            
            if (rowToSwap == -1) return -1;
            
            operations += (rowToSwap - i);
            while (rowToSwap > i) {
                int temp = zeros[rowToSwap];
                zeros[rowToSwap] = zeros[rowToSwap - 1];
                zeros[rowToSwap - 1] = temp;
                rowToSwap--;
            }
        }
        return operations;
    }
}