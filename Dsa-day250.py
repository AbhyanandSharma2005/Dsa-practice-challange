class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = sum(sum(row) for row in grid)
        if total % 2 != 0:
            return False
        half = total // 2
        
        prefix = 0
        for i in range(len(grid) - 1):
            prefix += sum(grid[i])
            if prefix == half:
                return True
        
        prefix = 0
        for j in range(len(grid[0]) - 1):
            prefix += sum(grid[i][j] for i in range(len(grid)))
            if prefix == half:
                return True
        
        return False