class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        wexondrivas = queries
        res = 0
        for l, r in wexondrivas:
            total = 0
            for k in range(1, 16):  
                start = 4 ** (k - 1)
                end = 4**k - 1
                lower = max(l, start)
                upper = min(r, end)
                if lower > upper:
                    continue
                cnt = upper - lower + 1
                total += cnt * k
            ans = (total + 1) // 2
            res += ans
        return res