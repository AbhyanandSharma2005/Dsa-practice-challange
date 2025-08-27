from functools import lru_cache
from typing import List

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dirs = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
        clockwise = [1, 2, 3, 0]  

        @lru_cache(None)
        def dfs(r, c, d, turned, expected):
            if not (0 <= r < n and 0 <= c < m) or grid[r][c] != expected:
                return 0

            if expected == 1:
                next_val = 2
            elif expected == 2:
                next_val = 0
            else:
                next_val = 2

            dr, dc = dirs[d]
            res = dfs(r + dr, c + dc, d, turned, next_val)

            if not turned:
                nd = clockwise[d]
                dr2, dc2 = dirs[nd]
                res = max(res, dfs(r + dr2, c + dc2, nd, 1, next_val))

            return 1 + res

        ans = 0
        for r in range(n):
            for c in range(m):
                if grid[r][c] == 1: 
                    for d in range(4):  
                        ans = max(ans, dfs(r, c, d, 0, 1))
        return ans