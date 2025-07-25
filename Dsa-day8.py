class Solution:
    def maxSum(self, nums: List[int]) -> int:
        sum_nums = 0
        for i in set(nums):
            if i > 0:
                sum_nums += i
        if sum_nums == 0:
            return max(nums)
        return sum_nums
