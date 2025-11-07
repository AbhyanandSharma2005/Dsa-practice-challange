class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        power = [0] * n
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stations[i]
        for i in range(n):
            left = max(0, i - r)
            right = min(n - 1, i + r)
            power[i] = prefix[right + 1] - prefix[left]
        
        def can(mid):
            added = [0] * (n + 1)
            total_add = 0
            used = 0
            for i in range(n):
                total_add += added[i]
                if power[i] + total_add < mid:
                    need = mid - (power[i] + total_add)
                    if used + need > k:
                        return False
                    used += need
                    total_add += need
                    if i + 2 * r + 1 < n:
                        added[i + 2 * r + 1] -= need
            return True
        
        left, right = 0, sum(stations) + k
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if can(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
