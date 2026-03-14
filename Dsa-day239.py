class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.count = 0 
        self.ans = ""   
        
        def dfs(cur: str):
            if len(cur) == n:
                self.count += 1
                if self.count == k:
                    self.ans = cur
                return
            
            for c in "abc":
                if not cur or cur[-1] != c:
                    dfs(cur + c)
                    if self.ans:
                        return
        
        dfs("")
        return self.ans
