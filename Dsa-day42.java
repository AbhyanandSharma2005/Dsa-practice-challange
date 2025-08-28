class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        
        for (int start = 0; start < n; start++) {
            List<Integer> d1 = new ArrayList<>(), d2 = new ArrayList<>();
            int i = start, j = 0;
            while (i < n && j < n) d1.add(grid[i++][j++]);
            d1.sort(Collections.reverseOrder());
            i = start; j = 0; int idx = 0;
            while (i < n && j < n) grid[i++][j++] = d1.get(idx++);
            
            if (start > 0) {
                i = 0; j = start;
                while (i < n && j < n) d2.add(grid[i++][j++]);
                Collections.sort(d2);
                i = 0; j = start; idx = 0;
                while (i < n && j < n) grid[i++][j++] = d2.get(idx++);
            }
        }
        return grid;
    }
}
