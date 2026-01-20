class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        return [int(bin(v).replace('b','',1)[::-1].replace('10','00',1)[::-1],2)or -1 for v in nums]