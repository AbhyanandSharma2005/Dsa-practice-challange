class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m = len(grid) 
        n = len(grid[0])  
        
        row_count = [0] * m
        col_count = [0] * n
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    row_count[i] += 1
                    col_count[j] += 1
        
        connected_servers = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (row_count[i] > 1 or col_count[j] > 1):
                    connected_servers += 1
        
        return connected_servers