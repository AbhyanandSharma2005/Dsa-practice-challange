class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        
        for p in range(1, n - 2):
            for q in range(p + 1, n - 1):
                valid = True
                
                for i in range(p):
                    if nums[i] >= nums[i + 1]:
                        valid = False
                        break
                
                if valid:
                    for i in range(p, q):
                        if nums[i] <= nums[i + 1]:
                            valid = False
                            break
                
                if valid:
                    for i in range(q, n - 1):
                        if nums[i] >= nums[i + 1]:
                            valid = False
                            break
                
                if valid:
                    return True
        
        return False