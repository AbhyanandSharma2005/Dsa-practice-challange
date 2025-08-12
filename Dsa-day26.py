class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        """
        Calculates the number of ways n can be expressed as the sum of the x-th power
        of unique positive integers.
        """
        MOD = 10**9 + 7

        dp = [0] * (n + 1)
        
        dp[0] = 1

        num = 1
        while True:
            p = num ** x
            
            if p > n:
                break

            for j in range(n, p - 1, -1):
                dp[j] = (dp[j] + dp[j - p]) % MOD
            
            num += 1

        return dp[n]