class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        freq = Counter(x % value for x in nums)
        i = 0
        while True:
            if freq[i % value] == 0:
                return i
            freq[i % value] -= 1
            i += 1
