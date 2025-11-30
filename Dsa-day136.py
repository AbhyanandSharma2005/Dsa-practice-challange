class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        total = sum(nums)
        rem = total % p
        if rem == 0:
            return 0
        
        last = {0: -1}
        pref = 0
        ans = n
        
        for i, x in enumerate(nums):
            pref = (pref + x) % p
            target = (pref - rem + p) % p
            if target in last:
                ans = min(ans, i - last[target])
            last[pref] = i
        
        return ans if ans < n else -1