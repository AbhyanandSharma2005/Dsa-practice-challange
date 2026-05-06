class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length;
        int n = boxGrid[0].length;
        
        for (int row = 0; row < m; row++) {
            int emptyPos = n - 1;
            for (int col = n - 1; col >= 0; col--) {
                if (boxGrid[row][col] == '*') {
                    emptyPos = col - 1;
                } else if (boxGrid[row][col] == '#') {
                    boxGrid[row][col] = '.';
                    boxGrid[row][emptyPos] = '#';
                    emptyPos--;
                }
            }
        }
        
        char[][] result = new char[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return result;
    }
}