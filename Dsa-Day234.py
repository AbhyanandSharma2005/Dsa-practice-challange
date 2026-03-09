class Solution:

    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7

        from functools import lru_cache

        @lru_cache(None)
        def dfs(oneLeft, zeroLeft, last):

            if oneLeft == 0 and zeroLeft == 0:
                return 1

            ans = 0

            if last == 1:
                mx = min(zeroLeft, limit)
                for l in range(1, mx+1):
                    ans = (ans + dfs(oneLeft, zeroLeft-l, 0)) % MOD
            else:
                mx = min(oneLeft, limit)
                for l in range(1, mx+1):
                    ans = (ans + dfs(oneLeft-l, zeroLeft, 1)) % MOD

            return ans

        return (dfs(one, zero, 0) + dfs(one, zero, 1)) % MOD