class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count = 0
        clean = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                clean.append(nums[i])

        for i in range(1, len(clean) - 1):
            if clean[i] > clean[i - 1] and clean[i] > clean[i + 1]:
                count += 1  
            elif clean[i] < clean[i - 1] and clean[i] < clean[i + 1]:
                count += 1  
        return count
