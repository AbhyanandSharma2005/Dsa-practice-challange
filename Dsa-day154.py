class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        total = sum(a*b for a,b in zip(prices,strategy))
        p1,p2,ans = 0,0,total

        f = lambda i,p1: strategy[i]*prices[i] if p1 == 1 else (1-strategy[i])*prices[i]
    
        for i,j in zip(range(n),range(k//2,n)):                
            p1 += f(i,1)
            p2 += f(j,2)
            if j >= k-1:
                ans = max(ans,total - p1 + p2)
                p1 -= f(i-k//2+1,1)
                p2 -= f(j-k//2+1,2)
 
        return ans