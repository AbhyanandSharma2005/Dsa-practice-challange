class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, 0, 0]
        for x in nums:
            a, b, c = dp
            r = x % 3
            if r == 0:
                dp[0] += x
                if b: dp[1] += x
                if c: dp[2] += x
            elif r == 1:
                dp[0] = max(dp[0], b + x)
                dp[1] = max(dp[1], c + x)
                dp[2] = max(dp[2], a + x)
            else:
                dp[0] = max(dp[0], c + x)
                dp[1] = max(dp[1], a + x)
                dp[2] = max(dp[2], b + x)
        return dp[0]