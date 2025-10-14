class Solution:
    def is_strictly_increasing(self, nums: list[int], start: int, k: int) -> bool:
        for i in range(start, start + k - 1):
            if nums[i] >= nums[i+1]:
                return False
        return True

    def hasIncreasingSubarrays(self, nums: list[int], k: int) -> bool:
        n = len(nums)
        if n < 2 * k:
            return False
        
        for a in range(n - 2 * k + 1):
            # Check the first subarray: nums[a...a + k - 1]
            if self.is_strictly_increasing(nums, a, k):
                # Check the second adjacent subarray: nums[a + k...a + 2 * k - 1]
                if self.is_strictly_increasing(nums, a + k, k):
                    return True
        
        return False