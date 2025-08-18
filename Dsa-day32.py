from typing import List

class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def operate(a: float, b: float, op: str) -> float:
            if op == '+':
                return a + b
            if op == '-':
                return a - b
            if op == '*':
                return a * b
            if op == '/' and abs(b) > 1e-6:  
                return a / b
            return float('inf')  
        
        def backtrack(nums: List[float]) -> bool:
            if len(nums) == 1:
                return abs(nums[0] - 24) < 1e-3
            
            for i in range(len(nums)):
                for j in range(len(nums)):
                    if i == j:
                        continue
                    remaining = [nums[k] for k in range(len(nums)) if k != i and k != j]
                    
                    for op in ['+', '-', '*', '/']:
                        result = operate(nums[i], nums[j], op)
                        if result == float('inf'):
                            continue
                        if backtrack(remaining + [result]):
                            return True
            return False
        
        return backtrack([float(c) for c in cards])
