class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        count = 0
        if rows < 3 or cols < 3:
            return 0
        for i in range(rows - 2):
            for j in range(cols - 2):
                if self.is_magic(grid, i, j):
                    count += 1
        return count
    
    def is_magic(self, g: List[List[int]], r: int, c: int) -> bool:
        seen = set()
        for i in range(3):
            for j in range(3):
                val = g[r + i][c + j]
                if val < 1 or val > 9 or val in seen:
                    return False
                seen.add(val)
        target = g[r][c] + g[r][c+1] + g[r][c+2]
        for i in range(3):
            if g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != target:
                return False
        for j in range(3):
            if g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != target:
                return False
        if g[r][c] + g[r+1][c+1] + g[r+2][c+2] != target:
            return False
        if g[r][c+2] + g[r+1][c+1] + g[r+2][c] != target:
            return False
        return True