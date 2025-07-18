from heapq import heappush, heappop, heapify
from typing import List

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) // 3
        
        left_sum = sum(nums[:n])
        max_heap = [-num for num in nums[:n]] 
        heapify(max_heap)
        left_sums = [left_sum]
        
        for i in range(n, 2 * n):
            heappush(max_heap, -nums[i])
            left_sum += nums[i] + heappop(max_heap) 
            left_sums.append(left_sum)

        right_sum = sum(nums[2 * n:])
        min_heap = nums[2 * n:]
        heapify(min_heap)
        right_sums = [right_sum]
        
        for i in range(2 * n - 1, n - 1, -1):
            heappush(min_heap, nums[i])
            right_sum += nums[i] - heappop(min_heap)
            right_sums.append(right_sum)

        right_sums = right_sums[::-1]  

        min_diff = float('inf')
        for i in range(n + 1):
            diff = left_sums[i] - right_sums[i]
            min_diff = min(min_diff, diff)

        return min_diff
