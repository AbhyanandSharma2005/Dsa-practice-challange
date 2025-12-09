class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        from collections import Counter
        MOD = 10**9 + 7
        left = Counter()
        right = Counter(nums)
        ans = 0
        for x in nums:
            right[x] -= 1
            target = x * 2
            ans = (ans + left[target] * right[target]) % MOD
            left[x] += 1
        return ans