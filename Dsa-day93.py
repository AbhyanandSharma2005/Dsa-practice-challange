class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        prev = -float('inf')
        count = 0
        for x in nums:
            low, high = x - k, x + k
            val = max(prev + 1, low)
            if val <= high:
                count += 1
                prev = val
        return count
