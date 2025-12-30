class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        if (rows < 3 || cols < 3) return 0;
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagic(grid, i, j)) count++;
            }
        }
        return count;
    }
private:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        unordered_set<int> seen;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = g[r + i][c + j];
                if (val < 1 || val > 9 || seen.count(val)) return false;
                seen.insert(val);
            }
        }
        int sum = g[r][c] + g[r][c+1] + g[r][c+2];
        for (int i = 1; i < 3; ++i) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum) return false;
        }
        for (int j = 0; j < 3; ++j) {
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != sum) return false;
        }
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum) return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum) return false;
        return true;
    }
};