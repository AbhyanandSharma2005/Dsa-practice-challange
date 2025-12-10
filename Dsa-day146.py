class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        n = len(complexity)
        if n == 1:
            return 1
        c0 = complexity[0]
        for i in range(1, n):
            if complexity[i] <= c0:
                return 0
        MOD = 10**9 + 7
        res = 1
        for i in range(2, n):
            res = res * i % MOD
        return res