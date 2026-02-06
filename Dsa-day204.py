class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        
        max_keep = 1
        
        for i in range(n):
            min_val = nums[i]
            max_allowed = min_val * k
            
            left, right = i, n - 1
            valid_right = i
            
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] <= max_allowed:
                    valid_right = mid
                    left = mid + 1
                else:
                    right = mid - 1
            
            max_keep = max(max_keep, valid_right - i + 1)
        
        return n - max_keep