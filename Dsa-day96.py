class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        counts = [0] * ((max(nums) + 1) + k)
        for num in nums:
            counts[num] += 1
        pre = [counts[0]]
        for i in range(1, len(counts)):
            pre.append(pre[-1] + counts[i])
        res = 0
        for i in range(len(counts) - k):
            left = max(0, i - k - 1)
            right = min(i + k, len(pre) - 1)
            mid = counts[i]
            candidate = pre[right] - pre[left] - mid
            res = max(res, mid + min(numOperations, candidate))
        return res
