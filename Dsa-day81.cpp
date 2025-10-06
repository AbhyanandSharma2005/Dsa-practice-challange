class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});
        int res = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];
            res = max(res, t);
            if (x == n - 1 && y == n - 1) return res;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
};
