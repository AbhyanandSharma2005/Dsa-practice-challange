class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat or not mat[0]:
            return []
        m, n = len(mat), len(mat[0])
        result = []
        for k in range(m + n - 1):
            intermediate = []
            if k < n:
                row, col = 0, k
            else:
                row, col = k - n + 1, n - 1
            while row < m and col >= 0:
                intermediate.append(mat[row][col])
                row += 1
                col -= 1
            if k % 2 == 0:
                result.extend(intermediate[::-1])
            else:
                result.extend(intermediate)
        return result
