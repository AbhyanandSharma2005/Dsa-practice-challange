from itertools import permutations
from typing import List

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        nums = set()
        for mask in range(1, 1 << 9):
            digits_list = []
            total_len = 0
            for i in range(9):
                if mask & (1 << i):
                    d = i + 1
                    total_len += d
                    digits_list.extend([str(d)] * d)
            if total_len == 0 or total_len > 7:
                continue

            for perm in set(permutations(digits_list)):
                num = int(''.join(perm))
                nums.add(num)

        candidates = sorted(nums)
        for val in candidates:
            if val > n:
                return val

        return -1
