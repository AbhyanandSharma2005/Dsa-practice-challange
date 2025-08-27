import java.util.*;

class Solution {
    int n, m;
    int[][] grid;
    int[][] dirs = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int[] clockwise = {1,2,3,0};
    int[][][][][] dp;

    int valToIdx(int v) { return v == 1 ? 0 : v == 2 ? 1 : 2; }
    int[] nextIdx = {1,2,1};

    int dfs(int r, int c, int d, int turned, int expIdx) {
        if (r < 0 || r >= n || c < 0 || c >= m || valToIdx(grid[r][c]) != expIdx) return 0;
        if (dp[r][c][d][turned][expIdx] != -1) return dp[r][c][d][turned][expIdx];
        int ans = dfs(r+dirs[d][0], c+dirs[d][1], d, turned, nextIdx[expIdx]);
        if (turned == 0) ans = Math.max(ans, dfs(r+dirs[clockwise[d]][0], c+dirs[clockwise[d]][1], clockwise[d], 1, nextIdx[expIdx]));
        return dp[r][c][d][turned][expIdx] = 1 + ans;
    }

    public int lenOfVDiagonal(int[][] g) {
        grid = g;
        n = grid.length; m = grid[0].length;
        dp = new int[n][m][4][2][3];
        for (int[][][][] a : dp) for (int[][][] b : a) for (int[][] c : b) for (int[] d : c) Arrays.fill(d, -1);
        int ans = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (grid[r][c] == 1)
                    for (int d = 0; d < 4; d++)
                        ans = Math.max(ans, dfs(r, c, d, 0, 0));
        return ans;
    }
}
