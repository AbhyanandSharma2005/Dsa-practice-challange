#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dirs[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
        int clockwise[4] = {1,2,3,0};
        auto valToIdx = [&](int v) { return v == 1 ? 0 : v == 2 ? 1 : 2; };
        int nextIdx[3] = {1,2,1};
        static int dp[500][500][4][2][3];
        memset(dp, -1, sizeof(dp));
        function<int(int,int,int,int,int)> dfs = [&](int r, int c, int d, int turned, int expIdx) -> int {
            if (r < 0 || r >= n || c < 0 || c >= m || valToIdx(grid[r][c]) != expIdx) return 0;
            int &res = dp[r][c][d][turned][expIdx];
            if (res != -1) return res;
            int ans = dfs(r+dirs[d][0], c+dirs[d][1], d, turned, nextIdx[expIdx]);
            if (!turned) ans = max(ans, dfs(r+dirs[clockwise[d]][0], c+dirs[clockwise[d]][1], clockwise[d], 1, nextIdx[expIdx]));
            return res = 1 + ans;
        };
        int answer = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (grid[r][c] == 1)
                    for (int d = 0; d < 4; d++)
                        answer = max(answer, dfs(r, c, d, 0, 0));
        return answer;
    }
};