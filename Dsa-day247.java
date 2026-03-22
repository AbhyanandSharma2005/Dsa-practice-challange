class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        for (int r = 0; r < 4; r++) {
            if (Arrays.deepEquals(mat, target)) return true;
            mat = rotate(mat);
        }
        return false;
    }
    
    private int[][] rotate(int[][] m) {
        int n = m.length;
        int[][] tmp = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tmp[j][n-1-i] = m[i][j];
        return tmp;
    }
}