class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def max_consecutive(bars: List[int]) -> int:
            if not bars:
                return 1
            bars.sort()
            max_len = 1
            curr = 1
            for i in range(1, len(bars)):
                if bars[i] == bars[i - 1] + 1:
                    curr += 1
                    max_len = max(max_len, curr)
                else:
                    curr = 1
            return max_len
        
        side = min(max_consecutive(hBars), max_consecutive(vBars)) + 1
        return side * side