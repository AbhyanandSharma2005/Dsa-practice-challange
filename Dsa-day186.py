from typing import List

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        if not mat or not mat[0]:
            return 0
            
        m, n = len(mat), len(mat[0])
        
        prefix = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix[i][j] = (prefix[i-1][j] + prefix[i][j-1] 
                              - prefix[i-1][j-1] + mat[i-1][j-1])
        
        def get_sum(r1, c1, r2, c2):
            return (prefix[r2+1][c2+1] - prefix[r2+1][c1] 
                  - prefix[r1][c2+1] + prefix[r1][c1])
        
        left, right = 0, min(m, n)
        ans = 0
        
        while left <= right:
            mid = (left + right) // 2
            found = False
            
            for i in range(m - mid + 1):
                for j in range(n - mid + 1):
                    s = get_sum(i, j, i + mid - 1, j + mid - 1)
                    if s <= threshold:
                        found = True
                        break
                if found:
                    break
                    
            if found:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
                
        return ans