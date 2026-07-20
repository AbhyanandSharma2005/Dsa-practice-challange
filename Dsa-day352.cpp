class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;
        vector<int> flat(total);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                flat[i * n + j] = grid[i][j];
        vector<int> shifted(total);
        for (int i = 0; i < total; i++)
            shifted[(i + k) % total] = flat[i];
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = shifted[i * n + j];
        return res;
    }
};