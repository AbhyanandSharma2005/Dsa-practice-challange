class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n, MOD = len(grid), len(grid[0]), 10**9 + 7
        maxDp = [[0]*n for _ in range(m)]
        minDp = [[0]*n for _ in range(m)]
        
        maxDp[0][0] = minDp[0][0] = grid[0][0]
        for i in range(1, m): maxDp[i][0] = minDp[i][0] = maxDp[i-1][0] * grid[i][0]
        for j in range(1, n): maxDp[0][j] = minDp[0][j] = maxDp[0][j-1] * grid[0][j]
        
        for i in range(1, m):
            for j in range(1, n):
                val = grid[i][j]
                if val >= 0:
                    maxDp[i][j] = max(maxDp[i-1][j], maxDp[i][j-1]) * val
                    minDp[i][j] = min(minDp[i-1][j], minDp[i][j-1]) * val
                else:
                    maxDp[i][j] = min(minDp[i-1][j], minDp[i][j-1]) * val
                    minDp[i][j] = max(maxDp[i-1][j], maxDp[i][j-1]) * val
        
        res = maxDp[m-1][n-1]
        return -1 if res < 0 else res % MOD