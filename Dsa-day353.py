class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        ones = s.count('1')
        if ones == n:
            return n
        one_blocks = []
        i = 0
        while i < n:
            if s[i] == '1':
                j = i
                while j < n and s[j] == '1':
                    j += 1
                left_zero = (i == 0 or s[i - 1] == '0')
                right_zero = (j == n or s[j] == '0')
                if left_zero and right_zero:
                    one_blocks.append((i, j - 1))
                i = j
            else:
                i += 1
        if not one_blocks:
            return ones
        best = ones
        for l, r in one_blocks:
            left_zeros = 0
            left_idx = l - 1
            while left_idx >= 0 and s[left_idx] == '0':
                left_zeros += 1
                left_idx -= 1
            right_zeros = 0
            right_idx = r + 1
            while right_idx < n and s[right_idx] == '0':
                right_zeros += 1
                right_idx += 1
            if left_zeros > 0 and right_zeros > 0:
                best = max(best, ones + left_zeros + right_zeros)
        return min(best, n)