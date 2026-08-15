class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        total = 0
        n = len(nums)
        hasNonZero = False
        for num in nums:
            total ^= num
            if num > 0:
                hasNonZero = True
        if total != 0:
            return n
        if hasNonZero:
            return n - 1
        return 0