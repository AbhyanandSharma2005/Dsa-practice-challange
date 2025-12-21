class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, m = len(strs), len(strs[0])
        delete_count = 0
        is_sorted = [False] * (n - 1)  

        for col in range(m):
            remove_column = False
            for row in range(1, n):
                if not is_sorted[row - 1] and strs[row][col] < strs[row - 1][col]:
                    remove_column = True
                    break
            
            if remove_column:
                delete_count += 1
            else:
                for row in range(1, n):
                    if strs[row][col] > strs[row - 1][col]:
                        is_sorted[row - 1] = True

        return delete_count