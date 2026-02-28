class Solution:
    MOD = 1000000007
    def concatenatedBinary(self, n: int) -> int:
        ans=[]
        for i in range(1,n+1):
            ans+=bin(i)[2:]
        ans= int(("".join(ans)),2)
        return ans%self.MOD

        

        