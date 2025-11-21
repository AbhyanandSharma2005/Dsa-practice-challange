class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        
        first = [-1] * 26
        last = [-1] * 26

        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            if first[idx] == -1:
                first[idx] = i
            last[idx] = i

        unique_palindromes = 0

        
        for i in range(26):
            if first[i] != -1 and last[i] > first[i] + 1:
                
                seen = [False] * 26
                for j in range(first[i] + 1, last[i]):
                    seen[ord(s[j]) - ord('a')] = True
                unique_palindromes += sum(seen)

        return unique_palindromes
