class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff = [[0] * (n + 1) for _ in range(n + 1)]
        
        for r1, c1, r2, c2 in queries:
            diff[r1][c1] += 1
            if r2 + 1 < n:
                diff[r2 + 1][c1] -= 1
            if c2 + 1 < n:
                diff[r1][c2 + 1] -= 1
            if r2 + 1 < n and c2 + 1 < n:
                diff[r2 + 1][c2 + 1] += 1
        
        mat = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i > 0:
                    diff[i][j] += diff[i-1][j]
                if j > 0:
                    diff[i][j] += diff[i][j-1]
                if i > 0 and j > 0:
                    diff[i][j] -= diff[i-1][j-1]
                mat[i][j] = diff[i][j]
        
        return mat