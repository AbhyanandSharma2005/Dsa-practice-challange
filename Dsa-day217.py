class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        count = 0
        i = 0
        specials = []
        start = 0
        for j, c in enumerate(s):
            count += 1 if c == '1' else -1
            if count == 0:
                specials.append('1' + self.makeLargestSpecial(s[start+1:j]) + '0')
                start = j + 1
        specials.sort(reverse=True)
        return ''.join(specials)