class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        return next(i for i in range(n, 101) if (lambda x: prod(map(int, str(x))))(i) % t == 0)