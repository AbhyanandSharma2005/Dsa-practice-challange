from sortedcontainers import SortedList

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k < 0:
            return 0
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1
        sl = SortedList()
        l = 0
        total = 1  
        
        for i, num in enumerate(nums):
            sl.add(num)
            while sl and sl[-1] - sl[0] > k:
                total = (total - dp[l] + mod) % mod
                sl.remove(nums[l])
                l += 1
            dp[i + 1] = total
            total = (total + dp[i + 1]) % mod
        
        return dp[n]