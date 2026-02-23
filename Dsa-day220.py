class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        allCodes = set()
        n = len(s)
        for i in range(n):
                if i + k <= n: 
                    allCodes.add(s[i:i + k])
        return 2 ** k == len(allCodes)