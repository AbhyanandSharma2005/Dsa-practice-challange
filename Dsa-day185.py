from typing import List

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
            
        m, n = len(grid), len(grid[0])
        
        # row[i][j+1] = sum of grid[i][0..j]
        row = [[0] * (n + 1) for _ in range(m)]
        
        # col[j][i+1] = sum of grid[0..i][j]
        col = [[0] * (m + 1) for _ in range(n)]
        
        for i in range(m):
            for j in range(n):
                row[i][j + 1] = row[i][j] + grid[i][j]
                col[j][i + 1] = col[j][i] + grid[i][j]
        
        def row_sum(r, c1, c2):
            return row[r][c2 + 1] - row[r][c1]
            
        def col_sum(c, r1, r2):
            return col[c][r2 + 1] - col[c][r1]
        
        for k in range(min(m, n), 1, -1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    target = row_sum(i, j, j + k - 1)
                    
                    # Check all rows
                    valid = True
                    for r in range(i, i + k):
                        if row_sum(r, j, j + k - 1) != target:
                            valid = False
                            break
                    if not valid:
                        continue
                        
                    # Check all columns
                    for c in range(j, j + k):
                        if col_sum(c, i, i + k - 1) != target:
                            valid = False
                            break
                    if not valid:
                        continue
                        
                    # Check both diagonals
                    diag1 = diag2 = 0
                    for t in range(k):
                        diag1 += grid[i + t][j + t]
                        diag2 += grid[i + t][j + k - 1 - t]
                        
                    if diag1 == target and diag2 == target:
                        return k
        
        return 1