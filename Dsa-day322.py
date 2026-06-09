class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        # mini = nums[0]
        # maxi = nums[0]
        # for i in range(len(nums)):
        #     maxi = max(maxi, nums[i])
        #     mini = min(mini, nums[i])
        
        # return (maxi - mini) * k
        
        return (max(nums) - min(nums)) * k