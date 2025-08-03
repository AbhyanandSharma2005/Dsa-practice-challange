from typing import List

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        n = len(fruits)
        max_fruits = 0
        left = 0
        current_fruits = 0

        for right in range(n):
            current_fruits += fruits[right][1]
            
            while True:
                if left > right:
                    break
                
                left_pos = fruits[left][0]
                right_pos = fruits[right][0]
                
                dist_to_left = abs(startPos - left_pos)
                dist_to_right = abs(startPos - right_pos)
                
                steps_needed = min(dist_to_left, dist_to_right) + (right_pos - left_pos)
                
                if steps_needed <= k:
                    break
                
                current_fruits -= fruits[left][1]
                left += 1
            
            max_fruits = max(max_fruits, current_fruits)
                
        return max_fruits