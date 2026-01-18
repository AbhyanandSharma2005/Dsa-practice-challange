class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n + 1));
        vector<vector<int>> col(n, vector<int>(m + 1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[j][i + 1] = col[j][i] + grid[i][j];
            }
        }

        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    int target = row[i][j + k] - row[i][j];

                    bool ok = true;
                    for (int r = i; r < i + k && ok; ++r) {
                        if (row[r][j + k] - row[r][j] != target) ok = false;
                    }
                    if (!ok) continue;

                    for (int c = j; c < j + k && ok; ++c) {
                        if (col[c][i + k] - col[c][i] != target) ok = false;
                    }
                    if (!ok) continue;

                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; ++t) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }
                    if (d1 == target && d2 == target) return k;
                }
            }
        }
        return 1;
    }
};