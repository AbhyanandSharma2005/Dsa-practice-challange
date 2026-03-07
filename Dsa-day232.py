class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        t = s + s

        diff1 = diff2 = 0
        left = 0
        res = float('inf')

        for right in range(2 * n):

            expected1 = '0' if right % 2 == 0 else '1'
            expected2 = '1' if right % 2 == 0 else '0'

            if t[right] != expected1:
                diff1 += 1
            if t[right] != expected2:
                diff2 += 1

            if right - left + 1 > n:
                left_expected1 = '0' if left % 2 == 0 else '1'
                left_expected2 = '1' if left % 2 == 0 else '0'

                if t[left] != left_expected1:
                    diff1 -= 1
                if t[left] != left_expected2:
                    diff2 -= 1

                left += 1

            if right - left + 1 == n:
                res = min(res, diff1, diff2)

        return res