class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        last_a = last_b = last_c = -1
        result = 0
        for i, char in enumerate(s):
            if char == 'a':
                last_a = i
            elif char == 'b':
                last_b = i
            else:
                last_c = i
            if last_a != -1 and last_b != -1 and last_c != -1:
                min_last = min(last_a, last_b, last_c)
                result += min_last + 1
        return result