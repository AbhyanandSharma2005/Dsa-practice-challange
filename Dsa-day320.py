class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left, right = 0, sum(nums)

        for i, j in enumerate(nums):
            ans = left - (right - j)
            nums[i] = abs(ans)

            right -= j
            left += j

        return nums