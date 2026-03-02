class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        trailing_zeros = []
        for row in grid:
            last_one = -1
            for idx in range(n - 1, -1, -1):
                if row[idx] == 1:
                    last_one = idx
                    break
            trailing_zeros.append(n - 1 - last_one)
            
        swaps = 0
        for i in range(n):
            target = n - 1 - i
            
            for j in range(i, n):
                if trailing_zeros[j] >= target:
                    swaps += (j - i)
                    
                    row_data = trailing_zeros.pop(j)
                    trailing_zeros.insert(i, row_data)
                    break
            else:
                return -1
                
        return swaps