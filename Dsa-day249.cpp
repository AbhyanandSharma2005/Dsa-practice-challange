class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size(), total = n * m;
        
        vector<long long> flat(total);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                flat[i * m + j] = grid[i][j];
        
        vector<long long> prefix(total + 1, 1), suffix(total + 1, 1);
        for (int i = 0; i < total; i++)
            prefix[i + 1] = (prefix[i] * flat[i]) % MOD;
        for (int i = total - 1; i >= 0; i--)
            suffix[i] = (suffix[i + 1] * flat[i]) % MOD;
        
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                result[i][j] = (prefix[idx] * suffix[idx + 1]) % MOD;
            }
        
        return result;
    }
};