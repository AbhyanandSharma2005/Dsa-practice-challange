from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        def is_non_decreasing(arr, length):
            for i in range(1, length):
                if arr[i] < arr[i - 1]:
                    return False
            return True
        
        ans = 0
        n = len(nums)
        arr = nums[:]  # work on a copy to avoid modifying input
        
        while not is_non_decreasing(arr, n):
            ans += 1
            min_sum = float('inf')
            pos = -1
            for i in range(1, n):
                current_sum = arr[i - 1] + arr[i]
                if current_sum < min_sum:
                    min_sum = current_sum
                    pos = i
            arr[pos - 1] = min_sum
            for i in range(pos, n - 1):
                arr[i] = arr[i + 1]
            n -= 1
        
        return ans