class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        powers = []
        bit = 0
        while n:
            if n & 1:
                powers.append(1 << bit)
            bit += 1
            n >>= 1
        prefix = [1] * (len(powers) + 1)
        for i in range(len(powers)):
            prefix[i+1] = (prefix[i] * powers[i]) % MOD
        ans = []
        for l, r in queries:
            ans.append(prefix[r+1] * pow(prefix[l], MOD-2, MOD) % MOD)
        return ans
