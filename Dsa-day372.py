class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        temp = t
        r2, r3, r5, r7 = 0, 0, 0, 0
        
        while temp % 2 == 0:
            r2 += 1
            temp //= 2
        while temp % 3 == 0:
            r3 += 1
            temp //= 3
        while temp % 5 == 0:
            r5 += 1
            temp //= 5
        while temp % 7 == 0:
            r7 += 1
            temp //= 7
            
        # If t has prime factors other than 2, 3, 5, or 7, it's impossible.
        if temp > 1:
            return "-1"
            
        n = len(num)
        f2 = [0, 0, 1, 0, 2, 0, 1, 0, 3, 0]
        f3 = [0, 0, 0, 1, 0, 0, 1, 0, 0, 2]
        f5 = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0]
        f7 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
        
        pref2 = [0] * (n + 1)
        pref3 = [0] * (n + 1)
        pref5 = [0] * (n + 1)
        pref7 = [0] * (n + 1)
        
        has_zero = False
        first_zero = -1
        
        for i, ch in enumerate(num):
            d = int(ch)
            if d == 0:
                has_zero = True
                if first_zero == -1:
                    first_zero = i
            
            pref2[i + 1] = pref2[i] + f2[d]
            pref3[i + 1] = pref3[i] + f3[d]
            pref5[i + 1] = pref5[i] + f5[d]
            pref7[i + 1] = pref7[i] + f7[d]
            
        # Already zero-free and completely divisible -> No increment required
        if not has_zero and pref2[n] >= r2 and pref3[n] >= r3 and pref5[n] >= r5 and pref7[n] >= r7:
            return num
            
        max_r2, max_r3 = 50, 30
        inf_str = "9" * 100
        dp = [[inf_str] * (max_r3 + 1) for _ in range(max_r2 + 1)]
        dp[0][0] = ""
        digits_to_try = ['2', '3', '4', '6', '8', '9']
        
        for i in range(max_r2 + 1):
            for j in range(max_r3 + 1):
                if i == 0 and j == 0:
                    continue
                best = inf_str
                for d_char in digits_to_try:
                    d_val = int(d_char)
                    ni = max(0, i - f2[d_val])
                    nj = max(0, j - f3[d_val])
                    
                    if len(dp[ni][nj]) < 100:
                        cand = "".join(sorted(dp[ni][nj] + d_char))
                        if len(cand) < len(best) or (len(cand) == len(best) and cand < best):
                            best = cand
                dp[i][j] = best
                
        start_i = n - 1 if first_zero == -1 else first_zero
        
        # Try modifying bounded from the back to maintain the maximum possible prefix
        for i in range(start_i, -1, -1):
            orig_d = int(num[i])
            start_d = orig_d + 1
            
            for d in range(start_d, 10):
                rem2 = max(0, r2 - pref2[i] - f2[d])
                rem3 = max(0, r3 - pref3[i] - f3[d])
                rem5 = max(0, r5 - pref5[i] - f5[d])
                rem7 = max(0, r7 - pref7[i] - f7[d])
                
                dp_str = dp[rem2][rem3]
                S = rem5 + rem7 + len(dp_str)
                K = n - 1 - i
                
                if S <= K:
                    ones = K - S
                    rest = ("5" * rem5) + ("7" * rem7) + dp_str
                    rest_sorted = "".join(sorted(rest))
                    
                    return num[:i] + str(d) + ("1" * ones) + rest_sorted
                    
        # Out of Bounds Handling Fallback: Must natively compile by primes into a longer sequence
        dp_str = dp[r2][r3]
        S_full = r5 + r7 + len(dp_str)
        L = max(n + 1, S_full)
        
        ones = L - S_full
        rest = ("5" * r5) + ("7" * r7) + dp_str
        rest_sorted = "".join(sorted(rest))
        
        return ("1" * ones) + rest_sorted