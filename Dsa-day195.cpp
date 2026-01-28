#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INF)));
        
        dp[0][0][0] = 0;

        vector<int> vals;
        for (const auto& row : grid) 
            for (int val : row) vals.push_back(val);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto get_idx = [&](int v) {
            return lower_bound(vals.begin(), vals.end(), v) - vals.begin();
        };

        for (int p = 0; p <= k; ++p) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j][p] == INF) continue;

                    if (i + 1 < m) {
                        dp[i + 1][j][p] = min(dp[i + 1][j][p], dp[i][j][p] + grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1][p] = min(dp[i][j + 1][p], dp[i][j][p] + grid[i][j + 1]);
                    }
                }
            }

            if (p < k) {
                vector<int> suffix_min(vals.size(), INF);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[i][j][p] != INF) {
                            int idx = get_idx(grid[i][j]);
                            suffix_min[idx] = min(suffix_min[idx], dp[i][j][p]);
                        }
                    }
                }

                for (int i = (int)vals.size() - 2; i >= 0; --i) {
                    suffix_min[i] = min(suffix_min[i], suffix_min[i + 1]);
                }

                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int idx = get_idx(grid[i][j]);
                        if (suffix_min[idx] != INF) {
                            dp[i][j][p + 1] = min(dp[i][j][p + 1], suffix_min[idx]);
                        }
                    }
                }
            }
        }

        int ans = INF;
        for (int p = 0; p <= k; ++p) {
            ans = min(ans, dp[m - 1][n - 1][p]);
        }
        return ans;
    }
};