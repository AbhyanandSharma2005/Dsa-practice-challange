class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        # Step 1: Cost to satisfy the overlapping portion of both needs
        common = min(need1, need2)
        total_cost = common * min(costBoth, cost1 + cost2)
        
        # Step 2: Cost to satisfy any remaining single need
        if need1 > need2:
            rem = need1 - need2
            total_cost += rem * min(cost1, costBoth)
        else:
            rem = need2 - need1
            total_cost += rem * min(cost2, costBoth)
            
        return total_cost
