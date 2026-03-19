class Solution:
    def val(self, x):
        if x == '.': return 0
        if x == 'X': return 1
        return -1
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        s = set()
        vals = [[(0, False)] * m for _ in range(n)]        
        vals[0][0] = (self.val(grid[0][0]), self.val(grid[0][0]) == 1)
        res = 0
        for i in range(1, m):
            vals[0][i] = (vals[0][i-1][0] + self.val(grid[0][i]), vals[0][i-1][1] or self.val(grid[0][i]) == 1)
        for j in range(1, n):
            vals[j][0] = (vals[j-1][0][0] + self.val(grid[j][0]), vals[j-1][0][1] or self.val(grid[j][0]) == 1)
        for i in range(1, n):
            for j in range(1, m):
                vals[i][j] = (vals[i-1][j][0] + vals[i][j-1][0] - vals[i-1][j-1][0] + self.val(grid[i][j]), 
                vals[i-1][j][1] or vals[i][j-1][1] or (self.val(grid[i][j]) == 1))
        for i in range(n):
            for j in range(m):
                if vals[i][j][0] == 0 and vals[i][j][1] == True:
                    res += 1
        return res