class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        ans = 0
        p1 = p2 = -1
        for l, r in intervals:
            if l > p2:
                ans += 2
                p1 = r - 1
                p2 = r
            elif l > p1:
                ans += 1
                p1 = p2
                p2 = r
            elif r < p2:
                p1 = max(l, p1)
                p2 = r
        return ans