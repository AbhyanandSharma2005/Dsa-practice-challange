from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        MOD = 10**9 + 7
        
        p10 = [1] * (n + 1)
        for i in range(1, n + 1):
            p10[i] = (p10[i - 1] * 10) % MOD
            
        pref_cnt = [0] * (n + 1)
        pref_sum = [0] * (n + 1)
        pref_val = [0] * (n + 1)
        
        for i in range(n):
            pref_cnt[i + 1] = pref_cnt[i]
            pref_sum[i + 1] = pref_sum[i]
            pref_val[i + 1] = pref_val[i]
            
            if s[i] != '0':
                d = int(s[i])
                pref_cnt[i + 1] += 1
                pref_sum[i + 1] += d
                pref_val[i + 1] = (pref_val[i] * 10 + d) % MOD
                
        ans = []
        for L, R in queries:
            total_sum = pref_sum[R + 1] - pref_sum[L]
            non_zeros = pref_cnt[R + 1] - pref_cnt[L]
            
            if non_zeros == 0:
                ans.append(0)
                continue
                
            val_R = pref_val[R + 1]
            val_L = pref_val[L]
            x = (val_R - (val_L * p10[non_zeros]) % MOD + MOD) % MOD
            
            ans.append((x * total_sum) % MOD)
            
        return ans