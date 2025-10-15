class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        
        L = [1] * n
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                L[i] = L[i-1] + 1
        
        def canFind(k: int) -> bool:
            if 2 * k > n:
                return False
            
            for a in range(n - 2 * k + 1):
                end1 = a + k - 1
                end2 = a + 2 * k - 1
                
                if L[end1] >= k and L[end2] >= k:
                    return True
            
            return False

        low = 1
        high = n // 2
        max_k = 0
        
        while low <= high:
            mid = low + (high - low) // 2
            
            if canFind(mid):
                max_k = mid
                low = mid + 1
            else:
                high = mid - 1
                
        return max_k