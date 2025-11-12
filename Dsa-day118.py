class Solution:
    def minOperations(self, nums: List[int]) -> int:
        from math import gcd
        n = len(nums)
        ones = nums.count(1)
        if ones:
            return n - ones
        ans = float('inf')
        for i in range(n):
            g = nums[i]
            for j in range(i + 1, n):
                g = gcd(g, nums[j])
                if g == 1:
                    ans = min(ans, j - i + n - 1)
                    break
        return -1 if ans == float('inf') else ans
