class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        def minBitwise(n):
            if n == 2:
                return -1
            i = 1
            while (i << 1) & n:
                i <<= 1
            return n ^ i
            
        return [minBitwise(n) for n in nums]        