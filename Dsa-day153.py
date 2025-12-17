from functools import cache

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        
        @cache
        def dp(i: int, rem: int, state: int) -> int:
            if i == n:
                return 0 if state == 0 else float('-inf') 
            
            if state == 0:
                res = dp(i + 1, rem, 0)
                
                if rem > 0:
                    res = max(res, dp(i + 1, rem - 1, 1) - prices[i])
                    
                    res = max(res, dp(i + 1, rem - 1, 2) + prices[i])
                
                return res
            
            if state == 1:
                keep = dp(i + 1, rem, 1)
                sell = dp(i + 1, rem, 0) + prices[i]
                return max(keep, sell)
            
            if state == 2:
                keep = dp(i + 1, rem, 2)
                cover = dp(i + 1, rem, 0) - prices[i]
                return max(keep, cover)
        
        ans = dp(0, k, 0)
        dp.cache_clear()  
        return ans