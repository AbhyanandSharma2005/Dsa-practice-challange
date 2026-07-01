class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] dist = new int[n][n];
        for (int[] row : dist) Arrays.fill(row, -1);
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid.get(i).get(j) == 1) {
                    dist[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] d : dirs) {
                int ni = cur[0] + d[0], nj = cur[1] + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[cur[0]][cur[1]] + 1;
                    q.offer(new int[]{ni, nj});
                }
            }
        }
        int[][] safe = new int[n][n];
        for (int[] row : safe) Arrays.fill(row, -1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[2] - a[2]);
        pq.offer(new int[]{0, 0, dist[0][0]});
        safe[0][0] = dist[0][0];
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int r = cur[0], c = cur[1], s = cur[2];
            if (s < safe[r][c]) continue;
            if (r == n - 1 && c == n - 1) return s;
            for (int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int ns = Math.min(s, dist[nr][nc]);
                    if (ns > safe[nr][nc]) {
                        safe[nr][nc] = ns;
                        pq.offer(new int[]{nr, nc, ns});
                    }
                }
            }
        }
        return safe[n - 1][n - 1];
    }
}