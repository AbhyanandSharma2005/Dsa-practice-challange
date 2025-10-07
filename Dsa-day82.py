import bisect

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        ans = [-1] * n
        full = {}
        dry_days = []
        for i, lake in enumerate(rains):
            if lake == 0:
                bisect.insort(dry_days, i)
                ans[i] = 1
            else:
                if lake in full:
                    idx = bisect.bisect_right(dry_days, full[lake])
                    if idx == len(dry_days):
                        return []
                    dry_day = dry_days.pop(idx)
                    ans[dry_day] = lake
                full[lake] = i
        return ans
