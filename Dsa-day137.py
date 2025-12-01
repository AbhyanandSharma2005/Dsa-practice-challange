class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        total = sum(batteries)
        batteries.sort()
        
        while batteries and batteries[-1] > total // n:
            total -= batteries.pop()
            n -= 1
        return total // n