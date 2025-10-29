class Solution:
    def smallestNumber(self, n: int) -> int:
        bits = 0
        while (1 << bits) - 1 < n:
            bits += 1
        return (1 << bits) - 1
