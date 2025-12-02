class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9 + 7
        from collections import Counter
        cnt = Counter(y for _, y in points)

        total = sq = 0
        for f in cnt.values():
            if f >= 2:
                c = f * (f - 1) // 2
                total = (total + c) % MOD
                sq = (sq + c * c) % MOD

        ans = (total * total % MOD - sq + MOD) % MOD
        ans = ans * 500000004 % MOD  # // 2
        return ans