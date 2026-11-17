class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = float('inf')

        cost = [[0] * n for _ in range(n)]

        # Precompute the minimum cost for every substring.
        for start in range(n):
            for end in range(start + 1, n):
                length = end - start + 1
                best = length

                for d in range(1, length):
                    if length % d != 0:
                        continue

                    changes = 0

                    for offset in range(d):
                        group_length = (length - 1 - offset) // d + 1

                        for pair in range(group_length // 2):
                            left = start + offset + pair * d
                            right = start + offset + (group_length - 1 - pair) * d

                            if s[left] != s[right]:
                                changes += 1

                    best = min(best, changes)

                cost[start][end] = best

        # DP: dp[p][i] = minimum cost to partition s[:i] into p parts.
        dp = [[INF] * (n + 1) for _ in range(k + 1)]
        dp[0][0] = 0

        for parts in range(1, k + 1):
            for end in range(2 * parts, n + 1):
                for start in range(2 * (parts - 1), end - 1):
                    if dp[parts - 1][start] == INF:
                        continue

                    dp[parts][end] = min(
                        dp[parts][end],
                        dp[parts - 1][start] + cost[start][end - 1]
                    )

        return dp[k][n]