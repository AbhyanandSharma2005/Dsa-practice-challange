class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        if ((n + 1) & n) == 0:
            return 0
        r = 1
        while True:
            if (2**r - 1) > n:
                break
            r += 1
        return 2**r - 1 - n