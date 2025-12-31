class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            
            queue<pair<int, int>> q;
            for (int c = 0; c < col; c++) {
                if (grid[0][c] == 0) {
                    q.push({0, c});
                    grid[0][c] = -1;
                }
            }
            
            int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                if (r == row - 1) return true;
                for (auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                        grid[nr][nc] = -1;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };
        
        int left = 0, right = cells.size(), result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};