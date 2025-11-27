class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        
        ans = -10**18
        mod_min = [10**18] * k
        
        for i in range(n + 1):
            r = i % k
            if mod_min[r] != 10**18:
                ans = max(ans, prefix[i] - mod_min[r])
            mod_min[r] = min(mod_min[r], prefix[i])
        
        return ans