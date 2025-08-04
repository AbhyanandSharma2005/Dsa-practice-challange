from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        if n <= 2:
            return n

        fruit_count = defaultdict(int)
        max_fruits = 0
        window_start = 0

        for window_end in range(n):
            fruit_count[fruits[window_end]] += 1

            while len(fruit_count) > 2:
                left_fruit = fruits[window_start]
                fruit_count[left_fruit] -= 1
                if fruit_count[left_fruit] == 0:
                    del fruit_count[left_fruit]
                window_start += 1
            
            max_fruits = max(max_fruits, window_end - window_start + 1)
        
        return max_fruits