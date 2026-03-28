class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        word = [''] * n
        c = 0
        for i in range(n):
            if word[i] == '':
                if c >= 26:
                    return ''
                word[i] = chr(ord('a') + c)
                c += 1
            for j in range(i + 1, n):
                if lcp[i][j] > 0:
                    if word[j] == '':
                        word[j] = word[i]
                    elif word[j] != word[i]:
                        return ''
        
        for i in range(n):
            for j in range(n):
                if i == n - 1 or j == n - 1:
                    expected = 1 if word[i] == word[j] else 0
                else:
                    expected = lcp[i+1][j+1] + 1 if word[i] == word[j] else 0
                if lcp[i][j] != expected:
                    return ''
        
        return ''.join(word)