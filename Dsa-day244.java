class Solution {
    public int numberOfSubmatrices(char[][] grid){
        int m = grid[0].length;
        int[][] col = new int[2][m];
        int res = 0;
        for (char[] row : grid) {
            int x = 0;
            int y = 0;
            for(int j = 0; j < m; j++){
                if(row[j] == 'X') col[0][j]++;
                else if(row[j] == 'Y') col[1][j]++;
                x += col[0][j];
                y += col[1][j];
                if(x > 0 && x == y) res++;
            }
        }
        return res;
    }
}