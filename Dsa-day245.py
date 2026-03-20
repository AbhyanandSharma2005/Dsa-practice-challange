from typing import List

class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        result = [[0] * (n - k + 1) for _ in range(m - k + 1)]

        for i in range(m - k + 1):
            for j in range(n - k + 1):

                elements = []
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        elements.append(grid[x][y])

                unique = sorted(set(elements))

                if len(unique) < 2:
                    result[i][j] = 0
                    continue

                min_diff = float('inf')

                for t in range(1, len(unique)):
                    diff = unique[t] - unique[t - 1]
                    if diff < min_diff:
                        min_diff = diff

                result[i][j] = min_diff

        return result