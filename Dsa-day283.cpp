class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<pair<int, int>>> directions = {
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        };
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            for (auto [dr, dc] : directions[grid[r][c] - 1]) {
                int nr = r + dr, nc = c + dc;
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    for (auto [bdr, bdc] : directions[grid[nr][nc] - 1]) {
                        if (nr + bdr == r && nc + bdc == c) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            break;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};