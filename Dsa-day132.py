class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        MOD = 10**9 + 7
        
        # dp[i][j][r] = number of ways to reach (i,j) with sum % k == r
        dp = [[[0] * k for _ in range(n)] for _ in range(m)]
        
        # starting point
        dp[0][0][grid[0][0] % k] = 1
        
        # fill first row
        for j in range(1, n):
            for r in range(k):
                new_r = (r + grid[0][j]) % k
                dp[0][j][new_r] = (dp[0][j][new_r] + dp[0][j-1][r]) % MOD
        
        # fill first column
        for i in range(1, m):
            for r in range(k):
                new_r = (r + grid[i][0]) % k
                dp[i][0][new_r] = (dp[i][0][new_r] + dp[i-1][0][r]) % MOD
        
        # fill the rest
        for i in range(1, m):
            for j in range(1, n):
                for r in range(k):
                    new_r = (r + grid[i][j]) % k
                    # from up
                    dp[i][j][new_r] = (dp[i][j][new_r] + dp[i-1][j][r]) % MOD
                    # from left
                    dp[i][j][new_r] = (dp[i][j][new_r] + dp[i][j-1][r]) % MOD
        
        return dp[m-1][n-1][0]