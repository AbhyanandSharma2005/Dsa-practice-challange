from collections import Counter
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        count = Counter(nums)
        ans = 0
        
        if 1 in count:
            ans = count[1] if count[1] % 2 != 0 else count[1] - 1
            
        for x in count:
            if x == 1:
                continue
            
            curr_len = 0
            curr = x
            while curr in count and count[curr] >= 2:
                curr_len += 2
                curr = curr * curr
                
            if curr in count and count[curr] >= 1:
                curr_len += 1
            else:
                curr_len -= 1
                
            ans = max(ans, curr_len)
            
        return ans