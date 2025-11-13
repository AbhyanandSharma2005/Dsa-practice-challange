class Solution:
    def maxOperations(self, s: str) -> int:
        count = 0
        oneC = 0
        for i in range(len(s) - 1):
            if s[i] == '1':
                oneC += 1
            if s[i] == '1' and s[i + 1] == '0':
                count += oneC
        return count
