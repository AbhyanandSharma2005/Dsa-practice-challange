class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        if not strs:
            return 0
        rows, cols = len(strs), len(strs[0])
        count = 0
        
        for j in range(cols):
            for i in range(1, rows):
                if strs[i][j] < strs[i-1][j]:
                    count += 1
                    break
        return count