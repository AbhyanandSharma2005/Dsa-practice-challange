class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        v = sorted([c for c in s if c in vowels])
        res = []
        j = 0
        for c in s:
            if c in vowels:
                res.append(v[j])
                j += 1
            else:
                res.append(c)
        return ''.join(res)
