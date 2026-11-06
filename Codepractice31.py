from collections import defaultdict


class Solution:

    def countServers(
        self, n: int, logs: list[list[int]], x: int, queries: list[int]
    ) -> list[int]:
        # Sort logs by timestamp
        logs.sort(key=lambda item: item[1])

        # Store original indices of queries to restore order later
        m = len(queries)
        sorted_queries = sorted(enumerate(queries), key=lambda item: item[1])

        ans = [0] * m
        window_counts = defaultdict(int)
        active_servers = 0

        left = 0
        right = 0
        num_logs = len(logs)

        for orig_idx, q_time in sorted_queries:
            # Expand right boundary of the window to include logs <= q_time
            while right < num_logs and logs[right][1] <= q_time:
                server_id = logs[right][0]
                if window_counts[server_id] == 0:
                    active_servers += 1
                window_counts[server_id] += 1
                right += 1

            # Shrink left boundary of the window to exclude logs < q_time - x
            while left < num_logs and logs[left][1] < q_time - x:
                server_id = logs[left][0]
                window_counts[server_id] -= 1
                if window_counts[server_id] == 0:
                    active_servers -= 1
                left += 1

            # Total servers minus active servers = zero request servers
            ans[orig_idx] = n - active_servers

        return ans
