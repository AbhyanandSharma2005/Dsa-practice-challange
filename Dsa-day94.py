class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        from collections import deque
        seen = set()
        q = deque([s])
        ans = s
        while q:
            curr = q.popleft()
            if curr in seen:
                continue
            seen.add(curr)
            ans = min(ans, curr)
            arr = list(curr)
            for i in range(1, len(arr), 2):
                arr[i] = str((int(arr[i]) + a) % 10)
            added = ''.join(arr)
            rotated = curr[-b:] + curr[:-b]
            if added not in seen:
                q.append(added)
            if rotated not in seen:
                q.append(rotated)
        return ans
