class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts - 1:
            return 1.0
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        windowSum, result = 1.0, 0.0
        for i in range(1, n + 1):
            dp[i] = windowSum / maxPts
            if i < k:
                windowSum += dp[i]
            else:
                result += dp[i]
            if i - maxPts >= 0:
                windowSum -= dp[i - maxPts]
        return result
