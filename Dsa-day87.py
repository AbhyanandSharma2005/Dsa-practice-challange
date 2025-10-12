MOD = 10**9+7
def modexp(a,e):
    r=1
    a%=MOD
    while e:
        if e&1: r=r*a%MOD
        a=a*a%MOD
        e>>=1
    return r

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)
        fact=[1]*(m+1)
        for i in range(1,m+1): fact[i]=fact[i-1]*i%MOD
        ifact=[1]*(m+1)
        ifact[m]=modexp(fact[m], MOD-2)
        for i in range(m,0,-1): ifact[i-1]=ifact[i]*i%MOD
        powv = [[0]*(m+1) for _ in range(n)]
        for i in range(n):
            powv[i][0]=1
            for c in range(1,m+1):
                powv[i][c]=powv[i][c-1]*nums[i]%MOD
        dp = [[[0]*(m+1) for _ in range(m+1)] for __ in range(m+1)]
        dp[0][0][0]=1
        for pos in range(n):
            ndp = [[[0]*(m+1) for _ in range(m+1)] for __ in range(m+1)]
            for used in range(m+1):
                for carry in range(m+1):
                    for ones in range(m+1):
                        cur = dp[used][carry][ones]
                        if cur==0: continue
                        maxc = m-used
                        for c in range(maxc+1):
                            newused = used + c
                            total = carry + c
                            bit = total & 1
                            newones = ones + bit
                            newcarry = total >> 1
                            add = cur * powv[pos][c] % MOD * ifact[c] % MOD
                            ndp[newused][newcarry][newones] = (ndp[newused][newcarry][newones] + add) % MOD
            dp = ndp
        ans = 0
        for carry in range(m+1):
            more = bin(carry).count("1")
            for ones in range(m+1):
                if ones + more == k:
                    ans = (ans + dp[m][carry][ones])%MOD
        ans = ans * fact[m] % MOD
        return ans
