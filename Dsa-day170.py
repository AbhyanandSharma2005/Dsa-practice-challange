class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        
        # Initial state: 6 patterns each for Type A and Type B
        dpA = 6  # ABA patterns
        dpB = 6  # ABC patterns
        
        # Build up row by row
        for i in range(2, n + 1):
            new_dpA = (3 * dpA + 2 * dpB) % MOD
            new_dpB = (2 * dpA + 2 * dpB) % MOD
            
            dpA = new_dpA
            dpB = new_dpB
        
        return (dpA + dpB) % MOD