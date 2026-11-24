import math


class Solution:
    def maxLength(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0
        max_prod = math.lcm(*range(1, 11)) * 10

        for i in range(n):
            prod = 1
            cur_lcm = 1
            cur_gcd = 0
            for j in range(i, n):
                prod *= nums[j]
                if prod > max_prod:
                    break
                cur_lcm = math.lcm(cur_lcm, nums[j])
                cur_gcd = math.gcd(cur_gcd, nums[j])
                if prod == cur_lcm * cur_gcd:
                    ans = max(ans, j - i + 1)

        return ans
