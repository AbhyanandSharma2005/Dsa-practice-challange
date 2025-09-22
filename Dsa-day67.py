class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = {}
        max_freq = 0
        total = 0
        for n in nums:
            freq[n] = freq.get(n, 0) + 1
            if freq[n] > max_freq:
                max_freq = freq[n]
        for n in nums:
            if freq[n] == max_freq:
                total += 1
        return total
