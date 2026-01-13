class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        total = sum(l * l for _, _, l in squares)
        half = total / 2
        max_y = max(y + l for _, y, l in squares)

        def area_below(h: float) -> float:
            res = 0.0
            for _, y, l in squares:
                if h <= y:
                    continue
                height = min(h - y, l)
                res += height * l
            return res

        lo, hi = 0.0, float(max_y)
        for _ in range(100):
            mid = (lo + hi) / 2
            if area_below(mid) < half:
                lo = mid
            else:
                hi = mid
        return lo