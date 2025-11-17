class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -1 - k
        for i in range(len(nums)):
            if nums[i] == 1:
                if i - prev <= k:
                    return False
                prev = i
        return True