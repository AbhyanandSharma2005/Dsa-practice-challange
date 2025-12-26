class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        prefixY = [0] * (n + 1)
        for i in range(n):
            prefixY[i + 1] = prefixY[i] + (1 if customers[i] == 'Y' else 0)
        
        min_penalty = float('inf')
        best_hour = 0
        total_y = prefixY[n]
        
        for j in range(n + 1):
            open_no_cust = j - prefixY[j]
            closed_with_cust = total_y - prefixY[j]
            penalty = open_no_cust + closed_with_cust
            
            if penalty < min_penalty:
                min_penalty = penalty
                best_hour = j
        
        return best_hour