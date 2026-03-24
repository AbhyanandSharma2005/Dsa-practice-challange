class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        MOD = 12345
        n, m = len(grid), len(grid[0])
        flat = [grid[i][j] for i in range(n) for j in range(m)]
        total = n * m
        
        prefix = [1] * (total + 1)
        for i in range(total):
            prefix[i + 1] = (prefix[i] * flat[i]) % MOD
        
        suffix = [1] * (total + 1)
        for i in range(total - 1, -1, -1):
            suffix[i] = (suffix[i + 1] * flat[i]) % MOD
        
        result = []
        for i in range(n):
            row = []
            for j in range(m):
                idx = i * m + j
                row.append((prefix[idx] * suffix[idx + 1]) % MOD)
            result.append(row)
        
        return result