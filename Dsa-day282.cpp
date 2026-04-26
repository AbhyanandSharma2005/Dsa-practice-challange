class Solution {
public:
    int m, n;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int r, int c, int prevR, int prevC, char ch) {
        
        if (visited[r][c]) return true;  // cycle found!
        visited[r][c] = true;
        
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            
            // Skip out of bounds
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            // Skip different characters
            if (grid[nr][nc] != ch) continue;
            // Skip the cell we just came from
            if (nr == prevR && nc == prevC) continue;
            
            if (dfs(grid, visited, nr, nc, r, c, ch))
                return true;
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j])
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
        
        return false;
    }
};