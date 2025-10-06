import java.util.*;

class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[][] vis = new boolean[n][n];
        pq.offer(new int[]{grid[0][0], 0, 0});
        int res = 0;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int t = cur[0], x = cur[1], y = cur[2];
            res = Math.max(res, t);
            if (x == n - 1 && y == n - 1) return res;
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.offer(new int[]{grid[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
}
