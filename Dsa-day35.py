class Solution:
    def numSubmat(self, mat):
        m, n = len(mat), len(mat[0])
        heights = [0] * n
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    heights[j] += 1
                else:
                    heights[j] = 0
            for j in range(n):
                h = heights[j]
                k = j
                while k >= 0 and h > 0:
                    h = min(h, heights[k])
                    ans += h
                    k -= 1
        return ans
