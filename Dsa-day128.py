class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            r = x % 3
            ans += min(r, 3 - r)
        return ans