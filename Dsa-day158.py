class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n,l = len(strs),len(strs[0])
        dp = [1]*l

        for i in range(l):
            for j in range(i) :
                is_comp = True

                for k in range(n) :
                    if strs[k][i] < strs[k][j] :
                        is_comp = False
                        break

                if is_comp :
                    dp[i] = max(dp[i], 1+dp[j])

        return l-max(dp)