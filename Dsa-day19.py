from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        used_baskets = [False] * n
        unplaced_fruits_count = 0
        
        for i in range(n):
            fruit_size = fruits[i]
            placed = False
            for j in range(n):
                if not used_baskets[j] and baskets[j] >= fruit_size:
                    used_baskets[j] = True
                    placed = True
                    break
            
            if not placed:
                unplaced_fruits_count += 1
                
        return unplaced_fruits_count