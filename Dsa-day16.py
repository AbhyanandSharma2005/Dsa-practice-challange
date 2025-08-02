from collections import Counter

class Solution:
    def minCost(self, basket1: list[int], basket2: list[int]) -> int:
        combined_freq = Counter(basket1)
        combined_freq.update(basket2)

        min_cost = float('inf')
        for x in basket1:
            min_cost = min(min_cost, x)
        for x in basket2:
            min_cost = min(min_cost, x)

        misplaced = []
        freq1 = Counter(basket1)

        for fruit, total_count in combined_freq.items():
            if total_count % 2 != 0:
                return -1
            
            target_count = total_count // 2
            count1 = freq1.get(fruit, 0)
            
            if count1 > target_count:
                for _ in range(count1 - target_count):
                    misplaced.append(fruit)
            elif count1 < target_count:
                for _ in range(target_count - count1):
                    misplaced.append(fruit)
        
        misplaced.sort()
        
        total_cost = 0
        k = len(misplaced) // 2
        
        for i in range(k):
            total_cost += min(misplaced[i], min_cost * 2)
            
        return total_cost