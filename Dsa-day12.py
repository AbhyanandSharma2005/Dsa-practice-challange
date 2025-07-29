from typing import List

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        last = [-1] * 32  

        for i in range(n - 1, -1, -1):
            for b in range(32):
                if (nums[i] >> b) & 1:
                    last[b] = i

            max_reach = i
            for b in range(32):
                if last[b] != -1:
                    max_reach = max(max_reach, last[b])

            res[i] = max_reach - i + 1

        return res
