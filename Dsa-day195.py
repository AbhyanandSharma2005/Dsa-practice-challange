class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        max_val = max(max(row) for row in grid)
        
        teleport_cost = [float('inf')] * (max_val + 2)
        
        for teleports_used in range(k + 1):
            value_min_cost = [float('inf')] * (max_val + 1)
            col_cost = [float('inf')] * (n + 1)
            
            col_cost[1] = -grid[0][0]
            
            for row in grid:
                for j, cell_val in enumerate(row):
                    cost = min(col_cost[j], col_cost[j + 1])
                    cost += cell_val
                    cost = min(cost, teleport_cost[cell_val])
                    
                    col_cost[j + 1] = cost
                    value_min_cost[cell_val] = min(value_min_cost[cell_val], col_cost[j + 1])
            
            prev_teleport = teleport_cost.copy()
            for i in range(max_val, -1, -1):
                teleport_cost[i] = min(value_min_cost[i], teleport_cost[i + 1])
            
            if teleport_cost == prev_teleport:
                break
        
        return col_cost[n]