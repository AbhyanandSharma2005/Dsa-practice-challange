class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in range(1, 61):
            t = num1 - k * num2
            if t < k:
                if num2 >= 0:
                    return -1
                continue
            if t >= 0 and t.bit_count() <= k:
                return k
        return -1
