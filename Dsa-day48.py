import collections

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        
        points.sort(key=lambda p: (p[0], -p[1]))
        
        n = len(points)
        count = 0
        
        for i in range(n):
            for j in range(i + 1, n):
                x_a, y_a = points[i]
                x_b, y_b = points[j]
                
                if y_a >= y_b:
                    is_valid = True
                    for k in range(i + 1, j):
                        x_c, y_c = points[k]
                        
                        if y_b <= y_c <= y_a:
                            is_valid = False
                            break
                    
                    if is_valid:
                        count += 1
                        
        return count