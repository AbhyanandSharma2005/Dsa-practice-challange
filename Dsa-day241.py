class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])

        def valid(i, j, x):
            if j - x < 0 or j + x >= n or i + 2 * x >= m:
                return False
            return True

        def collect(i, j, x):
            if x == 0:
                return grid[i][j]
            res = grid[i][j] + grid[i + 2 * x][j]
            c = 1
            for r in range(i + 2 * x - 1, i + x, -1):
                res += grid[r][j + c]
                res += grid[r][j - c]
                c += 1
            c = 1
            for r in range(i + 1, i + x + 1):
                res += grid[r][j + c]
                res += grid[r][j - c]
                c += 1
            return res

        res = [0, 0, 0]
        for i in range(m):
            for j in range(n):
                for x in range(n):
                    if not valid(i, j, x):
                        break
                    r = collect(i, j, x)
                    if r in res:
                        continue
                    elif r > res[0]:
                        res[1], res[2] = res[0], res[1]
                        res[0] = r
                    elif r > res[1]:
                        res[2] = res[1]
                        res[1] = r
                    elif r > res[2]:
                        res[2] = r

        out = []
        for r in res:
            if r != 0:
                out.append(r)
        return out