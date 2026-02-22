class Solution:
    def binaryGap(self, n: int) -> int:
        last = -1
        max_gap = 0
        pos = 0
        while n > 0:
            if n & 1:
                if last != -1:
                    max_gap = max(max_gap, pos - last)
                last = pos
            pos += 1
            n >>= 1
        return max_gap