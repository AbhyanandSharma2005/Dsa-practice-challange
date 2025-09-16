import math

class Solution:
    def replaceNonCoprimes(self, nums: list[int]) -> list[int]:
        result = []
        for num in nums:
            while result and math.gcd(num, result[-1]) > 1:
                last_num = result.pop()
                num = (num * last_num) // math.gcd(num, last_num)
            result.append(num)
        return result