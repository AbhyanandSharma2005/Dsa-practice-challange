class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        from collections import defaultdict
        
        rows = defaultdict(list) 
        cols = defaultdict(list)  
        
        for x, y in buildings:
            rows[x].append(y)
            cols[y].append(x)
        
        for ys in rows.values():
            ys.sort()
        for xs in cols.values():
            xs.sort()
        
        ans = 0
        for x, y in buildings:
            row_ys = rows[x]
            has_left = row_ys[0] < y
            has_right = row_ys[-1] > y
            
            col_xs = cols[y]
            has_above = col_xs[0] < x
            has_below = col_xs[-1] > x
            
            if has_left and has_right and has_above and has_below:
                ans += 1
                
        return ans