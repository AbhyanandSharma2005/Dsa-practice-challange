class Solution:
    def maxProduct(self, n: int) -> int:
        digits = sorted(int(c) for c in str(n))
        return digits[-1] * digits[-2]