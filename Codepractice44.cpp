class Solution {
public:
    vector<vector<bool>>vis;
    int dfs(vector<vector<int>>& grid, long long i, long long j, int k){
        int n=grid.size();
        int m=grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || grid[i][j] == 0) {
            return 0;
        }
        vis[i][j] = true;
        long long sum = 0;
        if (grid[i][j] % k != 0) {
            sum= (sum+grid[i][j]%k)%k;
        }

        sum=(sum+dfs(grid, i + 1, j, k))%k;
        sum=(sum+dfs(grid, i - 1, j, k))%k;
        sum=(sum+dfs(grid, i, j + 1, k))%k;
        sum=(sum+dfs(grid, i, j - 1, k))%k;
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || k==0) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vis.assign(n,vector<bool>(m, false));
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(grid, i, j, k);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}